//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

// Get CPU time in milliseconds
unsigned long long get_cpu_time() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return (usage.ru_utime.tv_sec * 1000) + (usage.ru_utime.tv_usec / 1000);
}

int main() {
    // Initialize variables
    unsigned long long start_time = get_cpu_time();
    unsigned long long prev_cpu_time = 0;
    unsigned long long prev_idle_time = 0;
    unsigned long long total_cpu_time = 0;
    unsigned long long total_idle_time = 0;
    unsigned long long cpu_usage = 0;

    // Loop forever to continuously monitor CPU usage
    while (1) {
        // Get current CPU time
        unsigned long long curr_cpu_time = get_cpu_time();

        // Get current idle time
        FILE *fp = fopen("/proc/stat", "r");
        char line[1024];
        while (fgets(line, sizeof(line), fp) != NULL) {
            if (strncmp(line, "cpu ", 4) == 0) {
                sscanf(line, "cpu  %llu %llu %llu %llu", &total_cpu_time, &total_idle_time, &total_cpu_time, &total_idle_time);
                break;
            }
        }
        fclose(fp);

        // Calculate CPU usage
        cpu_usage = (total_cpu_time - prev_cpu_time - (total_idle_time - prev_idle_time)) * 100 / (curr_cpu_time - start_time - prev_cpu_time - prev_idle_time);

        // Print CPU usage
        printf("CPU Usage: %llu%%\n", cpu_usage);

        // Update previous CPU and idle times
        prev_cpu_time = total_cpu_time;
        prev_idle_time = total_idle_time;
    }

    return 0;
}