//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

// Function prototypes
void displayCpuUsage();
double getCpuUsage();

// Main function
int main() {
    printf("Welcome to the Thrilling CPU Usage Monitor!\n");
    printf("------------------------------------------------\n");
    
    while (1) {
        displayCpuUsage();
        sleep(1); // Refresh every second
    }

    return 0;
}

// Function to display CPU usage
void displayCpuUsage() {
    double cpuUsage = getCpuUsage();
    
    printf("\rCurrent CPU Usage: %.2f%% ", cpuUsage);
    fflush(stdout);
}

// Function to get CPU usage
double getCpuUsage() {
    FILE* file;
    long userTime, niceTime, systemTime, idleTime, iowaitTime, irqTime, softIrqTime, stealTime, totalTime;

    // Open 'proc/stat' to read CPU statistics
    file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Error opening /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read CPU usage values
    fscanf(file, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld",
        &userTime, &niceTime, &systemTime, &idleTime,
        &iowaitTime, &irqTime, &softIrqTime, &stealTime);

    fclose(file);

    // Calculate total CPU time and idle time
    totalTime = userTime + niceTime + systemTime + idleTime + iowaitTime + irqTime + softIrqTime + stealTime;
    long activeTime = totalTime - idleTime; // Active CPU time calculation

    static long prevTotalTime = 0;
    static long prevActiveTime = 0;

    // Calculate CPU percentage
    double cpuUsage = 0.0;
    
    if (prevTotalTime != 0) {
        cpuUsage = (double)(activeTime - prevActiveTime) / (totalTime - prevTotalTime) * 100.0; 
    }

    // Update previous total and active times
    prevTotalTime = totalTime;
    prevActiveTime = activeTime;

    return cpuUsage;
}