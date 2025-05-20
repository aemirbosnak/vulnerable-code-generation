//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <pthread.h>

#define CPU_INFO_PATH "/proc/stat"
#define UPDATE_INTERVAL 1 // seconds
#define BUFFER_SIZE 256

typedef struct {
    double user;
    double nice;
    double system;
    double idle;
    double iowait;
    double irq;
    double softirq;
} cpu_usage_t;

cpu_usage_t previous_cpu;
cpu_usage_t current_cpu;

void read_cpu_usage(cpu_usage_t *cpu_usage) {
    FILE *file = fopen(CPU_INFO_PATH, "r");
    if (!file) {
        perror("Could not open CPU info file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    fgets(buffer, sizeof(buffer), file); // Read the first line for overall CPU stats
    sscanf(buffer, "cpu %lf %lf %lf %lf %lf %lf %lf",
           &cpu_usage->user,
           &cpu_usage->nice,
           &cpu_usage->system,
           &cpu_usage->idle,
           &cpu_usage->iowait,
           &cpu_usage->irq,
           &cpu_usage->softirq);

    fclose(file);
}

void calculate_cpu_usage() {
    double total_prev = previous_cpu.user + previous_cpu.nice + previous_cpu.system +
                        previous_cpu.idle + previous_cpu.iowait + previous_cpu.irq +
                        previous_cpu.softirq;

    double total_curr = current_cpu.user + current_cpu.nice + current_cpu.system +
                        current_cpu.idle + current_cpu.iowait + current_cpu.irq +
                        current_cpu.softirq;

    double total_active_prev = total_prev - previous_cpu.idle;
    double total_active_curr = total_curr - current_cpu.idle;

    double active_diff = total_active_curr - total_active_prev;
    double total_diff = total_curr - total_prev;

    double cpu_usage_percent = (active_diff / total_diff) * 100.0;

    printf("CPU Usage: %.2f%%\n", cpu_usage_percent);
}

void *monitor_cpu_usage(void *arg) {
    while (1) {
        previous_cpu = current_cpu;

        read_cpu_usage(&current_cpu);
        calculate_cpu_usage();

        sleep(UPDATE_INTERVAL);
    }
    return NULL;
}

int main() {
    pthread_t monitor_thread;

    // Initial reading
    read_cpu_usage(&current_cpu);
    previous_cpu = current_cpu;

    // Create a thread to monitor CPU usage
    if (pthread_create(&monitor_thread, NULL, monitor_cpu_usage, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Wait for the monitor thread to finish
    pthread_join(monitor_thread, NULL);
    
    return 0;
}