/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __CC_CONFIG_H_YANGWS_20100110__
#define __CC_CONFIG_H_YANGWS_20100110__

/**
@file
@brief Config of cocos2d-x project.

There are config below:
    - build for which target platform
*/

//////////////////////////////////////////////////////////////////////////
// pre configure
//////////////////////////////////////////////////////////////////////////

// define supported target platform macro which ccx uses.
#define CC_PLATFORM_UNKNOWN            0
#define CC_PLATFORM_IOS                1
#define CC_PLATFORM_MAC                2
#define CC_PLATFORM_ANDROID            3
#define CC_PLATFORM_UPHONE             4
#define CC_PLATFORM_WIN32              5

// Determine tartet platform by compile environment macro.
#define CC_TARGET_PLATFORM             CC_PLATFORM_UNKNOWN

// iphone
#if ! CC_TARGET_PLATFORM && (defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR))
    #undef  CC_TARGET_PLATFORM
    #define CC_TARGET_PLATFORM         CC_PLATFORM_IOS
    #define CC_SUPPORT_MULTITHREAD 0
    #define CC_SUPPORT_UNICODE 0
#endif

// mac
#if ! CC_TARGET_PLATFORM && defined(TARGET_OS_MAC)
    #undef  CC_TARGET_PLATFORM
    #define CC_TARGET_PLATFORM         CC_PLATFORM_MAC
#endif

// android
#if ! CC_TARGET_PLATFORM && defined(ANDROID)
    #undef  CC_TARGET_PLATFORM
    #define CC_TARGET_PLATFORM         CC_PLATFORM_ANDROID
#endif

// uphone
#if ! CC_TARGET_PLATFORM && defined(_TRANZDA_VM_)
    #undef  CC_TARGET_PLATFORM
    #define CC_TARGET_PLATFORM         CC_PLATFORM_UPHONE
#endif

// win32
#if ! CC_TARGET_PLATFORM && (defined(WIN32) && defined(_WINDOWS))
    #undef  CC_TARGET_PLATFORM
    #define CC_TARGET_PLATFORM         CC_PLATFORM_WIN32

    #define CC_SUPPORT_MULTITHREAD     1
    #if defined(UNICODE)
        #define CC_SUPPORT_UNICODE     1
    #else
        #define CC_SUPPORT_UNICODE     0
    #endif
#endif

//////////////////////////////////////////////////////////////////////////
// user configure
//////////////////////////////////////////////////////////////////////////

// Check user assigned target platform.
#if defined(CC_UNDER_IOS)
    #undef  CC_TARGET_PLATFORM
    #define CC_TARGET_PLATFORM         CC_PLATFORM_IOS
#endif

#if defined(CC_UNDER_MAC)
    #undef  CC_TARGET_PLATFORM
    #define CC_TARGET_PLATFORM         CC_PLATFORM_MAC
#endif

#if defined(CC_UNDER_ANDROID)
    #undef  CC_TARGET_PLATFORM
    #define CC_TARGET_PLATFORM         CC_PLATFORM_ANDROID
#endif

#if defined(CC_UNDER_UPHONE)
    #undef  CC_TARGET_PLATFORM
    #define CC_TARGET_PLATFORM         CC_PLATFORM_UPHONE
#endif

#if defined(CC_UNDER_WIN32)
    #undef  CC_TARGET_PLATFORM
    #define CC_TARGET_PLATFORM         CC_PLATFORM_WIN32
#endif

// Check user assigned supportive of multi-thread
#if defined(CC_ENABLE_MULTITHREAD)
    #undef  CC_SUPPORT_MULTITHREAD
    #define CC_SUPPORT_MULTITHREAD     1
#elif defined(CC_DISABLE_MULTITHREAD)
    #undef  CC_SUPPORT_MULTITHREAD
    #define CC_SUPPORT_MULTITHREAD     0
#endif

// Check user assigned supportive of unicode
#if defined(CC_ENABLE_UNICODE)
#undef  CC_SUPPORT_UNICODE
#define CC_SUPPORT_UNICODE             1
#elif defined(CC_DISABLE_UNICODE)
#undef  CC_SUPPORT_UNICODE
#define CC_SUPPORT_UNICODE             0
#endif

//////////////////////////////////////////////////////////////////////////
// post configure
//////////////////////////////////////////////////////////////////////////

// check user set platform
#if ! CC_TARGET_PLATFORM
    #error  "Can not recognize the target platform, compling under a unsupported platform?"
#endif 

// distinguish mobile platforms and pc platforms
#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    #define CC_PLATFORM_PC
#else
    #define CC_PLATFORM_MOBILE
#endif

// cocos2d-x havn't support multi-thread yet
#undef  CC_SUPPORT_MULTITHREAD
#define CC_SUPPORT_MULTITHREAD         0

// cocos2d-x havn't support unicode yet
#undef  CC_SUPPORT_UNICODE
#define CC_SUPPORT_UNICODE             0

// Check the supportive of platform
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#endif  // CC_PLATFORM_WIN32
#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#error cofnig
#endif
#endif  // __CC_CONFIG_H_YANGWS_20100110__
