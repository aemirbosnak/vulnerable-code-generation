//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_STRING_LENGTH 256

int main() {
    // Variables
    double idle_time, total_time;
    double prev_idle_time = 0, prev_total_time = 0;
    double cpu_usage;
    int cpu_count;
    FILE *fp;
    char buffer[MAX_STRING_LENGTH];

    // Get number of CPU cores
    cpu_count = get_nprocs();

    while (1) {
        // Open the file containing CPU usage information
        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            printf("Failed to open /proc/stat file.\n");
            exit(1);
        }

        // Read the first line from the file
        fgets(buffer, MAX_STRING_LENGTH, fp);

        // Close the file
        fclose(fp);

        // Parse the numbers from the line
        sscanf(buffer, "cpu %lf %lf", &idle_time, &total_time);

        // Calculate CPU usage
        if (prev_idle_time == 0 && prev_total_time == 0) {
            cpu_usage = 0;
        } else {
            cpu_usage = (1 - ((idle_time - prev_idle_time) / (total_time - prev_total_time))) / cpu_count * 100;
        }

        // Store idle and total times
        prev_idle_time = idle_time;
        prev_total_time = total_time;

        // Print CPU usage
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        // Wait for one second before checking again
        sleep(1);
    }

    return 0;
}