//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <stdbool.h>

#define REFRESH_RATE 5 /* in seconds */
#define MAX_RAM_USAGE 90 /* maximum RAM usage allowed in percentage */

void *monitorRAMUsage(void *ptr);

int main()
{
    pthread_t monitor_thread;
    int iret;

    printf("Starting C RAM Usage Monitor Program...\n");

    /* create monitor thread */
    iret = pthread_create(&monitor_thread, NULL, monitorRAMUsage, NULL);

    if (iret)
    {
        printf("Error - pthread_create() return code: %d\n", iret);
        exit(EXIT_FAILURE);
    }

    /* wait for monitor thread to finish */
    pthread_join(monitor_thread, NULL);

    return 0;
}

void *monitorRAMUsage(void *ptr)
{
    struct sysinfo sys_info;
    bool aboveThreshold = false;

    while (true)
    {
        /* get system info */
        if (sysinfo(&sys_info) != 0)
        {
            fprintf(stderr, "Failed to get system info.\n");
            exit(EXIT_FAILURE);
        }

        /* calculate RAM usage */
        unsigned long long totalRAM = sys_info.totalram;
        unsigned long long freeRAM = sys_info.freeram;
        unsigned long long usedRAM = totalRAM - freeRAM;
        double RAMUsagePercentage = ((double)usedRAM / (double)totalRAM) * 100.0;

        /* check if RAM usage above threshold */
        if (RAMUsagePercentage >= MAX_RAM_USAGE)
        {
            aboveThreshold = true;
            printf("RAM usage is above threshold: %.2lf%%\n", RAMUsagePercentage);
        }
        else
        {
            aboveThreshold = false;
        }

        /* wait for next refresh */
        sleep(REFRESH_RATE);
    }

    /* exit thread */
    pthread_exit(NULL);
}