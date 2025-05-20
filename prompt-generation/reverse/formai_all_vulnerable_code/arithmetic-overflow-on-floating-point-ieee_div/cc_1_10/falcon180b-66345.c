//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define MAX_CPU_USAGE_HISTORY 100

struct cpu_usage_history {
    int cpu_percent;
    time_t timestamp;
};

void get_cpu_usage(double *cpu_percent) {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    *cpu_percent = (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0;
    *cpu_percent /= (double)sysconf(_SC_CLK_TCK);
}

void print_cpu_usage_history(struct cpu_usage_history *history, int count) {
    printf("CPU usage history (%d entries):\n", count);
    printf("Timestamp\tCPU usage\n");
    for (int i = 0; i < count; i++) {
        printf("%ld\t%.2f\n", history[i].timestamp, history[i].cpu_percent);
    }
}

int main() {
    struct cpu_usage_history cpu_usage_history[MAX_CPU_USAGE_HISTORY];
    int cpu_usage_history_count = 0;
    double cpu_percent;

    while (1) {
        get_cpu_usage(&cpu_percent);

        if (cpu_usage_history_count >= MAX_CPU_USAGE_HISTORY) {
            cpu_usage_history_count = 0;
        }

        cpu_usage_history[cpu_usage_history_count].cpu_percent = cpu_percent;
        cpu_usage_history[cpu_usage_history_count].timestamp = time(NULL);
        cpu_usage_history_count++;

        printf("Current CPU usage: %.2f%%\n", cpu_percent);

        if (cpu_usage_history_count > 1) {
            print_cpu_usage_history(cpu_usage_history, cpu_usage_history_count);
        }

        sleep(1);
    }

    return 0;
}