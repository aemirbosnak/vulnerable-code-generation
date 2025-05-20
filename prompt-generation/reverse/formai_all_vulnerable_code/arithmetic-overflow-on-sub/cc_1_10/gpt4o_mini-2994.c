//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <pthread.h>

#define BUFFER_SIZE 256

volatile sig_atomic_t keep_running = 1;

void handle_sigint(int sig) {
    keep_running = 0;
}

void* memory_monitor(void* arg) {
    struct sysinfo info;
    
    while (keep_running) {
        if (sysinfo(&info) == 0) {
            long total_ram = info.totalram;
            long free_ram = info.freeram;
            long used_ram = total_ram - free_ram;

            // Convert bytes to megabytes
            total_ram /= (1024 * 1024);
            free_ram /= (1024 * 1024);
            used_ram /= (1024 * 1024);

            printf("Total RAM: %ld MB, Used RAM: %ld MB, Free RAM: %ld MB\n", total_ram, used_ram, free_ram);
        } else {
            perror("sysinfo");
        }
        sleep(1); // Sleep for 1 second before next update
    }
    return NULL;
}

void display_instructions() {
    printf("Welcome to the RAM Usage Monitor!\n");
    printf("Press Ctrl+C to stop the monitoring.\n");
}

int main() {
    // Handle SIGINT to gracefully exit
    signal(SIGINT, handle_sigint);

    // Display instructions to the user
    display_instructions();

    // Create a separate thread for monitoring memory usage
    pthread_t monitor_thread;

    if (pthread_create(&monitor_thread, NULL, memory_monitor, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Main thread can perform other tasks or wait for input if needed
    while (keep_running) {
        // Main thread can do other work or just wait
        pause(); // Wait for signals
    }

    // Clean up and join the monitor thread
    pthread_join(monitor_thread, NULL);
    
    printf("RAM monitoring stopped. Goodbye!\n");
    return 0;
}