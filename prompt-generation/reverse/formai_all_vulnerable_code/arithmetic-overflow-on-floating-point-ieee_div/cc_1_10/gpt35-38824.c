//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: satisfied
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    // Define variables
    char fName[40], line[100];
    FILE* fp;
    float idleTime, totalTime, cpuUsage;
    long int idleOld, idleNew, cpuTotalOld, cpuTotalNew;

    // Define initial values
    idleOld = 0;
    cpuTotalOld = 0;

    // Get CPU information from /proc/stat file
    while(1) {
        // Open /proc/stat file
        fp = fopen("/proc/stat","r");
        if(fp == NULL) {
            printf("Error: /proc/stat file not found\n");
            exit(1);
        }

        // Read first line of the file
        fgets(line, sizeof(line), fp);

        // Close the file
        fclose(fp);

        // Extract CPU idle and total time from the read line
        sscanf(line, "%*s %ld %ld %ld %ld %ld %ld %ld", &cpuTotalNew, &cpuTotalNew, &cpuTotalNew, 
            &cpuTotalNew, &cpuTotalNew, &cpuTotalNew, &idleNew);

        // Calculate total and idle time differences
        totalTime = (cpuTotalNew - cpuTotalOld);
        idleTime = (idleNew - idleOld);

        // Calculate CPU usage percentage
        cpuUsage = ((totalTime - idleTime) / totalTime) * 100;

        // Print CPU usage percentage
        printf("CPU Usage: %.2f%%\n", cpuUsage);

        // Save current CPU idle and total values for next iteration
        idleOld = idleNew;
        cpuTotalOld = cpuTotalNew;

        // Wait for 1 second before checking CPU usage again
        sleep(1);
    }

    return 0;
}