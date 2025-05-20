//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

// Function to get the CPU usage in percentage
double get_cpu_usage() {
    // Get the current time
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    // Get the CPU usage for the last second
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            // Parse the CPU usage
            unsigned long long user, nice, system, idle, iowait, irq, softirq;
            sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system, &idle, &iowait, &irq, &softirq);

            // Calculate the CPU usage
            double total = user + nice + system + idle + iowait + irq + softirq;
            double idle_time = idle + iowait;
            double usage = (total - idle_time) / total * 100;

            // Close the file
            fclose(fp);

            // Return the CPU usage
            return usage;
        }
    }

    // Close the file
    fclose(fp);

    // Error
    return -1;
}

int main() {
    // Get the CPU usage every second
    while (1) {
        // Get the CPU usage
        double usage = get_cpu_usage();

        // Print the CPU usage
        printf("CPU usage: %.2f%%\n", usage);

        // Sleep for one second
        sleep(1);
    }

    return 0;
}