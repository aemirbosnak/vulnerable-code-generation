//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <time.h>

#define CPU_FREQ 24000000
#define SAMPLE_RATE 100

struct cpu_usage {
    unsigned long long prev_idle;
    unsigned long long prev_total;
    unsigned long long curr_idle;
    unsigned long long curr_total;
};

static struct cpu_usage cpu_usage;

void read_syscall(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    unsigned long long now = ts.tv_sec * 1000000000LL + ts.tv_nsec;
    unsigned long long idle = now - cpu_usage.prev_idle;
    unsigned long long total = now - cpu_usage.prev_total;
    cpu_usage.prev_idle = now;
    cpu_usage.prev_total = total;
    cpu_usage.curr_idle = idle;
    cpu_usage.curr_total = total;
}

void print_usage(void) {
    printf("CPU Usage:\n");
    printf("  Idle: %llu%%\n", (cpu_usage.curr_idle * 100) / CPU_FREQ);
    printf("  Total: %llu%%\n", (cpu_usage.curr_total * 100) / CPU_FREQ);
}

int main(void) {
    clock_t start_time, end_time;
    double duration;

    printf("CPU Usage Monitor\n");

    // Initialize CPU usage structure
    memset(&cpu_usage, 0, sizeof(struct cpu_usage));

    // Start timer
    start_time = clock();

    while (1) {
        // Read current system call
        read_syscall();

        // Calculate duration since last read
        end_time = clock();
        duration = (end_time - start_time) / CLOCKS_PER_SEC;

        // Print usage every SAMPLE_RATE seconds
        if (duration >= SAMPLE_RATE) {
            print_usage();
            start_time = end_time;
        }
    }

    return 0;
}