//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>

#define CPU_FREQ 24000000
#define SAMPLING_RATE 1000

struct cpu_usage {
    int prev_idle;
    int prev_total;
    int cur_idle;
    int cur_total;
};

static inline void init_cpu_usage(struct cpu_usage *cpu) {
    cpu->prev_idle = 0;
    cpu->prev_total = 0;
    cpu->cur_idle = 0;
    cpu->cur_total = 0;
}

static inline void update_cpu_usage(struct cpu_usage *cpu) {
    cpu->cur_idle = syscall(SYS_getcpu) & 1;
    cpu->cur_total = syscall(SYS_getcpu) & ~1;
    cpu->cur_total += cpu->prev_total;
    cpu->cur_idle += cpu->prev_idle;
    cpu->prev_idle = cpu->cur_idle;
    cpu->prev_total = cpu->cur_total;
}

static inline void print_cpu_usage(struct cpu_usage *cpu) {
    printf("CPU Usage: Idle=%d, Total=%d\n", cpu->cur_idle, cpu->cur_total);
}

int main(void) {
    struct cpu_usage cpu;
    init_cpu_usage(&cpu);

    while (1) {
        update_cpu_usage(&cpu);
        print_cpu_usage(&cpu);

        usleep(SAMPLING_RATE);
    }

    return 0;
}