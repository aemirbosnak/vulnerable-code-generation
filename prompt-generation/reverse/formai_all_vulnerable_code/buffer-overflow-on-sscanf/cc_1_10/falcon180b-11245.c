//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1000

int main() {
    FILE *fp;
    char buffer[BUF_SIZE];
    int cpu_percent = 0;
    int prev_idle = 0;
    int prev_total = 0;

    // Open /proc/stat file
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    // Read initial values
    fgets(buffer, BUF_SIZE, fp);
    sscanf(buffer, "cpu %d %d %d %d", &prev_idle, &prev_total, &cpu_percent, &cpu_percent);

    // Loop to monitor CPU usage
    while (1) {
        // Read current values
        fgets(buffer, BUF_SIZE, fp);
        sscanf(buffer, "cpu %d %d %d %d", &prev_idle, &prev_total, &cpu_percent, &cpu_percent);

        // Calculate CPU usage
        int idle = prev_idle;
        int total = prev_total;
        int delta_idle = idle - prev_idle;
        int delta_total = total - prev_total;
        float cpu_usage = ((float) (delta_total - delta_idle) / delta_total) * 100;

        // Print CPU usage
        printf("CPU usage: %.2f%%\n", cpu_usage);

        // Sleep for 1 second
        sleep(1);
    }

    // Close file
    fclose(fp);

    return 0;
}