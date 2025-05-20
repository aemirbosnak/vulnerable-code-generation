//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main() {
    // Set the interval to check the cpu usage
    int interval = 1;
    // Set the threshold of cpu usage
    float threshold = 70.0;

    while(1) {
        // Open the file containing the cpu usage information
        FILE* fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            printf("Failed to open file\n");
            exit(1);
        }

        // Parse the cpu usage values
        char buffer[1024];
        fgets(buffer, sizeof(buffer), fp);

        // Close the file
        fclose(fp);

        // Extract the cpu usage values
        int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
        sscanf(buffer, "cpu %d %d %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

        // Calculate the total cpu usage
        int total_time = user + nice + system + idle + iowait + irq + softirq + steal;
        int idle_time = idle + iowait;
        float cpu_usage = 100 * (1.0 - ((float)idle_time)/total_time);

        // Print the cpu usage information
        printf("CPU usage: %.2f%%\n", cpu_usage);

        // Check if the cpu usage exceeds the threshold
        if (cpu_usage > threshold) {
            printf("CPU usage exceeds threshold of %.2f%%. Sending alert!\n", threshold);
            // TODO: Send alert
        }

        // Wait for the next interval
        sleep(interval);
    }

    return 0;
}