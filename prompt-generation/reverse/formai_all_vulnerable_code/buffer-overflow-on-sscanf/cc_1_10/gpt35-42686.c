//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/resource.h>
#include <unistd.h>

#define INTERVAL 1 // The interval in seconds between each monitor update
#define BUFFER_SIZE 1024 // The buffer size for reading /proc/stat file

int main() {
    printf("Starting CPU Monitor...\n");

    unsigned long long prev_idle=0, prev_total=0;
    float cpu_usage = 0;

    while (1) {
        // Open /proc/stat for reading
        FILE *stat_file = fopen("/proc/stat", "r");
        if (stat_file == NULL) {
            printf("Error opening /proc/stat file.\n");
            exit(1);
        }

        // Read the first line of the /proc/stat file
        char buffer[BUFFER_SIZE];
        fgets(buffer, BUFFER_SIZE-1, stat_file);

        // Extract the values for user, nice, system, idle, iowait, irq, and softirq columns
        unsigned long long user, nice, system, idle, iowait, irq, softirq;
        sscanf(buffer, "cpu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system, &idle, &iowait, &irq, &softirq);
        
        // Close the stat_file
        fclose(stat_file);

        // Calculate total time and idle time
        unsigned long long total = user + nice + system + idle + iowait + irq + softirq;
        unsigned long long idle_time = idle;

        // Calculate the CPU usage percentage
        if (prev_idle != 0 && prev_total != 0) {
            float delta_idle = idle_time - prev_idle;
            float delta_total = total - prev_total;
            cpu_usage = 100.0 * (1.0 - delta_idle / delta_total);
        }

        // Store the current idle and total values for the next iteration
        prev_idle = idle_time;
        prev_total = total;

        // Print the CPU usage percentage
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        // Sleep for INTERVAL seconds before recalculating the CPU usage percentage
        sleep(INTERVAL);
    }

    return 0;
}