//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>

#define MEMORY_INFO_FILE "/proc/meminfo"
#define SLEEP_INTERVAL 5

volatile sig_atomic_t keep_running = 1;

void handle_signal(int signal) {
    keep_running = 0;
}

void print_memory_usage() {
    FILE *file = fopen(MEMORY_INFO_FILE, "r");
    if (file == NULL) {
        perror("Could not open memory info file");
        return;
    }

    char buffer[256];
    int total_memory = 0, free_memory = 0, available_memory = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        if (sscanf(buffer, "MemTotal: %d kB", &total_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %d kB", &free_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemAvailable: %d kB", &available_memory) == 1) {
            continue;
        }
    }
    
    fclose(file);

    if (total_memory > 0) {
        printf("Total Memory: %d kB\n", total_memory);
        printf("Free Memory: %d kB\n", free_memory);
        printf("Available Memory: %d kB\n", available_memory);
        float used_memory = ((float)(total_memory - free_memory) / total_memory) * 100;
        printf("Used Memory: %.2f%%\n", used_memory);
        printf("------------------------------------------------\n");
    } else {
        printf("Error reading memory information.\n");
    }
}

void* monitor_memory(void* arg) {
    while (keep_running) {
        print_memory_usage();
        sleep(SLEEP_INTERVAL);
    }
    return NULL;
}

int main() {
    // Setup signal handling for graceful termination
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    pthread_t monitor_thread;

    // Create a new thread to monitor memory usage asynchronously
    if (pthread_create(&monitor_thread, NULL, monitor_memory, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return EXIT_FAILURE;
    }

    // Main thread can perform other tasks while the memory monitor runs
    while (keep_running) {
        // Simulate other processing
        printf("Main thread is working...\n");
        // Sleep for a moment to simulate work being done
        sleep(3);
    }

    // Wait for monitor thread to finish
    pthread_join(monitor_thread, NULL);
    printf("Memory monitoring stopped.\n");

    return EXIT_SUCCESS;
}