//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

void get_cpu_usage(double *idle_time, double *total_time) {
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);

    // Parse the CPU metrics
    long user, nice, system, idle, iowait, irq, softirq, steal;
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld",
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);

    // Calculate total time
    long total = user + nice + system + idle + iowait + irq + softirq + steal;

    *idle_time = (double)idle;
    *total_time = (double)total;
}

void display_usage(double prev_idle, double prev_total) {
    double idle, total;
    get_cpu_usage(&idle, &total);

    double idle_delta = idle - prev_idle;
    double total_delta = total - prev_total;

    double cpu_usage = 100.0 * (total_delta - idle_delta) / total_delta;

    // Print CPU usage
    printf("\rCPU Usage: %.2f%%   ", cpu_usage);
    fflush(stdout);
}

int main() {
    // Create a playful header
    printf("\n✨ Welcome to the C CPU Usage Monitor! 🎉\n");
    printf("This program will keep you updated with real-time CPU usage.\n");
    printf("Press Ctrl+C to exit at any time. Enjoy! 🚀\n\n");

    double prev_idle = 0, prev_total = 0;
    
    // Start the monitoring loop
    while (1) {
        display_usage(prev_idle, prev_total);

        // Update previous values
        get_cpu_usage(&prev_idle, &prev_total);

        // Sleep for 1 second before the next update
        usleep(1000000);
    }

    return 0;
}