//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void display_memory_usage() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    long total_memory, free_memory, available_memory, used_memory;
    
    // Read from /proc/meminfo to get memory stats
    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
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
    
    // Calculate used memory
    used_memory = total_memory - free_memory;
    
    // Convert to MB for easier readability
    total_memory /= 1024;
    free_memory /= 1024;
    used_memory /= 1024;
    available_memory /= 1024;

    // Display memory usage
    printf("\033[H\033[J"); // Clear the screen
    printf("Memory Usage Monitor\n");
    printf("----------------------\n");
    printf("Total Memory:     %ld MB\n", total_memory);
    printf("Free Memory:      %ld MB\n", free_memory);
    printf("Used Memory:      %ld MB\n", used_memory);
    printf("Available Memory: %ld MB\n", available_memory);
    
    // Draw a simple bar graph
    int total_bar_length = 50; // Length of bar graph
    int used_bar_length = (int)((float)used_memory / total_memory * total_bar_length);
    int free_bar_length = total_bar_length - used_bar_length;
    
    printf("\nMemory Usage:\n");
    printf("[");
    for (int i = 0; i < used_bar_length; i++) {
        printf("#");
    }
    for (int i = 0; i < free_bar_length; i++) {
        printf(" ");
    }
    printf("] %.2f%% Used\n", ((float)used_memory / total_memory) * 100);
}

int main() {
    while (1) {
        display_memory_usage();
        sleep(1); // Refresh every second
    }
    return 0;
}