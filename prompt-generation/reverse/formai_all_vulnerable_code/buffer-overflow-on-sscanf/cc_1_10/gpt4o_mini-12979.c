//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256
#define SLEEP_INTERVAL 5 // seconds

// Function to read memory usage from /proc/meminfo
void get_memory_usage(double *used_memory, double *total_memory) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    char buffer[BUFFER_SIZE];
    double total_available = 0, free_memory = 0;

    while (fgets(buffer, BUFFER_SIZE, fp)) {
        if (sscanf(buffer, "MemTotal: %lf kB", total_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %lf kB", &free_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemAvailable: %lf kB", &total_available) == 1) {
            continue;
        }
    }
    
    fclose(fp);
    
    *used_memory = *total_memory - free_memory;
    printf("Total Memory: %.2f MB\n", *total_memory / 1024);
    printf("Used Memory: %.2f MB\n", *used_memory / 1024);
    printf("Free Memory: %.2f MB\n", free_memory / 1024);
    printf("Available Memory: %.2f MB\n\n", total_available / 1024);
}

// Function to monitor memory usage asynchronously
void *monitor_memory(void *arg) {
    while (1) {
        double used_memory, total_memory;
        get_memory_usage(&used_memory, &total_memory);
        
        // Sleep for the specified interval
        sleep(SLEEP_INTERVAL);
    }
    return NULL;
}

int main() {
    pthread_t monitor_thread;

    // Create the memory monitoring thread
    if (pthread_create(&monitor_thread, NULL, monitor_memory, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return EXIT_FAILURE;
    }

    printf("Memory usage monitor started. Ctrl+C to stop.\n");

    // Join the thread, shouldn't reach here due to infinite loop in monitor_memory()
    pthread_join(monitor_thread, NULL);

    return EXIT_SUCCESS;
}