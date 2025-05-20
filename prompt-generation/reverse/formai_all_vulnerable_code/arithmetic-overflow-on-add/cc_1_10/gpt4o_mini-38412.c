//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <time.h>

#define SAMPLE_INTERVAL 1 // in seconds
#define MAX_HISTORY 60 // history of CPU usage samples

float cpu_usage_history[MAX_HISTORY];
int history_index = 0;
int running = 1;

// Signal handler for graceful termination
void handle_sigint(int sig) {
    running = 0;
}

// Function to get current CPU usage
float get_cpu_usage() {
    static long prev_idle_time = 0;
    static long prev_total_time = 0;
    FILE *file;
    long user, nice, system, idle, iowait, irq, softirq, steal, total;
    long idle_time, total_time;

    file = fopen("/proc/stat", "r");
    if (!file) {
        perror("fopen");
        return -1;
    }
    
    fscanf(file, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld",
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
    
    fclose(file);

    idle_time = idle + iowait;
    total_time = user + nice + system + idle + iowait + irq + softirq + steal;

    // Calculate CPU usage
    long idle_diff = idle_time - prev_idle_time;
    long total_diff = total_time - prev_total_time;

    float cpu_usage = (1.0 - (float)idle_diff / total_diff) * 100.0;

    prev_idle_time = idle_time;
    prev_total_time = total_time;

    return cpu_usage;
}

// Function to display CPU usage history
void display_cpu_usage_history() {
    printf("----- CPU Usage History -----\n");
    for (int i = 0; i < MAX_HISTORY; i++) {
        if (cpu_usage_history[i] >= 0) {
            printf("Sample %d: %.2f%%\n", i + 1, cpu_usage_history[i]);
        }
    }
    printf("-----------------------------\n");
}

int main() {
    // Set up the signal handler
    signal(SIGINT, handle_sigint);

    printf("CPU Usage Monitor\n");
    printf("Press Ctrl+C to stop monitoring.\n");

    // Main monitoring loop
    while (running) {
        float cpu_usage = get_cpu_usage();
        if (cpu_usage >= 0) {
            cpu_usage_history[history_index] = cpu_usage;
            history_index = (history_index + 1) % MAX_HISTORY;

            // Display current CPU usage
            printf("Current CPU Usage: %.2f%%\n", cpu_usage);
            display_cpu_usage_history();
        }

        sleep(SAMPLE_INTERVAL); // Delay for the specified interval
    }

    // Display final history before exit
    printf("Exiting CPU Usage Monitor...\n");
    display_cpu_usage_history();

    return 0;
}