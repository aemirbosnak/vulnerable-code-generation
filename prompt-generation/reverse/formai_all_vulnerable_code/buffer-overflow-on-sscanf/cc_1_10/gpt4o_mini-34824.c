//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define PROC_STAT_PATH "/proc/stat"
#define BUFFER_SIZE 256

typedef struct {
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
    unsigned long irq;
    unsigned long softirq;
} CPUInfo;

void get_cpu_times(CPUInfo *cpu_info) {
    FILE *fp = fopen(PROC_STAT_PATH, "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, fp);
    sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu %lu",
           &cpu_info->user,
           &cpu_info->nice,
           &cpu_info->system,
           &cpu_info->idle,
           &cpu_info->iowait,
           &cpu_info->irq,
           &cpu_info->softirq);
    
    fclose(fp);
}

unsigned long calc_cpu_usage(CPUInfo *old_cpu, CPUInfo *new_cpu) {
    unsigned long total_old = old_cpu->user + old_cpu->nice + old_cpu->system + old_cpu->idle + old_cpu->iowait + old_cpu->irq + old_cpu->softirq;
    unsigned long total_new = new_cpu->user + new_cpu->nice + new_cpu->system + new_cpu->idle + new_cpu->iowait + new_cpu->irq + new_cpu->softirq;

    unsigned long idle_time = new_cpu->idle - old_cpu->idle;
    unsigned long total_time = total_new - total_old;

    unsigned long active_time = total_time - idle_time;

    return (total_time == 0) ? 0 : (active_time * 100) / total_time;
}

void display_cpu_usage() {
    CPUInfo old_cpu, new_cpu;

    get_cpu_times(&old_cpu);
    sleep(1); // Wait for 1 second to get a new sample
    get_cpu_times(&new_cpu);

    unsigned long cpu_usage = calc_cpu_usage(&old_cpu, &new_cpu);

    printf("CPU Usage: %lu%%\n", cpu_usage);
}

void print_header() {
    printf("\n=============================\n");
    printf("      CPU Usage Monitor      \n");
    printf("=============================\n");
}

int main() {
    print_header();
    while (1) {
        display_cpu_usage();
        sleep(1); // Refresh rate of 1 second
    }
    return 0;
}