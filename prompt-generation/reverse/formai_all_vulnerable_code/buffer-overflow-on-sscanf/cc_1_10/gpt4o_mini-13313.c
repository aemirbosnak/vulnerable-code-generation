//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <pthread.h>
#include <errno.h>

#define CPU_USAGE_SAMPLES 100
#define SLEEP_INTERVAL 1

typedef struct {
    double user;
    double nice;
    double system;
    double idle;
    double iowait;
    double irq;
    double softirq;
    double steal;
} CPUStats;

CPUStats previous_stats;
CPUStats current_stats;

void read_cpu_stats(CPUStats *stats) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }
    
    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %lf %lf %lf %lf %lf %lf %lf %lf",
           &stats->user,
           &stats->nice,
           &stats->system,
           &stats->idle,
           &stats->iowait,
           &stats->irq,
           &stats->softirq,
           &stats->steal);
    
    fclose(fp);
}

void calculate_cpu_usage() {
    double prev_idle = previous_stats.idle + previous_stats.iowait;
    double idle = current_stats.idle + current_stats.iowait;
    double prev_total = previous_stats.user + previous_stats.nice + previous_stats.system + prev_idle;
    double total = current_stats.user + current_stats.nice + current_stats.system + idle;

    double total_diff = total - prev_total;
    double idle_diff = idle - prev_idle;

    double usage = ((total_diff - idle_diff) / total_diff) * 100;

    printf("CPU Usage: %.2f%%\n", usage);
}

void *monitor_cpu_usage(void *arg) {
    while (1) {
        read_cpu_stats(&current_stats);
        if (previous_stats.user > 0) {
            calculate_cpu_usage();
        }
        previous_stats = current_stats;
        sleep(SLEEP_INTERVAL);
    }
    return NULL;
}

int main() {
    pthread_t thread;
    read_cpu_stats(&previous_stats);

    if (pthread_create(&thread, NULL, monitor_cpu_usage, NULL) != 0) {
        perror("Failed to create monitor thread");
        return EXIT_FAILURE;
    }

    pthread_join(thread, NULL);
    return EXIT_SUCCESS;
}