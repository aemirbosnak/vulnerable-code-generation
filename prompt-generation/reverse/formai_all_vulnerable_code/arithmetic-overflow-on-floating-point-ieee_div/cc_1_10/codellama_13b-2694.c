//Code Llama-13B DATASET v1.0 Category: CPU usage monitor ; Style: secure
// A secure and efficient CPU usage monitor program in C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/times.h>
#include <time.h>
#include <string.h>

// Function to get CPU usage
float get_cpu_usage(void) {
    struct tms t;
    clock_t total_time, total_time_old;
    float cpu_usage;

    // Get current time
    total_time = times(&t);

    // Calculate CPU usage
    cpu_usage = ((float)t.tms_utime + (float)t.tms_stime) / (float)total_time;

    // Return CPU usage
    return cpu_usage;
}

// Function to print CPU usage
void print_cpu_usage(float cpu_usage) {
    printf("CPU usage: %.2f%%\n", cpu_usage * 100);
}

int main(void) {
    // Initialize CPU usage
    float cpu_usage = get_cpu_usage();

    // Loop and print CPU usage every second
    while (1) {
        // Get current CPU usage
        float cpu_usage_new = get_cpu_usage();

        // Calculate CPU usage difference
        float cpu_usage_diff = cpu_usage_new - cpu_usage;

        // Print CPU usage
        print_cpu_usage(cpu_usage_diff);

        // Update CPU usage
        cpu_usage = cpu_usage_new;

        // Sleep for one second
        sleep(1);
    }

    // Return success
    return 0;
}