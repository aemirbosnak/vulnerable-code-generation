//MISTRAL-7B DATASET v1.0 Category: CPU usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>

#define CPU_PERCENTAGE_INCREMENT 0.1
#define MIN_CPU_USAGE 5
#define MAX_CPU_USAGE 100
#define PRINT_INTERVAL 1000 //ms

typedef struct {
    int pid;
    float cpu_usage;
    struct timespec next_print_time;
} cpu_monitor_t;

cpu_monitor_t *cpu_monitors = NULL;
int num_monitors = 0;

void print_cpu_usage(cpu_monitor_t *monitor) {
    struct sysinfo info;
    long long total_usage = 0;
    long long total_runtime = 0;

    if (sysconf(_SC_CLK_TCK) != -1) {
        total_runtime = sysconf(_SC_CLK_TCK) * monitor->cpu_usage / 100;
    }

    if (sysconf(_SC_PAGE_SIZE) != -1) {
        total_usage = sysconf(_SC_PAGE_SIZE) * sysconf(_SC_PHYS_PAGES) / (1024 * 1024);
    }

    if (total_runtime > 0 && total_usage > 0) {
        monitor->cpu_usage += CPU_PERCENTAGE_INCREMENT;
        if (monitor->cpu_usage > MAX_CPU_USAGE) {
            monitor->cpu_usage = MAX_CPU_USAGE;
        }
        float cpu_percentage = (monitor->cpu_usage * 100.0 / total_usage);
        printf("\033[1;31m[!] Process %d: %.2f%% CPU usage\033[0m\n", monitor->pid, cpu_percentage);
    }

    if (nanosleep((const struct timespec*)&monitor->next_print_time, NULL) < 0) {
        perror("nanosleep");
        exit(EXIT_FAILURE);
    }
}

void add_monitor(int pid) {
    cpu_monitor_t *new_monitor = (cpu_monitor_t *) malloc(sizeof(cpu_monitor_t));
    new_monitor->pid = pid;
    new_monitor->cpu_usage = MIN_CPU_USAGE;
    clock_gettime(CLOCK_MONOTONIC, &new_monitor->next_print_time);
    new_monitor->next_print_time.tv_sec += PRINT_INTERVAL / 1000;
    new_monitor->next_print_time.tv_nsec += PRINT_INTERVAL % 1000 * 1000000;

    cpu_monitors = (cpu_monitor_t *)realloc(cpu_monitors, sizeof(cpu_monitor_t) * (num_monitors + 1));
    cpu_monitors[num_monitors++] = *new_monitor;
}

int main() {
    pid_t pid;

    while (1) {
        printf("\033[1;32m[*] Enter PID to monitor: \033[0m");
        scanf("%d", &pid);

        add_monitor(pid);
    }

    return EXIT_SUCCESS;
}