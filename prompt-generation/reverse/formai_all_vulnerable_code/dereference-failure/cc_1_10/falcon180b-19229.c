//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define CPU_USAGE_INTERVAL 1 // CPU usage update interval in seconds

// Function to get CPU usage as a percentage
double get_cpu_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return (double)100 * (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec + usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / (double)(usage.ru_utime.tv_sec + usage.ru_stime.tv_sec + usage.ru_utime.tv_usec + usage.ru_stime.tv_usec + 1e6);
}

int main() {
    printf("Starting CPU usage monitor...\n");

    // Initialize variables
    double previous_cpu_usage = 0;
    int num_processors = sysconf(_SC_NPROCESSORS_ONLN);
    double *cpu_usage_array = malloc(num_processors * sizeof(double));
    for (int i = 0; i < num_processors; i++) {
        cpu_usage_array[i] = 0;
    }

    while (1) {
        sleep(CPU_USAGE_INTERVAL);

        // Get current CPU usage for each processor
        for (int i = 0; i < num_processors; i++) {
            cpu_usage_array[i] = get_cpu_usage();
        }

        // Calculate average CPU usage
        double total_cpu_usage = 0;
        for (int i = 0; i < num_processors; i++) {
            total_cpu_usage += cpu_usage_array[i];
        }
        double average_cpu_usage = total_cpu_usage / num_processors;

        // Print CPU usage
        printf("Average CPU usage: %.2f%%\n", average_cpu_usage);

        // Update previous CPU usage for next iteration
        previous_cpu_usage = average_cpu_usage;
    }

    return 0;
}