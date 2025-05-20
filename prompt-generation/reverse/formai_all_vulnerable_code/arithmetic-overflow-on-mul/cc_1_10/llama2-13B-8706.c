//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/syscall.h>
#include <unistd.h>

#define CPU_USAGE_THRESHOLD 75 // set to 75%
#define UPDATE_INTERVAL 1000 // update every 1000 milliseconds (1 second)

struct cpu_usage {
    int pid;
    int usage;
};

static void monitor_cpu_usage(struct cpu_usage *cpus) {
    // get the current time
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    long long int now = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;

    // calculate the CPU usage for each process
    for (int i = 0; i < sizeof(cpus) / sizeof(cpus[0]); i++) {
        struct cpu_usage *cpu = &cpus[i];
        long long int start = cpu->usage;
        long long int end = 0;
        if (cpu->pid > 0) {
            // get the current CPU usage
            long long int usage = syscall(SYS_getcpu, CPU_USAGE_THRESHOLD);
            end = usage;
        }
        long long int diff = end - start;
        if (diff > 0) {
            // calculate the CPU usage percentage
            double usage_pct = (double)diff / (double)now * 100;
            // print the CPU usage percentage
            printf("%3.2f%% %d\n", usage_pct, cpu->pid);
        }
    }
}

int main() {
    // create an array of CPU usage structures
    struct cpu_usage cpus[5];
    for (int i = 0; i < sizeof(cpus) / sizeof(cpus[0]); i++) {
        cpus[i].pid = i + 1; // set the PID to the array index
        cpus[i].usage = 0; // set the CPU usage to 0
    }

    // start the CPU usage monitoring loop
    while (1) {
        monitor_cpu_usage(cpus);
        // sleep for the update interval
        usleep(UPDATE_INTERVAL * 1000);
    }
    return 0;
}