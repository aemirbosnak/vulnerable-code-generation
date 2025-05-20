//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to calculate CPU usage
float calculateCPU(unsigned int* preCPU, unsigned int* preIdleCPU);

int main() {

    // Variables to store previous CPU time
    unsigned int preCPU, preIdleCPU;

    // Get initial CPU time
    FILE* fStat = fopen("/proc/stat", "r");
    fscanf(fStat, "cpu %u %*u %u", &preCPU, &preIdleCPU);
    fclose(fStat);

    while(1) {

        // Sleep for 1 second
        sleep(1);

        // Get current CPU time
        unsigned int currCPU, currIdleCPU;
        fStat = fopen("/proc/stat", "r");
        fscanf(fStat, "cpu %u %*u %u", &currCPU, &currIdleCPU);
        fclose(fStat);

        // Calculate CPU usage
        float CPUUsage = calculateCPU(&preCPU, &preIdleCPU);
        preCPU = currCPU;
        preIdleCPU = currIdleCPU;

        // Print CPU usage
        printf("CPU usage: %.2f%%\n", CPUUsage);

    }

    return 0;
}

// Function to calculate CPU usage
float calculateCPU(unsigned int* preCPU, unsigned int* preIdleCPU) {

    // Get CPU and idle time difference
    unsigned int currCPU, currIdleCPU;
    currCPU = *preCPU;
    currIdleCPU = *preIdleCPU;
    FILE* fStat = fopen("/proc/stat", "r");
    fscanf(fStat, "cpu %u %*u %u", &currCPU, &currIdleCPU);
    fclose(fStat);
    unsigned int diffCPU = currCPU - *preCPU;
    unsigned int diffIdleCPU = currIdleCPU - *preIdleCPU;

    // Calculate CPU usage
    float CPUUsage = 100.0 * (diffCPU - diffIdleCPU) / diffCPU;

    return CPUUsage;
}