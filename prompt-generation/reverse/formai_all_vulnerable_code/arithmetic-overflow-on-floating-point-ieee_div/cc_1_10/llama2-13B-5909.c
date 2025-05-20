//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/resource.h>

#define CPU_THRESHOLD 75 // percentage

int main() {
    // Initialize CPU usage data structures
    struct rusage cpu_usage;
    getrusage(RUSAGE_SELF, &cpu_usage);
    double avg_cpu_usage = (double)cpu_usage.ru_utime.tv_sec / (double)cpu_usage.ru_utime.tv_usec;

    // Set up a timer to measure CPU usage
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    long long int start_time = ts.tv_sec;

    // Main loop
    while (1) {
        // Measure CPU usage
        getrusage(RUSAGE_SELF, &cpu_usage);
        double current_cpu_usage = (double)cpu_usage.ru_utime.tv_sec / (double)cpu_usage.ru_utime.tv_usec;

        // Check if CPU usage is above the threshold
        if (current_cpu_usage > CPU_THRESHOLD) {
            // Print a warning message if CPU usage is above the threshold
            printf(
                "CPU usage above threshold (%.2f %%): "
                "Current: %.*f s, "
                "Threshold: %.*f s\n",
                CPU_THRESHOLD * 100,
                (int)current_cpu_usage,
                avg_cpu_usage,
                CPU_THRESHOLD * 100
            );
        }

        // Sleep for a short period of time to avoid excessive CPU usage
        usleep(100000);

        // Update the average CPU usage
        avg_cpu_usage = current_cpu_usage;

        // Check if the program should be terminated
        if (avg_cpu_usage > CPU_THRESHOLD && current_cpu_usage > CPU_THRESHOLD) {
            printf("Terminating program due to excessive CPU usage\n");
            break;
        }
    }

    // Print the final CPU usage
    printf("Final CPU usage: %.*f s\n", (int)avg_cpu_usage);

    return 0;
}