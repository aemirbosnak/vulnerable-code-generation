//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to calculate CPU usage
float calculate_cpu_usage(long long *prev_idle, long long *prev_total) {
    long long idle, total;
    long long active, total_time;
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("fopen");
        return -1;
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    // Parsing the first line of /proc/stat to get CPU times
    char cpu[5];
    sscanf(buffer, "%s %lld %lld %lld %lld %lld %lld %lld %lld", cpu, &total_time, &idle, &active, &total, &total_time, &total_time, &total_time, &total_time);

    // Calculate the total and idle times
    total = total_time + active + idle;
    
    // Calculate the differences with previous values
    long long idle_diff = idle - *prev_idle;
    long long total_diff = total - *prev_total;

    // Update previous values
    *prev_idle = idle;
    *prev_total = total;
    
    return (float)(1.0 - (float)idle_diff / (float)total_diff) * 100.0;
}

int main() {
    // Initialize previous idle and total values
    long long prev_idle = 0;
    long long prev_total = 0;

    // User prompt for how many seconds to monitor CPU usage
    int duration;
    printf("Enter the duration (in seconds) to monitor CPU usage: ");
    scanf("%d", &duration);

    // Monitor CPU usage for the specified duration
    while (duration > 0) {
        float cpu_usage = calculate_cpu_usage(&prev_idle, &prev_total);
        if (cpu_usage < 0) {
            fprintf(stderr, "Error calculating CPU usage\n");
            return EXIT_FAILURE;
        }
        
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        // Sleep for one second
        sleep(1);
        duration--;
    }

    return EXIT_SUCCESS;
}