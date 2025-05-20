//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

// Structure to store CPU usage data
typedef struct {
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
    unsigned long irq;
    unsigned long softirq;
    unsigned long steal;
    unsigned long guest;
    unsigned long guest_nice;
} CPUData;

// Function declarations
CPUData get_cpu_data();
void display_cpu_usage(CPUData prev_data, CPUData curr_data);
void monitor_cpu_usage(int interval, int duration);

int main(int argc, char *argv[]) {
    int interval = 1;  // default interval in seconds
    int duration = 10; // default monitor duration in seconds

    // Parse command line arguments
    if (argc > 1) {
        interval = atoi(argv[1]);
    }
    if (argc > 2) {
        duration = atoi(argv[2]);
    }

    if (interval <= 0 || duration <= 0) {
        fprintf(stderr, "Both interval and duration must be positive integers.\n");
        return EXIT_FAILURE;
    }

    monitor_cpu_usage(interval, duration);

    return EXIT_SUCCESS;
}

// Function to read CPU data from /proc/stat
CPUData get_cpu_data() {
    CPUData cpu_data = {0};
    FILE *fp = fopen("/proc/stat", "r");

    if (fp == NULL) {
        perror("Could not open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    if (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "cpu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",
               &cpu_data.user, &cpu_data.nice, &cpu_data.system,
               &cpu_data.idle, &cpu_data.iowait, 
               &cpu_data.irq, &cpu_data.softirq,
               &cpu_data.steal, &cpu_data.guest, 
               &cpu_data.guest_nice);
    }

    fclose(fp);
    return cpu_data;
}

// Function to calculate and display CPU usage
void display_cpu_usage(CPUData prev_data, CPUData curr_data) {
    unsigned long prev_total = prev_data.user + prev_data.nice + prev_data.system +
                                prev_data.idle + prev_data.iowait + prev_data.irq +
                                prev_data.softirq + prev_data.steal;

    unsigned long curr_total = curr_data.user + curr_data.nice + curr_data.system +
                                curr_data.idle + curr_data.iowait + curr_data.irq +
                                curr_data.softirq + curr_data.steal;

    unsigned long total_diff = curr_total - prev_total;
    unsigned long idle_diff = curr_data.idle - prev_data.idle;

    double cpu_usage = 100.0 * (total_diff - idle_diff) / total_diff;

    printf("CPU Usage: %.2f%%\n", cpu_usage);
}

// Main monitoring loop
void monitor_cpu_usage(int interval, int duration) {
    CPUData prev_data = get_cpu_data();

    for (int i = 0; i < duration; i += interval) {
        sleep(interval);
        CPUData curr_data = get_cpu_data();
        display_cpu_usage(prev_data, curr_data);
        prev_data = curr_data;
    }
}