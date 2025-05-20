//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

void displayMemoryUsage(long total, long free) {
    long used = total - free;
    double used_percentage = (double)used / total * 100;

    printf("\n------------------------------\n");
    printf("Total Memory: %ld MB\n", total / 1024);
    printf("Free Memory: %ld MB\n", free / 1024);
    printf("Used Memory: %ld MB\n", used / 1024);
    printf("Memory Usage: %.2f%%\n", used_percentage);
    printf("------------------------------\n");
}

void printTime() {
    time_t now;
    time(&now);
    printf("Current Time: %s", ctime(&now));
}

void memoryMonitor(int interval) {
    struct sysinfo memInfo;
    
    printf("Starting Memory Usage Monitor...\n");
    printf("Press Ctrl+C to stop monitoring.\n");

    while (1) {
        sysinfo(&memInfo);
        displayMemoryUsage(memInfo.totalram, memInfo.freeram);
        printTime();
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    int interval = 5; // Default interval is 5 seconds

    // Check if user provided an interval in arguments
    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            printf("Invalid interval. Must be a positive integer. Using default interval of 5 seconds.\n");
            interval = 5;
        }
    }

    printf("Memory Monitor Interval: %d seconds\n", interval);
    memoryMonitor(interval);

    return 0;
}