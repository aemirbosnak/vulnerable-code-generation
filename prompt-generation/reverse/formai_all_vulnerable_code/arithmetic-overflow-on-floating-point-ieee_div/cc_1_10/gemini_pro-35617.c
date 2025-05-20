//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of seconds to monitor the CPU usage
#define MONITORING_INTERVAL 5

// Get the current CPU usage
float get_cpu_usage() {
    // Open the proc/stat file
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        return -1;
    }

    // Read the first line of the file
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("Error reading /proc/stat");
        fclose(fp);
        return -1;
    }

    // Parse the first line of the file
    int user, nice, system, idle, iowait, irq, softirq;
    sscanf(line, "cpu  %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    // Calculate the CPU usage
    float cpu_usage = (float)(user + nice + system + irq + softirq) / (user + nice + system + idle + iowait + irq + softirq);

    // Close the proc/stat file
    fclose(fp);

    return cpu_usage;
}

// Main function
int main() {
    // Get the current time
    time_t start_time = time(NULL);

    // Monitor the CPU usage
    while (time(NULL) - start_time < MONITORING_INTERVAL) {
        // Get the CPU usage
        float cpu_usage = get_cpu_usage();

        // Print the CPU usage
        printf("CPU usage: %.2f%%\n", cpu_usage * 100);

        // Sleep for one second
        sleep(1);
    }

    return 0;
}