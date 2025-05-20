//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CPU_INFO_FILE "/proc/stat"
#define SLEEP_INTERVAL 1
#define MAX_CPU 256

typedef struct {
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
    unsigned long irq;
    unsigned long softirq;
    unsigned long steal;
    unsigned long guest;
    unsigned long guest_nice;
} cpu_times_t;

void read_cpu_times(cpu_times_t *cpu_times) {
    FILE *fp = fopen(CPU_INFO_FILE, "r");
    if (fp == NULL) {
        perror("Failed to open CPU info file");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "cpu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",
           &cpu_times->user,
           &cpu_times->nice,
           &cpu_times->system,
           &cpu_times->idle,
           &cpu_times->iowait,
           &cpu_times->irq,
           &cpu_times->softirq,
           &cpu_times->steal,
           &cpu_times->guest,
           &cpu_times->guest_nice);

    fclose(fp);
}

void compute_cpu_usage(cpu_times_t *old_cpu, cpu_times_t *new_cpu, float *usage) {
    unsigned long old_idle = old_cpu->idle + old_cpu->iowait;
    unsigned long new_idle = new_cpu->idle + new_cpu->iowait;

    unsigned long old_non_idle = old_cpu->user + old_cpu->nice + old_cpu->system + old_cpu->irq + old_cpu->softirq + old_cpu->steal;
    unsigned long new_non_idle = new_cpu->user + new_cpu->nice + new_cpu->system + new_cpu->irq + new_cpu->softirq + new_cpu->steal;

    unsigned long old_total = old_idle + old_non_idle;
    unsigned long new_total = new_idle + new_non_idle;

    unsigned long total_diff = new_total - old_total;
    unsigned long idle_diff = new_idle - old_idle;

    *usage = (1.0 - (float)idle_diff / total_diff) * 100;
}

int main() {
    cpu_times_t old_cpu, new_cpu;
    float cpu_usage;

    printf("Monitoring CPU usage. Press Ctrl+C to stop.\n");

    // Initial read
    read_cpu_times(&old_cpu);

    while (1) {
        sleep(SLEEP_INTERVAL);
        read_cpu_times(&new_cpu);

        compute_cpu_usage(&old_cpu, &new_cpu, &cpu_usage);

        printf("CPU Usage: %.2f%%\n", cpu_usage);

        // Update old_cpu for the next iteration
        old_cpu = new_cpu;
    }

    return 0;
}