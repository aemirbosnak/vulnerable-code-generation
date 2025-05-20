//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

// Constants defining the nature of our new world
#define MAX_CPU_USAGE 100
#define WARNING_THRESHOLD 80
#define REPORT_INTERVAL 1

// Global variables to store the state of our CPU monitor
volatile sig_atomic_t stop_monitoring = 0;

// Signal handler to gracefully exit the monitoring
void handle_sigint(int sig) {
    stop_monitoring = 1;
}

// Function to read CPU usage from /proc/stat
float get_cpu_usage() {
    FILE *fp;
    char buffer[1024];
    long idle_time, total_time;
    long user_time, nice_time, system_time, irq_time, softirq_time, steal_time, guest_time;

    fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld",
           &user_time, &nice_time, &system_time, &idle_time,
           &irq_time, &softirq_time, &steal_time, &guest_time);

    total_time = user_time + nice_time + system_time + idle_time + 
                 irq_time + softirq_time + steal_time + guest_time;

    // Calculating the CPU usage percentage
    float cpu_usage = 100.0 * (total_time - idle_time) / total_time;
    return cpu_usage;
}

// Function to display the monitored output
void display_cpu_usage(float usage) {
    if (usage >= WARNING_THRESHOLD && usage < MAX_CPU_USAGE) {
        printf("Warning! CPU usage at %.2f%%.\n", usage);
    } else if (usage >= MAX_CPU_USAGE) {
        printf("Danger! CPU usage exceeds limits at %.2f%%!\n", usage);
    } else {
        printf("CPU usage at a safe level: %.2f%%.\n", usage);
    }
}

// Main function to run the CPU monitor
int main() {
    printf("=== CPU Usage Monitor: The Last Bastion ===\n");
    printf("In a world where machines roam free, we monitor the heart of our makeshift systems.\n");

    // Register the SIGINT handler for graceful shutdown
    signal(SIGINT, handle_sigint);

    // Main monitoring loop
    while (!stop_monitoring) {
        float cpu_usage = get_cpu_usage();
        display_cpu_usage(cpu_usage);
        sleep(REPORT_INTERVAL);
    }

    printf("\nShutting down the CPU monitor. May the remnants of technology guide you!\n");
    return 0;
}