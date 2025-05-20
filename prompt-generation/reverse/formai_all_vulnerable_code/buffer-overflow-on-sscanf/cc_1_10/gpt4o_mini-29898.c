//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define INTERVAL 1  // Update interval in seconds

void* monitor_cpu_usage(void* arg);
void get_cpu_usage(double* idle_time, double* total_time);
void* log_cpu_usage(void* arg); // Placeholder for future enhancements

int main() {
    pthread_t cpu_thread;
    pthread_t log_thread;

    // Create a thread to monitor CPU usage
    if (pthread_create(&cpu_thread, NULL, monitor_cpu_usage, NULL) != 0) {
        fprintf(stderr, "Error creating CPU monitoring thread.\n");
        return 1;
    }

    // Create a thread for logging CPU usage (placeholder)
    if (pthread_create(&log_thread, NULL, log_cpu_usage, NULL) != 0) {
        fprintf(stderr, "Error creating log thread.\n");
        return 1;
    }

    // Wait for the CPU monitoring thread to finish
    pthread_join(cpu_thread, NULL);
    pthread_cancel(log_thread); // Cancel log thread if not needed
    pthread_join(log_thread, NULL); // Waiting for log thread to finish

    return 0;
}

void* monitor_cpu_usage(void* arg) {
    while (1) {
        double idle_time, total_time;
        
        get_cpu_usage(&idle_time, &total_time);
        
        double usage = 100.0 * (1 - (idle_time / total_time));
        
        printf("Current CPU Usage: %.2f%%\n", usage);
        fflush(stdout);  // Ensure output is displayed immediately

        sleep(INTERVAL);
    }
    return NULL;
}

void get_cpu_usage(double* idle_time, double* total_time) {
    FILE* file = fopen("/proc/stat", "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open /proc/stat.\n");
        exit(1);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);

    // Retrieve CPU times
    long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

    total_time[0] = user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;
    *idle_time = idle;
}

void* log_cpu_usage(void* arg) {
    // A placeholder function for future logging capabilities
    while (1) {
        // Future logging implementation could go here
        sleep(INTERVAL);
    }
    return NULL;
}