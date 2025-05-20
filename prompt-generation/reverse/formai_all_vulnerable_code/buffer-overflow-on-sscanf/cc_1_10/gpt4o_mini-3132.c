//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define FILE_PATH "/proc/stat"
#define BUFFER_SIZE 256

void get_cpu_times(long long *user, long long *nice, long long *system,
                   long long *idle, long long *iowait, long long *irq,
                   long long *softirq) {
    FILE *fp = fopen(FILE_PATH, "r");
    if (fp == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, fp) == NULL) {
        perror("Failed to read from file");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    sscanf(buffer, "cpu %lld %lld %lld %lld %lld %lld %lld",
           user, nice, system, idle, iowait, irq, softirq);

    fclose(fp);
}

double calculate_cpu_usage(long long prev_total, long long prev_idle, 
                            long long total, long long idle) {
    long long total_diff = total - prev_total;
    long long idle_diff = idle - prev_idle;
    return (1.0 - (idle_diff / (double)total_diff)) * 100.0; // In percentage
}

void print_cpu_usage(double usage) {
    printf("CPU Usage: %.2f%%\n", usage);
}

int main() {
    long long user, nice, system, idle, iowait, irq, softirq;
    long long prev_total, prev_idle;
    long long total, idle_time;
    int interval = 1; // Time interval in seconds

    // Initial reading of CPU times
    get_cpu_times(&user, &nice, &system, &idle, &iowait, &irq, &softirq);
    prev_total = user + nice + system + idle + iowait + irq + softirq;
    prev_idle = idle;

    printf("Starting CPU Usage Monitor...\n");

    while (1) {
        sleep(interval); // Sleep for the specified interval

        // Get CPU times again
        get_cpu_times(&user, &nice, &system, &idle, &iowait, &irq, &softirq);
        total = user + nice + system + idle + iowait + irq + softirq;
        idle_time = idle;

        // Calculate CPU usage
        double usage = calculate_cpu_usage(prev_total, prev_idle, total, idle_time);
        print_cpu_usage(usage);

        // Update previous values
        prev_total = total;
        prev_idle = idle_time;
    }

    return 0;
}