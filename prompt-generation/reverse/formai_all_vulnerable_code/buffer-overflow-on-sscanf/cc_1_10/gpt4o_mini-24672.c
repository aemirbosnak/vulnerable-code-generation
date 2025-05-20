//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void clear_screen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void read_memory_info(float *total_memory, float *used_memory, float *free_memory) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    float mem_total, mem_free, mem_available;

    // Open the /proc/meminfo file to read memory statistics
    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (sscanf(buffer, "MemTotal: %f kB", &mem_total) == 1) {
            *total_memory = mem_total / 1024; // Convert to MB
        } 
        else if (sscanf(buffer, "MemFree: %f kB", &mem_free) == 1) {
            *free_memory = mem_free / 1024; // Convert to MB
        } 
        else if (sscanf(buffer, "MemAvailable: %f kB", &mem_available) == 1) {
            // Available memory is not necessarily needed here, but can be useful for other metrics.
        }
        if (*total_memory > 0 && *free_memory > 0) {
            break; // We have obtained the needed information.
        }
    }

    fclose(file);
    *used_memory = *total_memory - *free_memory; // Calculate used memory
}

void display_memory_usage(float total_memory, float used_memory, float free_memory) {
    clear_screen();
    printf("\nMemory Usage Monitor\n");
    printf("---------------------\n");
    printf("Total Memory: %.2f MB\n", total_memory);
    printf("Used Memory:  %.2f MB\n", used_memory);
    printf("Free Memory:  %.2f MB\n", free_memory);
    printf("---------------------\n");

    // Visual Representation
    int bar_length = 50;
    int used_length = (int)((used_memory / total_memory) * bar_length);
    int free_length = bar_length - used_length;

    printf("Memory Usage Bar: [");
    for (int i = 0; i < used_length; i++) {
        printf("#");
    }
    for (int i = 0; i < free_length; i++) {
        printf("-");
    }
    printf("] %.2f%% used\n", (used_memory / total_memory) * 100);
}

int main() {
    float total_memory = 0.0, used_memory = 0.0, free_memory = 0.0;

    while (1) {
        read_memory_info(&total_memory, &used_memory, &free_memory);
        display_memory_usage(total_memory, used_memory, free_memory);
        sleep(2); // Refresh every 2 seconds
    }

    return 0;
}