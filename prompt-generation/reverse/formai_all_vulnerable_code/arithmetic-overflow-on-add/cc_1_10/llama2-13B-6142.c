//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/resource.h>

#define CPU_THRESHOLD 75 // percent

int main() {
    // Set up CPU monitoring
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    float avg_cpu_usage = (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) / 2;

    // Create a random background color
    int r = (rand() % 256);
    int g = (rand() % 256);
    int b = (rand() % 256);

    // Set up the CPU usage monitor
    int monitor_interval = 1000; // 1 second
    int monitor_count = 0;

    // Main loop
    while (1) {
        // Monitor CPU usage
        getrusage(RUSAGE_SELF, &usage);
        avg_cpu_usage = (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) / 2;

        // Check if CPU usage is above threshold
        if (avg_cpu_usage > CPU_THRESHOLD) {
            // Print CPU usage in a fancy way
            printf("CPU usage: %3.2f%% 🔥🔥🔥\n", avg_cpu_usage);
        } else {
            printf("CPU usage: %3.2f%% 😌\n", avg_cpu_usage);
        }

        // Update background color based on CPU usage
        if (avg_cpu_usage > CPU_THRESHOLD) {
            r = 255; // red
            g = 0; // green
            b = 0; // blue
        } else {
            r = 0; // red
            g = 255; // green
            b = 0; // blue
        }

        // Update the background color
        printf("Background color: %d, %d, %d\n", r, g, b);

        // Sleep for a bit
        sleep(monitor_interval);
        monitor_count++;

        // Print CPU usage monitor stats
        if (monitor_count % 10 == 0) {
            printf("CPU usage monitor stats: avg_cpu_usage=%3.2f, monitor_count=%d\n", avg_cpu_usage, monitor_count);
        }
    }

    return 0;
}