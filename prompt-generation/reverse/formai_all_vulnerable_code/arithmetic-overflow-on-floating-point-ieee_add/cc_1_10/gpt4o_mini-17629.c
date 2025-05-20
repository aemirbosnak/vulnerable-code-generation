//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <pthread.h>

// Global variable to control the monitoring
volatile sig_atomic_t keep_monitoring = 1;

// Function to handle termination signal
void terminate_monitoring(int signum) {
    keep_monitoring = 0;
}

// Struct to store CPU usage data
typedef struct {
    long double idle_time;
    long double total_time;
} cpu_data_t;

// Function to read the CPU usage from the /proc/stat file
cpu_data_t read_cpu_usage() {
    FILE *file;
    cpu_data_t data = {0.0, 0.0};
    long double user_time, nice_time, system_time, idle_time, iowait_time, irq_time, softirq_time, total_time;

    // Open the /proc/stat file to read CPU usage
    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line corresponding to CPU usage
    fscanf(file, "cpu %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf",
           &user_time, &nice_time, &system_time, &idle_time, &iowait_time, &irq_time, &softirq_time);
    
    // Calculate total time
    total_time = user_time + nice_time + system_time + idle_time + iowait_time + irq_time + softirq_time;

    // Assign values to the data struct
    data.idle_time = idle_time;
    data.total_time = total_time;

    fclose(file);
    return data;
}

// Function to monitor CPU usage
void* cpu_monitor(void* arg) {
    cpu_data_t previous_data = read_cpu_usage();
    cpu_data_t current_data;

    while (keep_monitoring) {
        sleep(1); // Sleep for 1 second
        current_data = read_cpu_usage();

        // Calculate CPU usage percentage
        long double idle_delta = current_data.idle_time - previous_data.idle_time;
        long double total_delta = current_data.total_time - previous_data.total_time;
        long double cpu_usage = 100.0 * (1.0 - (idle_delta / total_delta));

        // Display CPU usage
        printf("Current CPU Usage: %.2Lf%%\n", cpu_usage);
        
        // Update previous data for the next iteration
        previous_data = current_data;
    }
    return NULL;
}

// Main function
int main() {
    // Register signal handler for graceful exit
    signal(SIGINT, terminate_monitoring);

    pthread_t monitor_thread;

    // Create a thread for CPU monitoring
    if (pthread_create(&monitor_thread, NULL, cpu_monitor, NULL) != 0) {
        perror("Failed to create monitoring thread");
        return EXIT_FAILURE;
    }

    // Wait for the monitoring thread to finish
    pthread_join(monitor_thread, NULL);

    printf("CPU monitoring stopped. Exiting...\n");
    return EXIT_SUCCESS;
}