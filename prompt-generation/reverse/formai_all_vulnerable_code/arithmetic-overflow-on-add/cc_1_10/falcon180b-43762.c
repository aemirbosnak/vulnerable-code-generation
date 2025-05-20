//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main() {
    char buffer[BUF_SIZE];
    FILE *fp;
    int cpu_percentage;
    int total_cpu_percentage = 0;
    int num_processes = 0;

    // Open the /proc/stat file
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    // Read the first line of the file
    fgets(buffer, BUF_SIZE, fp);

    // Parse the first line to get the number of processors
    sscanf(buffer, "cpu %d", &num_processes);

    // Loop through each processor and calculate the CPU usage percentage
    for (int i = 0; i < num_processes; i++) {
        fgets(buffer, BUF_SIZE, fp);

        // Parse the line to get the CPU usage percentage
        sscanf(buffer, "cpu%d %d", &i, &cpu_percentage);

        // Add the CPU usage percentage to the total
        total_cpu_percentage += cpu_percentage;
    }

    // Close the file
    fclose(fp);

    // Calculate the average CPU usage percentage
    float avg_cpu_percentage = (float) total_cpu_percentage / num_processes;

    // Print the result
    printf("Average CPU usage percentage: %.2f%%\n", avg_cpu_percentage);

    return 0;
}