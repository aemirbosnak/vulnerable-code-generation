//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void get_cpu_usage(float *cpu_usage) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    long idle_time, total_time, prev_total_time, prev_idle_time;

    // Open the /proc/stat file
    file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Could not open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line, which starts with "cpu"
    fgets(buffer, BUFFER_SIZE, file);
    fclose(file);

    // Parse the CPU times
    long user_time, nice_time, system_time, irq_time, softirq_time, steal_time, guest_time, guest_nice_time;
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld",
           &user_time, &nice_time, &system_time, &idle_time,
           &irq_time, &softirq_time, &steal_time, &guest_time);

    // Calculate total and idle time
    total_time = user_time + nice_time + system_time + idle_time +
                 irq_time + softirq_time + steal_time + guest_time;

    // Compute CPU usage
    if (prev_total_time > 0) {
        long total_diff = total_time - prev_total_time;
        long idle_diff = idle_time - prev_idle_time;
        *cpu_usage = (1.0 - (float)idle_diff / total_diff) * 100.0;
    } else {
        *cpu_usage = 0.0; // Initial value
    }

    // Store previous values for next call
    prev_total_time = total_time;
    prev_idle_time = idle_time;
}

int main() {
    float cpu_usage;
    
    printf("Welcome to the Simple CPU Usage Monitor!\n");
    printf("I'll be showing you the CPU usage every second. Press Ctrl+C to quit.\n\n");

    while (1) {
        get_cpu_usage(&cpu_usage);
        printf("Current CPU Usage: %.2f%%\n", cpu_usage);
        sleep(1); // Wait for one second before the next reading
    }

    return 0;
}