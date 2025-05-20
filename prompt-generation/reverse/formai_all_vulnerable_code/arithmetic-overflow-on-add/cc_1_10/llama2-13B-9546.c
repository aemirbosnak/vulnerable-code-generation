//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <time.h>

#define MAX_CPU_USAGE 100
#define SAMPLING_RATE 1000

struct cpu_usage {
    unsigned long long total_time;
    unsigned long long idle_time;
    unsigned long long non_idle_time;
};

static void start_timer(struct cpu_usage *usage) {
    usage->total_time = 0;
    usage->idle_time = 0;
    usage->non_idle_time = 0;
}

static void stop_timer(struct cpu_usage *usage) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    usage->total_time = ts.tv_sec * 1000000000 + ts.tv_nsec;
}

static void update_usage(struct cpu_usage *usage) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    unsigned long long now = ts.tv_sec * 1000000000 + ts.tv_nsec;
    usage->idle_time += (now - usage->total_time) / SAMPLING_RATE;
    usage->non_idle_time += (now - usage->total_time) % SAMPLING_RATE;
    usage->total_time = now;
}

static void print_usage(struct cpu_usage *usage) {
    printf("CPU Usage: %3.2f%%\n", (float)usage->non_idle_time / SAMPLING_RATE * 100);
}

int main() {
    struct cpu_usage usage;
    start_timer(&usage);

    while (1) {
        update_usage(&usage);
        print_usage(&usage);

        // Simulate some CPU-intensive work here
        for (int i = 0; i < 1000; i++) {
            double x = 0;
            double y = 0;
            double z = 0;
            for (int j = 0; j < 1000; j++) {
                x += j * j;
                y += j * j * j;
                z += j * j * j * j;
            }
        }

        // Sleep for a bit to avoid overloading the CPU
        sleep(1);
    }

    return 0;
}