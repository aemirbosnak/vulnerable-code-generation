//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define TOTAL_CPUS 4 // Number of CPUs in the system
#define SLEEP_TIME 5 // Sleep time in seconds

// Function to get CPU usage
double get_cpu_usage(int cpu_id) {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        printf("Error getting CPU usage\n");
        exit(1);
    }
    double cpu_time = (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0;
    double total_time = (double)usage.ru_stime.tv_sec + (double)usage.ru_stime.tv_usec / 1000000.0;
    return cpu_time / total_time * 100.0;
}

// Function to print CPU usage
void print_cpu_usage(double cpu_usage) {
    printf("CPU usage: %.2f%%\n", cpu_usage);
}

int main() {
    int i, j;
    double cpu_usages[TOTAL_CPUS];

    // Initialize CPU usage array
    for (i = 0; i < TOTAL_CPUS; i++) {
        cpu_usages[i] = 0.0;
    }

    // Main loop
    while (1) {
        for (i = 0; i < TOTAL_CPUS; i++) {
            cpu_usages[i] = get_cpu_usage(i);
        }

        // Print CPU usage for each CPU
        for (i = 0; i < TOTAL_CPUS; i++) {
            printf("CPU %d usage: %.2f%%\n", i, cpu_usages[i]);
        }

        // Sleep for some time
        sleep(SLEEP_TIME);
    }

    return 0;
}