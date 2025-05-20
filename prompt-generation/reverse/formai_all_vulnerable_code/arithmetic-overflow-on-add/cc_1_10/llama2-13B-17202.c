//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <math.h>

#define MAX_CPU_USAGE 100
#define SAMPLING_RATE 1000

struct cpu_usage {
    unsigned long long int prev_usage;
    unsigned long long int curr_usage;
    unsigned long long int delta_usage;
};

static void init_cpu_usage(struct cpu_usage *cpu) {
    cpu->prev_usage = 0;
    cpu->curr_usage = 0;
    cpu->delta_usage = 0;
}

static void update_cpu_usage(struct cpu_usage *cpu) {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    cpu->curr_usage = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec;
    cpu->delta_usage = cpu->curr_usage - cpu->prev_usage;
    cpu->prev_usage = cpu->curr_usage;
}

static void print_cpu_usage(struct cpu_usage *cpu) {
    printf("CPU Usage: %llu%% (%llu%% delta)\n",
           (cpu->curr_usage / 100), (cpu->delta_usage / 100));
}

int main() {
    struct cpu_usage cpu;
    init_cpu_usage(&cpu);

    while (1) {
        update_cpu_usage(&cpu);
        print_cpu_usage(&cpu);

        // Random sleep time to avoid CPU overload
        usleep(random() % 1000);
    }

    return 0;
}