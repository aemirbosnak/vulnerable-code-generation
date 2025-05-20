//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TIME_INTERVAL 1 // Time interval in seconds

// Function to read CPU statistics from /proc/stat
void get_cpu_usage(long long *idle_time, long long *total_time) {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), fp); // Read the first line
    fclose(fp);

    long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

    // Parse CPU times from the line
    sscanf(buffer, "cpu %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

    *idle_time = idle + iowait;
    *total_time = user + nice + system + *idle_time + irq + softirq + steal + guest + guest_nice;
}

// Function to calculate CPU usage
void calculate_cpu_usage() {
    long long idle_time1, total_time1;
    long long idle_time2, total_time2;

    // Get initial CPU statistics
    get_cpu_usage(&idle_time1, &total_time1);
    sleep(TIME_INTERVAL); // Wait for the specified interval
    // Get CPU statistics after the interval
    get_cpu_usage(&idle_time2, &total_time2);

    // Calculate CPU usage
    long long idle_time_diff = idle_time2 - idle_time1;
    long long total_time_diff = total_time2 - total_time1;
    double cpu_usage = 100.0 * (1.0 - ((double)idle_time_diff / (double)total_time_diff));

    printf("CPU Usage: %.2f%%\n", cpu_usage);
}

int main() {
    printf("CPU Usage Monitor\n");
    printf("Press Ctrl+C to stop monitoring...\n");

    while (1) {
        calculate_cpu_usage();
    }

    return 0;
}