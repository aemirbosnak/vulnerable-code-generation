//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 128

// Function to read CPU usage from /proc/stat
void read_cpu_usage(int *total_time, int *idle_time) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    int user, nice, system, idle, iowait, irq, softirq, steal, total;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %d %d %d %d %d %d %d %d %d", 
           &user, &nice, &system, &idle, 
           &iowait, &irq, &softirq, &steal);

    *idle_time = idle;
    *total_time = user + nice + system + idle + 
                  iowait + irq + softirq + steal;

    fclose(fp);
}

// Function to calculate CPU usage
double calculate_cpu_usage(int prev_total, int prev_idle, 
                            int curr_total, int curr_idle) {
    int total_delta = curr_total - prev_total;
    int idle_delta = curr_idle - prev_idle;

    return ((double)(total_delta - idle_delta) / total_delta) * 100.0;
}

// Recursive function to display CPU usage
void display_cpu_usage(int prev_total, int prev_idle) {
    int curr_total, curr_idle;

    read_cpu_usage(&curr_total, &curr_idle);

    double usage = calculate_cpu_usage(prev_total, prev_idle, 
                                        curr_total, curr_idle);

    printf("CPU Usage: %.2f%%\n", usage);

    // Recursive call with the current values
    sleep(1); // Wait for 1 second before the next check
    display_cpu_usage(curr_total, curr_idle);
}

int main() {
    int prev_total, prev_idle;

    read_cpu_usage(&prev_total, &prev_idle);
    printf("Starting CPU usage monitoring...\n");

    // Start the recursive monitoring
    display_cpu_usage(prev_total, prev_idle);

    return 0;
}