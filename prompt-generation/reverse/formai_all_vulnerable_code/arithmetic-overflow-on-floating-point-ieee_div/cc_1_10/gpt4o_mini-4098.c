//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define CPU_USAGE_INTERVAL 1 // seconds
#define MAX_CPUS 128

typedef struct {
    int cpu_count;
    float cpu_usage[MAX_CPUS];
} CpuUsageData;

void* monitor_cpu_usage(void* arg) {
    CpuUsageData* data = (CpuUsageData*)arg;
    char buffer[256];
    FILE* statfile;
    long unsigned int user, nice, sys, idle, iowait, irq, softirq, steal, total;
    
    while (1) {
        statfile = fopen("/proc/stat", "r");
        if (!statfile) {
            perror("Failed to open /proc/stat");
            return NULL;
        }

        for (data->cpu_count = 0; data->cpu_count < MAX_CPUS; data->cpu_count++) {
            if (fgets(buffer, sizeof(buffer), statfile) == NULL || strncmp(buffer, "cpu", 3) != 0) {
                break; // end of CPU stats
            }
            sscanf(buffer, "cpu%d %lu %lu %lu %lu %lu %lu %lu %lu", 
                   &data->cpu_count, 
                   &user, &nice, &sys, &idle, 
                   &iowait, &irq, &softirq, &steal);
            total = user + nice + sys + idle + iowait + irq + softirq + steal;
            data->cpu_usage[data->cpu_count] = ((float)(total - idle) / total) * 100.0;
        }
        
        fclose(statfile);
        sleep(CPU_USAGE_INTERVAL);
    }
    return NULL;
}

void display_cpu_usage(CpuUsageData* data) {
    printf("\033[H\033[J"); // Clear screen
    printf("CPU Usage Monitor\n");
    printf("------------------\n");
    for (int i = 0; i < data->cpu_count; i++) {
        printf("CPU%d: %.2f%%\n", i, data->cpu_usage[i]);
    }
    fflush(stdout);
}

int main() {
    CpuUsageData data;
    pthread_t monitor_thread;

    if (pthread_create(&monitor_thread, NULL, monitor_cpu_usage, &data) != 0) {
        perror("Failed to create thread");
        exit(EXIT_FAILURE);
    }

    while (1) {
        display_cpu_usage(&data);
        usleep(1000000); // Refresh every second
    }

    pthread_join(monitor_thread, NULL);
    return 0;
}