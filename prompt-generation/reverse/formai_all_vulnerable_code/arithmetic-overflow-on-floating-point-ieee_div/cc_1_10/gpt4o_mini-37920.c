//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/sysinfo.h>

#define MAX_PROCESSES 1024
#define INTERVAL 1

void get_cpu_usage(float *cpu_usage) {
    FILE *file;
    char line[256];
    unsigned long total_user, total_user_nice, total_sys, total_idle, total_iowait, total_steal;
    unsigned long total;

    file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    fgets(line, sizeof(line), file);
    fclose(file);
    
    sscanf(line, "cpu %lu %lu %lu %lu %lu %lu %lu", &total_user, &total_user_nice, &total_sys, &total_idle, &total_iowait, &total_steal);

    total = total_user + total_user_nice + total_sys + total_idle + total_iowait + total_steal;

    // Calculate CPU usage
    *cpu_usage = 100.0 * (total - total_idle) / total;
}

void display_header() {
    printf("\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|                      CPU Usage Monitor                    |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| %-10s | %-10s | %-10s |\n", "CPU", "Usage (%)", "Time");
    printf("+-----------------------------------------------------------+\n");
}

void display_cpu_usage() {
    char timestamp[64];
    float cpu_usage;

    get_cpu_usage(&cpu_usage);
    
    // Get current time
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", current_time);
    
    printf("| %-10s | %-10.2f | %-10s |\n", "CPU0", cpu_usage, timestamp);
}

int main() {
    // Set terminal to safe mode
    system("clear");
    display_header();
    
    // Monitor CPU usage at regular intervals
    while (1) {
        display_cpu_usage();
        sleep(INTERVAL);
    }

    return 0;
}