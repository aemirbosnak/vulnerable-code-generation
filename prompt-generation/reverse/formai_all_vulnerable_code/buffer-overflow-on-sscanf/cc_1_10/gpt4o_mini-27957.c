//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_CPU 16 // Maximum number of CPUs we’ll monitor

void get_cpu_usage(double cpu_usage[MAX_CPU]) {
    FILE *fp;
    char buffer[256];
    unsigned long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    unsigned long total_idle, total_non_idle, total;

    fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line for the CPU stats
    fgets(buffer, sizeof(buffer), fp);
    
    sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu", 
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    
    total_idle = idle + iowait;
    total_non_idle = user + nice + system + irq + softirq + steal + guest + guest_nice;
    total = total_idle + total_non_idle;

    double cpu_percentage = 100.0 * (total_non_idle) / total; // Calculate percentage
    cpu_usage[0] = cpu_percentage; // Store usage for the first CPU
    
    fclose(fp);
}

void format_and_print_usage(double cpu_usage[MAX_CPU]) {
    printf("\n---------------- CPU USAGE MONITOR ----------------\n");
    printf("CPU Usage: %.2f%%\n", cpu_usage[0]);
    printf("---------------------------------------------------\n");
}

int main() {
    double cpu_usage[MAX_CPU];
    int interval = 1; // Interval in seconds

    printf("Starting CPU usage monitoring...\n");
    
    while (1) {
        get_cpu_usage(cpu_usage);
        format_and_print_usage(cpu_usage);
        sleep(interval);
    }

    return 0;
}