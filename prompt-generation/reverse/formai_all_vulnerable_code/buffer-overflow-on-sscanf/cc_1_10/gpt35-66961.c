//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void displayHeader()
{
    printf("+--------------------------------------------------------+\n");
    printf("|              MEDIEVAL CPU USAGE MONITOR                |\n");
    printf("+--------------------------------------------------------+\n");
    printf("|       |       Load       |       Memory      |         |\n");
    printf("|  Time |   Avg   |   Max   |      Used      |   Swap   |\n");
    printf("+-------|---------|---------|----------------|---------+\n");
}

int main()
{
    FILE* pFile;
    long lIdleTime = 0, lOldIdleTime = 0, lTotalTime = 0, lOldTotalTime = 0;
    int nCpuNum = 0, nLine = 0, nSeconds;
    double dIdleTime, dTotalTime, dCpuUsage, dAvgCpuUsage = 0, dMaxCpuUsage = 0;
    char acBuff[1024], acCpuName[64];

    pFile = fopen("/proc/stat", "r");

    if (pFile == NULL)
    {
        printf("Error opening /proc/stat file\n");
        exit(EXIT_FAILURE);
    }

    displayHeader();

    while (1)
    {
        lOldIdleTime = lIdleTime;
        lOldTotalTime = lTotalTime;

        rewind(pFile);

        while (fgets(acBuff, sizeof(acBuff), pFile))
        {
            nLine++;

            if (nLine == 1)
            {
                sscanf(acBuff, "%s %lu %lu %lu %lu %lu %lu %lu", acCpuName, &lTotalTime, &nCpuNum, &lIdleTime, &nCpuNum, &nCpuNum, &nCpuNum, &nCpuNum);
            }
            else
            {
                sscanf(acBuff, "%s %lu %lu %lu %lu %lu %lu %lu", acCpuName, &nCpuNum, &nCpuNum, &nCpuNum, &nCpuNum, &nCpuNum, &nCpuNum, &nCpuNum);
            }
        }

        dIdleTime = (double)(lIdleTime - lOldIdleTime);
        dTotalTime = (double)(lTotalTime - lOldTotalTime);
        dCpuUsage = 100.0 * (1.0 - dIdleTime / dTotalTime);

        if (dCpuUsage > dMaxCpuUsage)
            dMaxCpuUsage = dCpuUsage;

        dAvgCpuUsage = ((dAvgCpuUsage * nSeconds) + dCpuUsage) / (nSeconds + 1);
        nSeconds++;

        printf("| %02d:%02d  | %6.2lf%% | %6.2lf%% | ", (int)(time(NULL) / 60) % 60, (int)time(NULL) % 60, dAvgCpuUsage, dMaxCpuUsage);

        FILE *fp = fopen("/proc/meminfo", "r");
        unsigned long long total_memory, free_memory, used_memory;
        char buffer[256];

        if(fp)
        {
            fgets(buffer, 256, fp);
            sscanf(buffer, "MemTotal: %llu kB", &total_memory);
            fgets(buffer, 256, fp);
            sscanf(buffer, "MemFree: %llu kB", &free_memory);

            used_memory = total_memory - free_memory;
        }

        printf("%10lld kB |", used_memory);

        if(fp)
        {
            fgets(buffer, 256, fp);
            sscanf(buffer, "SwapTotal: %llu kB", &total_memory);
            fgets(buffer, 256, fp);
            sscanf(buffer, "SwapFree: %llu kB", &free_memory);

            used_memory = total_memory - free_memory;
        }

        printf(" %8lld kB  |\n", used_memory);

        fclose(fp);
        sleep(1);
    }

    return 0;
}