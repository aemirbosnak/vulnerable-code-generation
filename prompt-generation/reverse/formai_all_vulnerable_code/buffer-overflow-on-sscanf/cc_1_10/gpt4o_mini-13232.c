//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t keep_running = 1;

void handle_sigint(int sig) {
    keep_running = 0;
}

void display_memory_usage() {
    FILE *fp;
    char buffer[256];
    long total_memory = 0;
    long free_memory = 0;
    long available_memory = 0;
    
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
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
    fclose(fp);
    
    printf("\nMemory Usage Information:\n");
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Available Memory: %ld kB\n", available_memory);
    printf("Used Memory: %ld kB\n", total_memory - free_memory);
    printf("Percentage of Memory Used: %.2f%%\n",
           ((double)(total_memory - free_memory) / total_memory) * 100);
}

int main() {
    signal(SIGINT, handle_sigint);
    
    printf("Active RAM Usage Monitor. Press Ctrl+C to stop.\n");
    
    while (keep_running) {
        display_memory_usage();
        sleep(2); // Refresh every 2 seconds
    }
    
    printf("Exiting RAM Usage Monitor. Goodbye!\n");
    return 0;
}