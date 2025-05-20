//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void get_memory_info(float *mem_free, float *mem_total, float *mem_available) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }
    
    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %f kB", mem_total) == 1) {
            *mem_total /= 1024; // Convert to MB
        } else if (sscanf(line, "MemFree: %f kB", mem_free) == 1) {
            *mem_free /= 1024; // Convert to MB
        } else if (sscanf(line, "MemAvailable: %f kB", mem_available) == 1) {
            *mem_available /= 1024; // Convert to MB
        }
    }
    
    fclose(file);
}

void display_memory_info(float mem_free, float mem_total, float mem_available) {
    printf("\033[H\033[J"); // Clear the terminal
    printf("Memory Usage Monitor\n");
    printf("---------------------\n");
    printf("Total Memory:     %.2f MB\n", mem_total);
    printf("Free Memory:      %.2f MB\n", mem_free);
    printf("Available Memory: %.2f MB\n", mem_available);
    
    float used_memory = mem_total - mem_free;
    float percent_used = (used_memory / mem_total) * 100.0;
    
    printf("Used Memory:      %.2f MB (%.2f%%)\n", used_memory, percent_used);
    printf("---------------------\n");
    printf("Press Ctrl+C to exit.\n");
}

int main() {
    float mem_free, mem_total, mem_available;

    // Continuous monitoring
    while (1) {
        get_memory_info(&mem_free, &mem_total, &mem_available);
        display_memory_info(mem_free, mem_total, mem_available);
        sleep(1); // Wait for 1 second before refreshing
    }

    return EXIT_SUCCESS;
}