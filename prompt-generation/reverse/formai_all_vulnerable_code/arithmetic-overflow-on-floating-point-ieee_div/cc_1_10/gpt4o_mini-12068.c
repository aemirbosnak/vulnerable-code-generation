//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <pthread.h>
#include <signal.h>

volatile int running = 1;

void handle_sigint(int sig) {
    running = 0; // Set running to false to exit the loop
}

void *cpu_usage_monitor(void *arg) {
    FILE *fp;
    char buffer[1024];
    
    while (running) {
        // Open the file containing the CPU stats
        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            perror("Failed to open /proc/stat");
            return NULL;
        }

        // Read the first line of /proc/stat
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            // Parse the CPU usage stats from the line
            unsigned long total_user, total_user_nice, total_system, total_idle, total_iowait, total_steal, total_guest, total_guest_nice;
            sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu %lu %lu", 
                   &total_user, &total_user_nice, &total_system, &total_idle, 
                   &total_iowait, &total_steal, &total_guest, &total_guest_nice);

            // Calculate total CPU time
            unsigned long total_cpu_time = total_user + total_user_nice + total_system + total_idle + total_iowait + total_steal;

            // Calculate idle CPU time
            unsigned long idle_cpu_time = total_idle + total_iowait;

            // Calculate CPU usage percentage
            double cpu_usage = 100 * ((double)(total_cpu_time - idle_cpu_time) / total_cpu_time);
            printf("CPU Usage: %.2f%%\n", cpu_usage);
        }

        fclose(fp); // Close the file
        sleep(1); // Wait for a second before checking again
    }

    return NULL;
}

int main(void) {
    pthread_t monitor_thread;
    struct sigaction sigIntHandler;

    // Set up signal handling to gracefully exit the program
    sigIntHandler.sa_handler = handle_sigint;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);

    // Create a thread for monitoring CPU usage
    if (pthread_create(&monitor_thread, NULL, cpu_usage_monitor, NULL) != 0) {
        perror("Failed to create monitor thread");
        return 1;
    }

    // Main loop to keep the main thread running
    while (running) {
        // Optionally: other code can run here
        pause(); // Wait for signals
    }

    // Join the thread before exiting
    pthread_join(monitor_thread, NULL);
    printf("Exiting CPU usage monitor.\n");
    return 0;
}