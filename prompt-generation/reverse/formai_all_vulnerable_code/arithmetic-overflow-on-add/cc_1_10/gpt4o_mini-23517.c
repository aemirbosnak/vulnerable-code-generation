//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 100

void get_cpu_usage(int *total_idle, int *total_all) {
    FILE *fp;
    char buffer[MAX];
    int user, nice, system, idle, iowait, irq, softirq;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }
    
    if (fgets(buffer, MAX, fp) != NULL) {
        sscanf(buffer, "cpu %d %d %d %d %d %d %d %d", 
               &user, &nice, &system, 
               &idle, &iowait, &irq, 
               &softirq);
    }
    
    fclose(fp);
    
    *total_idle = idle + iowait;
    *total_all = user + nice + system + *total_idle + irq + softirq;
}

double calculate_cpu_usage(int *total_idle, int *total_all) {
    static int prev_idle = 0, prev_all = 0;
    double usage;
    
    int idle = *total_idle;
    int all = *total_all;

    usage = 1.0 - ((idle - prev_idle) / (double)(all - prev_all));

    prev_idle = idle;
    prev_all = all;

    return usage * 100.0;
}

void display_usage(double usage) {
    printf("\rCPU Usage: %.2f%%", usage);
    fflush(stdout);
}

int main() {
    int total_idle = 0, total_all = 0;
    double cpu_usage;

    printf("CPU Usage Monitor\n");
    printf("Press Ctrl+C to stop the monitor.\n");

    while (1) {
        get_cpu_usage(&total_idle, &total_all);
        cpu_usage = calculate_cpu_usage(&total_idle, &total_all);
        display_usage(cpu_usage);
        sleep(1);  // Update every second
    }

    return 0;
}