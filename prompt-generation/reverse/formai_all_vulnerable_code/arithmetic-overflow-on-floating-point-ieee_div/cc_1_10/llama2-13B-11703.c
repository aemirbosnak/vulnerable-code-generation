//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/resource.h>
#include <time.h>

#define CPU_USAGE_THRESHOLD 80

void monitor_cpu_usage(void);
void print_usage(float usage);

int main(void)
{
    // Initialize CPU usage monitoring
    monitor_cpu_usage();

    // Loop indefinitely
    while (1)
    {
        // Sleep for a bit to avoid overloading the CPU
        sleep(1);

        // Check CPU usage again
        monitor_cpu_usage();
    }

    return 0;
}

void monitor_cpu_usage(void)
{
    // Get current CPU usage
    struct rusage cpu_usage;
    getrusage(RUSAGE_SELF, &cpu_usage);

    // Calculate CPU usage percentage
    float usage = (float)cpu_usage.ru_utime.tv_sec / (float)cpu_usage.ru_utime.tv_usec;

    // Print CPU usage percentage
    print_usage(usage);

    // Check if CPU usage is above the threshold
    if (usage > CPU_USAGE_THRESHOLD)
    {
        // Print a warning message if CPU usage is too high
        printf("CPU usage too high! (%f%%)\n", usage);
    }
}

void print_usage(float usage)
{
    // Print CPU usage percentage in a satisfied style
    printf("CPU usage: %f%% (%s)\n", usage, (usage > CPU_USAGE_THRESHOLD) ? "😱" : "👍");
}