//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <time.h>

#define CPU_THRESHOLD 75

struct cpu_usage {
    unsigned long long total;
    unsigned long long idle;
};

static void get_cpu_usage(struct cpu_usage *usage) {
    unsigned long long cur, prev;

    // Get the current and previous CPU usage values
    syscall(SYS_getcpu, &cur);
    prev = usage->total;

    // Calculate the current CPU usage
    usage->total = cur - prev;

    // Update the idle time
    usage->idle = prev - usage->idle;
}

int main(void) {
    struct cpu_usage usage;
    char status[64];

    // Initialize the CPU usage structure
    memset(&usage, 0, sizeof(usage));

    // Set the CPU threshold
    usage.total = CPU_THRESHOLD;

    // Loop indefinitely
    while (1) {
        // Get the current CPU usage
        get_cpu_usage(&usage);

        // Calculate the CPU usage percentage
        double usage_pct = (double)usage.total / (double)usage.idle * 100;

        // Print the CPU usage status
        if (usage_pct > CPU_THRESHOLD) {
            snprintf(status, sizeof(status), "%.2f%% CPU usage", usage_pct);
        } else {
            snprintf(status, sizeof(status), "CPU usage: %u%%", usage_pct);
        }

        // Print the status to the console
        printf("CPU usage: %s\n", status);

        // Sleep for 1 second to avoid overloading the CPU
        usleep(100000);
    }

    return 0;
}