//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <time.h>

#define CPU_USAGE_UPDATE_INTERVAL 1000 // Update CPU usage every 1 second

// Structure to store CPU usage data
typedef struct {
    int usage; // Current CPU usage
    int previous; // Previous CPU usage
} cpu_usage_t;

// Function to get current CPU usage
static inline int get_cpu_usage(void) {
    // Get current CPU usage using syscall
    int usage = syscall(SYS_getcpu) & 0xFFFF;
    return usage;
}

// Function to update CPU usage data
static inline void update_cpu_usage(cpu_usage_t *usage) {
    // Get current CPU usage
    int current = get_cpu_usage();

    // Calculate delta CPU usage
    int delta = current - usage->previous;

    // Update previous CPU usage
    usage->previous = current;

    // Print CPU usage change
    if (delta > 0) {
        printf("CPU usage increased to %d%%\n", delta * 100 / usage->previous);
    } else if (delta < 0) {
        printf("CPU usage decreased to %d%%\n", -delta * 100 / usage->previous);
    }
}

// Main program loop
int main() {
    // Create CPU usage data structure
    cpu_usage_t usage;

    // Initialize CPU usage to 0
    usage.usage = 0;
    usage.previous = 0;

    // Start updating CPU usage every interval
    clock_t start = clock();
    while (1) {
        // Get current CPU usage
        int current = get_cpu_usage();

        // Update CPU usage data
        update_cpu_usage(&usage);

        // Check if interval has elapsed
        if (clock() - start >= CPU_USAGE_UPDATE_INTERVAL) {
            // Print current CPU usage
            printf("Current CPU usage: %d%%\n", current * 100 / usage.previous);

            // Reset interval start time
            start = clock();
        }
    }

    return 0;
}