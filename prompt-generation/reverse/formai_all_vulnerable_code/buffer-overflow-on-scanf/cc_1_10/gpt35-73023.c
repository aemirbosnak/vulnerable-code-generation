//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>

#define ONE_KB 1024
#define MAX_SIZE 16

void printMemoryUsage(long int ramUsage) {
    if (ramUsage <= ONE_KB) {
        printf("RAM usage: %ld bytes\n", ramUsage);
    } else if (ramUsage <= ONE_KB*ONE_KB) {
        printf("RAM usage: %ldKB\n", ramUsage/ONE_KB);
    } else {
        printf("RAM usage: %ldMB\n", ramUsage/(ONE_KB*ONE_KB));
    }
}

void getRamUsageSysInfo(long int* ramUsage) {
    struct sysinfo si;
    sysinfo(&si);
    *ramUsage = (long int)si.totalram - (long int)si.freeram;
}

void getRamUsageProcStatus(long int* ramUsage) {
    FILE *procStatusFile;
    procStatusFile = fopen("/proc/meminfo", "r");
    if (!procStatusFile) {
        printf("Error opening /proc/meminfo file\n");
        exit(1);
    }
    char buffer[MAX_SIZE];
    int memTotal, memFree;
    while (fscanf(procStatusFile, "%s", buffer) == 1) {
        if (strcmp(buffer, "MemTotal:") == 0) {
            fscanf(procStatusFile, "%d", &memTotal);
        } else if (strcmp(buffer, "MemFree:") == 0) {
            fscanf(procStatusFile, "%d", &memFree);
        } else {
            fgets(buffer, MAX_SIZE, procStatusFile);
        }
    }
    fclose(procStatusFile);
    *ramUsage = (long int)memTotal - (long int)memFree;
}

void monitorCRamUsage(int mode, int duration, long int* previousUsage) {
    // Base case
    if (duration == 0) {
        return;
    }

    long int currentUsage;
    if (mode == 0) {
        getRamUsageSysInfo(&currentUsage);
    } else {
        getRamUsageProcStatus(&currentUsage);
    }

    if (*previousUsage == -1) {
        *previousUsage = currentUsage;
    } else if (currentUsage > *previousUsage) {
        printf("RAM usage increased by ");
        printMemoryUsage(currentUsage - *previousUsage);
    } else if (currentUsage == *previousUsage) {
        printf("RAM usage remained same: ");
        printMemoryUsage(currentUsage);
    } else {
        printf("RAM usage decreased by ");
        printMemoryUsage(*previousUsage - currentUsage);
    }

    // Set current usage as previous usage for next iteration
    *previousUsage = currentUsage;

    // Recursive call with decremented duration
    monitorCRamUsage(mode, duration - 1, previousUsage);
}

int main() {
    int mode, duration;
    printf("Which mode do you want to use?\n");
    printf("(0) sysinfo\t(1) /proc/meminfo\n");
    scanf("%d", &mode);

    if (mode != 0 && mode != 1) {
        printf("Invalid mode selected\n");
        exit(1);
    }

    printf("Enter duration of monitoring in seconds: ");
    scanf("%d", &duration);

    long int previousUsage = -1;
    monitorCRamUsage(mode, duration, &previousUsage);

    return 0;
}