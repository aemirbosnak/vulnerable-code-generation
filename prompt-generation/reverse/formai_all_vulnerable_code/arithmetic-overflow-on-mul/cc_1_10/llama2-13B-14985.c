//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/syscall.h>
#include <asm/unistd.h>

#define CPU_USAGE_SAMPLING_RATE 1000
#define CPU_USAGE_BUFFER_SIZE 1024

struct cpu_usage {
    unsigned long long total_time;
    unsigned long long idle_time;
    unsigned long long user_time;
    unsigned long long nice_time;
    unsigned long long system_time;
    unsigned long long wait_time;
};

static volatile struct cpu_usage cpu_usage;

void init_cpu_usage() {
    memset(&cpu_usage, 0, sizeof(struct cpu_usage));
}

void sample_cpu_usage() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    unsigned long long now = ts.tv_sec * 1000000000LL + ts.tv_nsec;
    unsigned long long delta = now - cpu_usage.total_time;
    cpu_usage.total_time = now;
    cpu_usage.idle_time += delta;
    cpu_usage.user_time += delta;
    cpu_usage.nice_time += delta;
    cpu_usage.system_time += delta;
    cpu_usage.wait_time += delta;
}

void print_cpu_usage() {
    printf("CPU Usage:\n");
    printf("  Total: %llu ms\n", cpu_usage.total_time);
    printf("  Idle: %llu ms\n", cpu_usage.idle_time);
    printf("  User: %llu ms\n", cpu_usage.user_time);
    printf("  Nice: %llu ms\n", cpu_usage.nice_time);
    printf("  System: %llu ms\n", cpu_usage.system_time);
    printf("  Wait: %llu ms\n", cpu_usage.wait_time);
}

int main() {
    init_cpu_usage();

    while (1) {
        sample_cpu_usage();
        usleep(CPU_USAGE_SAMPLING_RATE * 1000);
    }

    return 0;
}