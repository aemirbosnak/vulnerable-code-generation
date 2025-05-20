//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define CPU_INFO_PATH "/proc/stat"

typedef struct {
    double user;
    double nice;
    double system;
    double idle;
    double iowait;
    double irq;
    double softirq;
    double steal;
    double total;
} CpuUsage;

CpuUsage cpuUsage;

void *monitor_cpu_usage(void *arg) {
    FILE *file;
    char line[256];
    
    while (1) {
        file = fopen(CPU_INFO_PATH, "r");
        if (file == NULL) {
            perror("Error opening /proc/stat");
            exit(EXIT_FAILURE);
        }

        // Read the first line for CPU usage
        fgets(line, sizeof(line), file);
        sscanf(line, "cpu %lf %lf %lf %lf %lf %lf %lf %lf",
               &cpuUsage.user, &cpuUsage.nice, &cpuUsage.system, 
               &cpuUsage.idle, &cpuUsage.iowait, &cpuUsage.irq, 
               &cpuUsage.softirq, &cpuUsage.steal);
        
        cpuUsage.total = cpuUsage.user + cpuUsage.nice + cpuUsage.system + 
                         cpuUsage.idle + cpuUsage.iowait + cpuUsage.irq + 
                         cpuUsage.softirq + cpuUsage.steal;

        fclose(file);
        
        sleep(1);
    }

    return NULL;
}

void display_cpu_usage() {
    double total_usage = cpuUsage.user + cpuUsage.nice + cpuUsage.system + cpuUsage.iowait + cpuUsage.irq + cpuUsage.softirq + cpuUsage.steal;
    double usage_percentage = (total_usage / cpuUsage.total) * 100.0;

    printf("CPU Usage: %.2f%%\n", usage_percentage);
}

int main() {
    pthread_t cpu_thread;
    
    // Create a thread to monitor CPU usage
    if (pthread_create(&cpu_thread, NULL, monitor_cpu_usage, NULL) != 0) {
        perror("Failed to create CPU monitor thread");
        return EXIT_FAILURE;
    }

    // Continuously display CPU usage
    while (1) {
        display_cpu_usage();
        sleep(1); // Interval to update display
    }

    pthread_join(cpu_thread, NULL);
    return 0;
}