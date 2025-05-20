//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: active
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    printf("Starting CPU usage monitor...\n");

    // Wait for a second
    sleep(1);

    // Get the initial CPU time
    long idleStart, userStart, systemStart;
    FILE* statFile = fopen("/proc/stat", "r");
    fscanf(statFile, "cpu %ld %ld %ld", &userStart, &systemStart, &idleStart);
    fclose(statFile);

    // Wait for another second
    sleep(1);

    printf("Monitoring...\n");
    fprintf(stderr, "CPU usage percentage: ");

    // Loop forever
    while (1) {

        // Wait for a second
        sleep(1);

        // Get the current CPU time
        long idleEnd, userEnd, systemEnd;
        statFile = fopen("/proc/stat", "r");
        fscanf(statFile, "cpu %ld %ld %ld", &userEnd, &systemEnd, &idleEnd);
        fclose(statFile);

        // Calculate the CPU usage percentage
        long totalStart = userStart + systemStart + idleStart;
        long totalEnd = userEnd + systemEnd + idleEnd;
        float percent = ((float) (totalEnd - totalStart) - (float) (idleEnd - idleStart)) * 100 / (float) (totalEnd - totalStart);

        // Save the current CPU time
        idleStart = idleEnd;
        userStart = userEnd;
        systemStart = systemEnd;

        // Print the CPU usage percentage
        fprintf(stderr, "%.2f%%\n", percent);

    }

    return 0;
}