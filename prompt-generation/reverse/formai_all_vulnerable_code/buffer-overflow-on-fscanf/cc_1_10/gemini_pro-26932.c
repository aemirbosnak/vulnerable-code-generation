//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

// Time Warp Constants
#define SLOWTIME 6000000      // 6 seconds
#define FASTTIME 600000      // 600 milliseconds

// CPU Utilization Calculations
unsigned long long lastTotalUser, lastTotalUserLow, totalUser, totalUserLow;
unsigned long long lastTotalSystem, lastTotalSystemLow, totalSystem, totalSystemLow;
unsigned long long totalIdle, totalIdleLow, lastTotalIdle, lastTotalIdleLow;
double cpuPercentage;

// Time Warp Functions
void warpToSlowTime() {
    usleep(SLOWTIME);
}

void warpToFastTime() {
    usleep(FASTTIME);
}

// CPU Utilization Functions
void getCPUUtilization() {
    FILE* file = fopen("/proc/stat", "r");
    fscanf(file, "cpu %llu %llu %llu %llu", &totalUser, &totalUserLow, &totalSystem, &totalSystemLow);
    fclose(file);
}

double calculateCPUPercentage() {
    totalIdle = totalIdleLow + totalIdle;
    totalUser = totalUserLow + totalUser;
    totalSystem = totalSystemLow + totalSystem;

    double total = totalUser + totalSystem + totalIdle;
    return (totalUser + totalSystem) * 100.0 / total;
}

int main() {
    // Initialize Time Warp
    srand(time(NULL));

    // Initialize CPU Utilization
    getCPUUtilization();
    lastTotalUser = totalUser;
    lastTotalUserLow = totalUserLow;
    lastTotalSystem = totalSystem;
    lastTotalSystemLow = totalSystemLow;
    lastTotalIdle = totalIdle;
    lastTotalIdleLow = totalIdleLow;

    while (1) {
        // Time Warp
        if (rand() % 2) {
            warpToSlowTime();
        } else {
            warpToFastTime();
        }

        // Calculate CPU Utilization
        getCPUUtilization();
        cpuPercentage = calculateCPUPercentage();

        // Display CPU Utilization
        printf("CPU Usage: %.2f%%\n", cpuPercentage);

        // Update Last Values
        lastTotalUser = totalUser;
        lastTotalUserLow = totalUserLow;
        lastTotalSystem = totalSystem;
        lastTotalSystemLow = totalSystemLow;
        lastTotalIdle = totalIdle;
        lastTotalIdleLow = totalIdleLow;
    }

    return 0;
}