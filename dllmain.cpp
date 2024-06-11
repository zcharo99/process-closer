// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include <windows.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       [[maybe_unused]] LPVOID lpReserved
                     )
{
    HANDLE hConsole;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        // handle to the current process
        HANDLE hProcess;
        hProcess = GetCurrentProcess();

        // allocate console
        AllocConsole();

        // handle to the console
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        // print closing message
        std::cout << "closing in 2 seconds" << std::endl;

        // wait 2 seconds
        Sleep(2000);

        // terminate the process with code 0 (successful close, no errors)
        TerminateProcess(hProcess, 0);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

