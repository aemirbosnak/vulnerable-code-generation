//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_CPU 10
#define SLEEP_DURATION 2

void display_welcome_message() {
    printf("🎉 Welcome to the Happy CPU Usage Monitor! 🎉\n");
    printf("Tracking CPU usage is fun and easy.\n");
    printf("Let's dive in and see how busy your computer is! 🚀\n\n");
    sleep(1);
}

void read_cpu_usage() {
    FILE *fp;
    char buffer[1024];
    float cpu_usage;
    int cpu_count = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strncmp(buffer, "cpu", 3) == 0) {
            unsigned long user, nice, sys, idle, iowait, irq, softirq, steal, guest, guest_nice;
            sscanf(buffer, "cpu%d %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu", &cpu_count,
                   &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
            unsigned long non_idle = user + nice + sys + irq + softirq + steal;
            unsigned long total = non_idle + idle;

            cpu_usage = (float)(non_idle) / total * 100.0;
            printf("CPU %d Usage: %.2f%%\n", cpu_count, cpu_usage);
            cpu_count++;

            if(cpu_count >= MAX_CPU) break; // limit to MAX_CPU monitors
        }
    }

    fclose(fp);
}

void monitor_cpu() {
    while (1) {
        printf("\n📊 Monitoring CPU Usage...\n");
        read_cpu_usage();
        printf("\n✨ Happy Monitoring! Let's check again in %d seconds... ✨\n\n", SLEEP_DURATION);
        sleep(SLEEP_DURATION);
    }
}

int main() {
    display_welcome_message();
    monitor_cpu();
    
    return 0;
}