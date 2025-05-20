//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define CPU_INFO_FILE "/proc/stat"
#define INTERVAL 1

typedef struct {
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
    unsigned long irq;
    unsigned long softirq;
} CpuUsage;

void read_cpu_usage(CpuUsage *cpu_usage) {
    FILE *file = fopen(CPU_INFO_FILE, "r");
    if (!file) {
        perror("Failed to open CPU info file");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu %lu",
               &cpu_usage->user,
               &cpu_usage->nice,
               &cpu_usage->system,
               &cpu_usage->idle,
               &cpu_usage->iowait,
               &cpu_usage->irq,
               &cpu_usage->softirq);
    }

    fclose(file);
}

void calculate_cpu_usage(CpuUsage *prev, CpuUsage *curr, double *cpu_percent) {
    unsigned long prev_idle = prev->idle + prev->iowait;
    unsigned long curr_idle = curr->idle + curr->iowait;

    unsigned long prev_total = prev->user + prev->nice + prev->system + prev_idle + prev->irq + prev->softirq;
    unsigned long curr_total = curr->user + curr->nice + curr->system + curr_idle + curr->irq + curr->softirq;

    unsigned long total_diff = curr_total - prev_total;
    unsigned long idle_diff = curr_idle - prev_idle;

    *cpu_percent = (total_diff - idle_diff) * 100.0 / total_diff;
}

void *monitor_cpu_usage(void *arg) {
    double cpu_usage_percent;
    CpuUsage cpu_usage_prev, cpu_usage_curr;

    read_cpu_usage(&cpu_usage_prev);
    
    while (1) {
        sleep(INTERVAL);
        read_cpu_usage(&cpu_usage_curr);
        calculate_cpu_usage(&cpu_usage_prev, &cpu_usage_curr, &cpu_usage_percent);
        
        printf("CPU Usage: %.2f%%\n", cpu_usage_percent);
        
        // Update previous values
        cpu_usage_prev = cpu_usage_curr;
    }
    
    return NULL;
}

int main() {
    pthread_t cpu_thread;

    if (pthread_create(&cpu_thread, NULL, monitor_cpu_usage, NULL) != 0) {
        perror("Failed to create CPU monitoring thread");
        exit(EXIT_FAILURE);
    }

    // Allow monitoring for a specified period (e.g., run for 30 seconds)
    sleep(30);
        
    // Terminate the monitoring thread
    pthread_cancel(cpu_thread);
    pthread_join(cpu_thread, NULL);

    printf("CPU monitoring terminated.\n");
    return 0;
}