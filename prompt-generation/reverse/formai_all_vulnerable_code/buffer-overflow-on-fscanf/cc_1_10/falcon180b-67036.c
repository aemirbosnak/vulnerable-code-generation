//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to get CPU usage as a percentage
int getCPUUsage() {
    FILE *file;
    char buffer[1024];
    int total, idle, usage;

    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        printf("Error: Unable to open /proc/stat\n");
        exit(1);
    }

    fscanf(file, "cpu %d %d %d %d", &total, &idle, &usage, &idle);

    fclose(file);

    return usage;
}

// Function to print CPU usage in a formatted manner
void printCPUUsage(int usage) {
    printf("CPU usage: %.2f%%\n", usage);
}

int main() {
    int interval = 1; // Time interval in seconds for checking CPU usage
    int prevUsage = 0; // Previous CPU usage value

    while (1) {
        int currUsage = getCPUUsage();

        if (currUsage < 0) {
            printf("Error: Invalid CPU usage value\n");
            continue;
        }

        if (prevUsage == 0) {
            prevUsage = currUsage;
            continue;
        }

        int deltaUsage = currUsage - prevUsage;
        double deltaPercentage = (double)deltaUsage / prevUsage * 100.0;

        printf("CPU usage changed by %.2f%%\n", deltaPercentage);
        prevUsage = currUsage;

        sleep(interval);
    }

    return 0;
}