//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void get_cpu_times(long *user, long *nice, long *system, long *idle, long *iowait, long *irq, long *softirq, long *steal) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), fp);  // Read the first line
    sscanf(line, "cpu %ld %ld %ld %ld %ld %ld %ld %ld", user, nice, system, idle, iowait, irq, softirq, steal);

    fclose(fp);
}

double calculate_cpu_usage(long prev_idle, long prev_total, long idle, long total) {
    long idle_delta = idle - prev_idle;
    long total_delta = total - prev_total;

    return (total_delta - idle_delta) * 100.0 / total_delta;  // Usage in percentage
}

long get_total_time(long user, long nice, long system, long idle, long iowait, long irq, long softirq, long steal) {
    return user + nice + system + idle + iowait + irq + softirq + steal;
}

int main() {
    long user, nice, system, idle, iowait, irq, softirq, steal;
    long prev_idle = 0, prev_total = 0;
    double cpu_usage;

    printf("Welcome to the CPU Usage Monitor\n");
    printf("Press Ctrl+C to exit\n");

    while (1) {
        get_cpu_times(&user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
        
        long total_time = get_total_time(user, nice, system, idle, iowait, irq, softirq, steal);

        if (prev_total != 0) {
            cpu_usage = calculate_cpu_usage(prev_idle, prev_total, idle, total_time);
            printf("CPU Usage: %.2f%%\n", cpu_usage);
        }

        prev_idle = idle;
        prev_total = total_time;

        sleep(1);  // Update every second
    }

    return 0;
}