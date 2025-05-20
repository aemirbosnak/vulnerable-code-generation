//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    printf("Starting CPU usage monitor...\n");
    FILE* file = fopen("/proc/stat", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    long int prev_idle_time = 0;
    long int prev_total_time = 0;
    float cpu_usage = 0.0;
    char buffer[BUFFER_SIZE];

    while (true) {
        // Read from /proc/stat file
        fseek(file, 0L, SEEK_SET);
        fgets(buffer, BUFFER_SIZE, file);

        // Extract the CPU usage data
        long int user_time, nice_time, system_time, idle_time, io_wait_time,
                irq_time, soft_irq_time, steal_time, guest_time, guest_nice_time;
        sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
               &user_time, &nice_time, &system_time, &idle_time, &io_wait_time,
               &irq_time, &soft_irq_time, &steal_time, &guest_time, &guest_nice_time);
        long int total_time = user_time + nice_time + system_time + idle_time +
                              io_wait_time + irq_time + soft_irq_time + steal_time;
        long int diff_idle_time = idle_time - prev_idle_time;
        long int diff_total_time = total_time - prev_total_time;
        prev_idle_time = idle_time;
        prev_total_time = total_time;

        // Calculate CPU usage percentage
        cpu_usage = (100.0 * (diff_total_time - diff_idle_time)) / diff_total_time;

        // Print CPU usage percentage
        printf("CPU Usage: %.1f%%\n", cpu_usage);

        // Wait for one second
        sleep(1);
    }

    fclose(file);
    return 0;
}