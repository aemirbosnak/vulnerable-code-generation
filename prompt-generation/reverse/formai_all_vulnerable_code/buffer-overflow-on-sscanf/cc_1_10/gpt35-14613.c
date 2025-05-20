//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 128

int main()
{
    // Declare variables
    FILE* fp;
    char buffer[BUFFER_SIZE];
    char cpu[BUFFER_SIZE];
    int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    float total_cpu_time_prev = 0, idle_cpu_time_prev = 0, total_cpu_time_now = 0, idle_cpu_time_now = 0, cpu_usage;

    // Open CPU info file
    fp = fopen("/proc/stat", "r");
    if(fp == NULL)
    {
        printf("Error: Could not open file: /proc/stat\n");
        exit(1);
    }

    // Read initial CPU info
    fgets(buffer, BUFFER_SIZE, fp);
    sscanf(buffer, "%s %d %d %d %d %d %d %d %d %d %d", cpu, &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    total_cpu_time_prev = user + nice + system + idle + iowait + irq + softirq + steal;
    idle_cpu_time_prev = idle;

    // Loop to monitor CPU usage every 1 second
    while(1)
    {
        // Wait 1 second
        sleep(1);

        // Rewind to beginning of file
        rewind(fp);

        // Read current CPU info
        fgets(buffer, BUFFER_SIZE, fp);
        sscanf(buffer, "%s %d %d %d %d %d %d %d %d %d %d", cpu, &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
        total_cpu_time_now = user + nice + system + idle + iowait + irq + softirq + steal;
        idle_cpu_time_now = idle;

        // Calculate CPU usage
        float total_diff = total_cpu_time_now - total_cpu_time_prev;
        float idle_diff = idle_cpu_time_now - idle_cpu_time_prev;
        cpu_usage = 100.0 * (total_diff - idle_diff) / total_diff;

        // Print CPU usage
        printf("CPU usage: %.2f%%\n", cpu_usage);

        // Store current CPU info for next iteration
        total_cpu_time_prev = total_cpu_time_now;
        idle_cpu_time_prev = idle_cpu_time_now;
    }

    // Close file
    fclose(fp);

    return 0;
}