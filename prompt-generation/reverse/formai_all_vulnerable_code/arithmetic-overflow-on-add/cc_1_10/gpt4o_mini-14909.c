//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define CPU_USAGE_INTERVAL 1
#define NUM_CPU_CORES 4

typedef struct {
    int core_id;
    long user, nice, system, idle, iowait, irq, softirq, steal;
    long total_time;
} CPU_Core;

void init_cpu_core(CPU_Core *core, int id) {
    core->core_id = id;
    core->user = 0;
    core->nice = 0;
    core->system = 0;
    core->idle = 0;
    core->iowait = 0;
    core->irq = 0;
    core->softirq = 0;
    core->steal = 0;
    core->total_time = 0;
}

void read_cpu_usage(CPU_Core *core) {
    char buffer[256];
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        return;
    }

    int cpu_count = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL && cpu_count < NUM_CPU_CORES) {
        if (sscanf(buffer, "cpu%d %ld %ld %ld %ld %ld %ld %ld %ld",
                   &core[cpu_count].core_id,
                   &core[cpu_count].user,
                   &core[cpu_count].nice,
                   &core[cpu_count].system,
                   &core[cpu_count].idle,
                   &core[cpu_count].iowait,
                   &core[cpu_count].irq,
                   &core[cpu_count].softirq,
                   &core[cpu_count].steal) >= 8) {
            core[cpu_count].total_time = core[cpu_count].user + core[cpu_count].nice + core[cpu_count].system + core[cpu_count].idle + core[cpu_count].iowait + core[cpu_count].irq + core[cpu_count].softirq + core[cpu_count].steal;
            cpu_count++;
        }
    }
    fclose(fp);
}

void calculate_and_display_usage(CPU_Core *core_previous, CPU_Core *core_current) {
    for (int i = 0; i < NUM_CPU_CORES; i++) {
        long total_diff = core_current[i].total_time - core_previous[i].total_time;
        long idle_diff = core_current[i].idle - core_previous[i].idle;

        if (total_diff == 0) {
            printf("CPU%d: Usage: N/A\n", core_current[i].core_id);
            continue;
        }

        float usage_percentage = (1.0f - (float)idle_diff / (float)total_diff) * 100.0f;
        printf("CPU%d: Usage: %.2f%%\n", core_current[i].core_id, usage_percentage);
    }
}

void* cpu_monitor(void* arg) {
    CPU_Core core_previous[NUM_CPU_CORES];
    CPU_Core core_current[NUM_CPU_CORES];
    
    for (int i = 0; i < NUM_CPU_CORES; i++) {
        init_cpu_core(&core_previous[i], i);
    }
    
    while (1) {
        read_cpu_usage(core_current);
        if (core_previous[0].total_time != 0) {
            calculate_and_display_usage(core_previous, core_current);
        }
        
        memcpy(core_previous, core_current, sizeof(core_current));
        sleep(CPU_USAGE_INTERVAL);
    }
    return NULL;
}

int main() {
    pthread_t monitor_thread;
    if (pthread_create(&monitor_thread, NULL, cpu_monitor, NULL) != 0) {
        fprintf(stderr, "Failed to create CPU monitor thread\n");
        return EXIT_FAILURE;
    }

    // Let the monitor run indefinitely
    pthread_join(monitor_thread, NULL);
    return EXIT_SUCCESS;
}