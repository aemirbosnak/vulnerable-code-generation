//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>

#define CPU_FREQ 24000000 // CPU frequency in Hz
#define SAMPLES 10000 // number of samples to take
#define DELAY 1000 // delay between samples in ms

// define the CPU usage structure
typedef struct {
    unsigned long long prev_total;
    unsigned long long cur_total;
    unsigned long long prev_user;
    unsigned long long cur_user;
    unsigned long long prev_sys;
    unsigned long long cur_sys;
} cpu_usage_t;

// function to get the current CPU usage
void get_cpu_usage(cpu_usage_t *usage) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    unsigned long long cur_cpu_user = (ts.tv_sec * 1000000000) + ts.tv_nsec;
    unsigned long long cur_cpu_sys = (ts.tv_sec * 1000000000) + ts.tv_nsec;

    // calculate the current CPU usage
    usage->cur_total = cur_cpu_user + cur_cpu_sys;
    usage->cur_user = cur_cpu_user;
    usage->cur_sys = cur_cpu_sys;

    // calculate the delta between current and previous values
    usage->prev_total = usage->cur_total - usage->prev_total;
    usage->prev_user = usage->cur_user - usage->prev_user;
    usage->prev_sys = usage->cur_sys - usage->prev_sys;
}

// function to print the CPU usage
void print_cpu_usage(cpu_usage_t *usage) {
    printf("CPU Usage:\n");
    printf("  Total: %llu\n", usage->cur_total);
    printf("  User: %llu\n", usage->cur_user);
    printf("  Sys: %llu\n", usage->cur_sys);
    printf("  delta: %llu\n", usage->prev_total - usage->cur_total);
    printf("  User delta: %llu\n", usage->prev_user - usage->cur_user);
    printf("  Sys delta: %llu\n", usage->prev_sys - usage->cur_sys);
}

int main() {
    // initialize the CPU usage structure
    cpu_usage_t usage;
    usage.prev_total = 0;
    usage.prev_user = 0;
    usage.prev_sys = 0;

    // start the CPU usage monitoring loop
    for (int i = 0; i < SAMPLES; i++) {
        get_cpu_usage(&usage);
        usleep(DELAY);
    }

    // print the final CPU usage
    print_cpu_usage(&usage);

    return 0;
}