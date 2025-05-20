//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>

// Configurable options
#define REFRESH_INTERVAL 5 // Update interval in seconds
#define SAMPLE_SIZE 10 // Number of samples to average
#define PROC_STAT_PATH "/proc/stat" // Path to the process statistics file

// Function to read CPU usage from /proc/stat
int get_cpu_usage(unsigned int sample_size) {
    FILE *fp;
    unsigned long long total_cpu_time, idle_cpu_time, delta_idle_cpu_time, delta_total_cpu_time;
    int num_cpus, i;
    unsigned long long *prev_cpu_times, *cur_cpu_times;

    // Open /proc/stat
    fp = fopen(PROC_STAT_PATH, "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Allocate memory for CPU times
    prev_cpu_times = (unsigned long long *)malloc(sizeof(unsigned long long) * sample_size * num_cpus);
    cur_cpu_times = (unsigned long long *)malloc(sizeof(unsigned long long) * sample_size * num_cpus);
    if (prev_cpu_times == NULL || cur_cpu_times == NULL) {
        perror("malloc");
        return -1;
    }

    // Read CPU times into the previous array
    for (i = 0; i < sample_size; i++) {
        fscanf(fp, "%*u %llu %llu %*llu %*llu %*llu %*llu %*llu %*llu %*llu %*llu");
        fscanf(fp, "%llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &prev_cpu_times[i * num_cpus], &prev_cpu_times[i * num_cpus + 1],
              &prev_cpu_times[i * num_cpus + 2], &prev_cpu_times[i * num_cpus + 3], &prev_cpu_times[i * num_cpus + 4], &prev_cpu_times[i * num_cpus + 5],
              &prev_cpu_times[i * num_cpus + 6], &prev_cpu_times[i * num_cpus + 7], &prev_cpu_times[i * num_cpus + 8], &prev_cpu_times[i * num_cpus + 9]);
    }

    // Sleep for the refresh interval
    sleep(REFRESH_INTERVAL);

    // Read CPU times into the current array
    for (i = 0; i < sample_size; i++) {
        fscanf(fp, "%*u %llu %llu %*llu %*llu %*llu %*llu %*llu %*llu %*llu %*llu");
        fscanf(fp, "%llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &cur_cpu_times[i * num_cpus], &cur_cpu_times[i * num_cpus + 1],
              &cur_cpu_times[i * num_cpus + 2], &cur_cpu_times[i * num_cpus + 3], &cur_cpu_times[i * num_cpus + 4], &cur_cpu_times[i * num_cpus + 5],
              &cur_cpu_times[i * num_cpus + 6], &cur_cpu_times[i * num_cpus + 7], &cur_cpu_times[i * num_cpus + 8], &cur_cpu_times[i * num_cpus + 9]);
    }

    // Calculate CPU usage
    for (i = 0; i < sample_size; i++) {
        delta_total_cpu_time = cur_cpu_times[i * num_cpus] - prev_cpu_times[i * num_cpus];
        delta_idle_cpu_time = cur_cpu_times[i * num_cpus + 3] - prev_cpu_times[i * num_cpus + 3];
        total_cpu_time += delta_total_cpu_time;
        idle_cpu_time += delta_idle_cpu_time;
    }

    // Calculate average CPU usage
    double avg_cpu_usage = 100.0 * (total_cpu_time - idle_cpu_time) / total_cpu_time / sample_size;

    // Free allocated memory
    free(prev_cpu_times);
    free(cur_cpu_times);

    // Close /proc/stat
    fclose(fp);

    // Return CPU usage
    return (int)avg_cpu_usage;
}

// Main function
int main() {
    while (1) {
        // Print CPU usage
        printf("CPU usage: %d%%\n", get_cpu_usage(SAMPLE_SIZE));

        // Sleep for the refresh interval
        sleep(REFRESH_INTERVAL);
    }

    return 0;
}