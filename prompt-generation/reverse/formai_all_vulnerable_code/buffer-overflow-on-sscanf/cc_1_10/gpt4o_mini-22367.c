//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 256

void display_memory_usage() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    long total_memory = 0, free_memory = 0, available_memory = 0;

    file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemAvailable: %ld kB", &available_memory) == 1) {
            continue;
        }
    }
    
    fclose(file);

    long used_memory = total_memory - free_memory;
    long memory_percentage = (used_memory * 100) / total_memory;

    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Used Memory: %ld kB\n", used_memory);
    printf("Available Memory: %ld kB\n", available_memory);
    printf("Memory Usage Percentage: %ld%%\n", memory_percentage);
}

int main() {
    bool keep_running = true;
    int update_interval = 5; // seconds

    printf("╔════════════════════════════════════════════════════╗\n");
    printf("║           RAM Usage Monitor (Linux)                ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");

    while (keep_running) {
        display_memory_usage();
        printf("\nUpdating in %d seconds...\n", update_interval);
        sleep(update_interval);

        // Optional: Check for user input to quit
        if (access("/tmp/stop_monitor", F_OK) == 0) {
            keep_running = false;
            printf("Stopping RAM usage monitor...\n");
        }
    }

    return 0;
}