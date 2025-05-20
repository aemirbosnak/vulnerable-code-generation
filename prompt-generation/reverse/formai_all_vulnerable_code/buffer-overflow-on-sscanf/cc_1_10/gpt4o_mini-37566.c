//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 256

void get_cpu_usage(float* idle_time, float* total_time) {
    FILE* file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Unable to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LENGTH];
    if (fgets(line, sizeof(line), file) != NULL) {
        unsigned long user, nice, system, idle, iowait, irq, softirq, steal;

        sscanf(line, "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
               &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);

        *idle_time = (float)idle;
        *total_time = (float)(user + nice + system + idle + iowait + irq + softirq + steal);
    } else {
        perror("Failed to read line from /proc/stat");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

float calculate_cpu_usage(float idle_time, float total_time, float previous_idle, float previous_total) {
    float idle_diff = idle_time - previous_idle;
    float total_diff = total_time - previous_total;

    return 100.0 * (1.0 - (idle_diff / total_diff));
}

int main() {
    printf("🌟 Welcome to the CPU Usage Monitor! 🌟\n");
    printf("🐱‍👤 Monitoring CPU usage... Press Ctrl+C to exit! 🐱‍👤\n");

    float previous_idle_time = 0.0, previous_total_time = 0.0;
    float idle_time, total_time;

    while (1) {
        get_cpu_usage(&idle_time, &total_time);
        if (previous_total_time != 0.0) {
            float cpu_usage = calculate_cpu_usage(idle_time, total_time, previous_idle_time, previous_total_time);
            printf("🚀 Current CPU Usage: %.2f%%\n", cpu_usage);
        }

        previous_idle_time = idle_time;
        previous_total_time = total_time;

        sleep(1); // Wait for 1 second before the next reading
    }

    return 0;
}