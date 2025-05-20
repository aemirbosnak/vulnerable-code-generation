//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

// Function to get the CPU usage
float get_cpu_usage() {
    static long long prev_total = 0, prev_idle = 0;
    
    FILE* file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Unable to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    long long user, nice, system, idle, iowait, irq, softirq, total;
    
    fscanf(file, "cpu %lld %lld %lld %lld %lld %lld %lld",
           &user, &nice, &system, &idle, &iowait, &irq, &softirq);
    fclose(file);
    
    total = user + nice + system + idle + iowait + irq + softirq;
    
    long long total_diff = total - prev_total;
    long long idle_diff = idle - prev_idle;
    
    prev_total = total;
    prev_idle = idle;
    
    return (1 - (float)idle_diff / total_diff) * 100; // CPU usage percentage
}

// Signal handler for graceful exit
void handle_exit(int sig) {
    printf("\nExiting CPU Usage Monitor...\n");
    exit(0);
}

int main() {
    // Set up signal handler for graceful exit
    signal(SIGINT, handle_exit);
    
    printf("Starting CPU Usage Monitor. Press Ctrl+C to stop.\n");

    while (1) {
        float cpu_usage = get_cpu_usage();
        
        // Display CPU usage
        printf("Current CPU Usage: %.2f%%\r", cpu_usage);
        fflush(stdout);
        
        // Sleep for a second before next measurement
        sleep(1);
    }

    return 0;
}