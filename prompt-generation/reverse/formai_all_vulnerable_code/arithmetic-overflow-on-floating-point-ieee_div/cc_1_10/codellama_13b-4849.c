//Code Llama-13B DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
// CPU usage monitor program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Function to calculate CPU usage
float calculate_cpu_usage(int prev_total, int prev_idle) {
    int total = 0;
    int idle = 0;

    // Get current CPU usage
    FILE* fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }
    fscanf(fp, "cpu %d %d", &total, &idle);
    fclose(fp);

    // Calculate CPU usage
    int total_diff = total - prev_total;
    int idle_diff = idle - prev_idle;
    float usage = (float)(total_diff - idle_diff) / (float)total_diff;

    // Return CPU usage
    return usage;
}

int main() {
    // Initialize previous CPU usage values
    int prev_total = 0;
    int prev_idle = 0;

    // Get initial CPU usage
    FILE* fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }
    fscanf(fp, "cpu %d %d", &prev_total, &prev_idle);
    fclose(fp);

    // Loop and print CPU usage
    while (1) {
        float usage = calculate_cpu_usage(prev_total, prev_idle);
        printf("CPU usage: %.2f%%\n", usage * 100);

        // Wait for 1 second
        sleep(1);

        // Get current CPU usage
        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            printf("Error opening /proc/stat\n");
            exit(1);
        }
        fscanf(fp, "cpu %d %d", &prev_total, &prev_idle);
        fclose(fp);
    }

    return 0;
}