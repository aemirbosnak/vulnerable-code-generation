//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define INTERVAL 1 // in seconds
#define MAX_COMMAND_LENGTH 1024

int main()
{
    char command[MAX_COMMAND_LENGTH];
    struct timeval tv;
    struct rusage r_usage;
    int cpuUsage, prevCpuUsage = 0;
    FILE* fp;

    while(1) {
        sprintf(command, "ps -p %d -o %%cpu | awk '{sum+=$1} END {print sum}'", getpid());

        fp = popen(command, "r");
        if(fp == NULL) {
            fprintf(stderr, "Error: Could not execute command.");
            exit(1);
        }

        if(fscanf(fp, "%d", &cpuUsage) == -1) {
            fprintf(stderr, "Error: Could not read CPU usage.");
            exit(1);
        }

        // Calculate total CPU usage by this process
        gettimeofday(&tv, NULL);
        getrusage(RUSAGE_SELF, &r_usage);
        int totalCpuUsage = r_usage.ru_utime.tv_sec + r_usage.ru_stime.tv_sec;

        // Print the CPU usage statistics
        printf("\n--- Statistics ---\n");
        printf("CPU usage: %d%%\n", cpuUsage - prevCpuUsage);
        printf("Total CPU usage: %ds %dus\n", totalCpuUsage, r_usage.ru_utime.tv_usec + r_usage.ru_stime.tv_usec);
        printf("------------------\n");

        prevCpuUsage = cpuUsage;
        pclose(fp);

	// Sleep for INTERVAL seconds before checking again
        sleep(INTERVAL);
    }

    return 0;
}