//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define REFRESH_RATE 1 // In seconds
#define BUFFER_SIZE 256

void clearConsole() {
    printf("\033c");
}

void printTitle() {
    printf("------------------------------\n");
    printf("  CPU USAGE MONITOR PROGRAM\n");
    printf("------------------------------\n\n");
}

int getCurrentCpuUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    int userTimeInMs = usage.ru_utime.tv_sec * 1000 + usage.ru_utime.tv_usec / 1000;
    int systemTimeInMs = usage.ru_stime.tv_sec * 1000 + usage.ru_stime.tv_usec / 1000;

    int totalCpuUsageInMs = userTimeInMs + systemTimeInMs;

    return totalCpuUsageInMs;
}

void printCpuUsage(int currentUsage, int previousUsage) {
    int cpuUsageInPercent = (currentUsage - previousUsage) / REFRESH_RATE / 10;
    printf("Current CPU usage: %d%%\n", cpuUsageInPercent);
}

int main() {
    clearConsole();
    printTitle();

    int currentUsage = getCurrentCpuUsage();
    int previousUsage = currentUsage;
    int buffer[BUFFER_SIZE];

    while (1) {
        if (fgets(buffer, BUFFER_SIZE, stdin)) {
            clearConsole();
            printTitle();

            currentUsage = getCurrentCpuUsage();
            printCpuUsage(currentUsage, previousUsage);
            previousUsage = currentUsage;

            sleep(REFRESH_RATE);
        }
    }

    return 0;
}