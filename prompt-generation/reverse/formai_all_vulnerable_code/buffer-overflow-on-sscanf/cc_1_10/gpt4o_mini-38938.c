//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void display_ram_usage() {
    FILE *fp;
    char line[256];
    long total_memory, free_memory, available_memory;

    // Open the /proc/meminfo file to read memory information
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read relevant memory information
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %ld kB", &total_memory) == 1) {
            continue;
        }
        if (sscanf(line, "MemFree: %ld kB", &free_memory) == 1) {
            continue;
        }
        if (sscanf(line, "MemAvailable: %ld kB", &available_memory) == 1) {
            break;
        }
    }

    fclose(fp);

    // Calculate used memory
    long used_memory = total_memory - free_memory;

    // Display memory usage
    printf("\nMemory Usage:\n");
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Available Memory: %ld kB\n", available_memory);
    printf("Used Memory: %ld kB\n", used_memory);
    printf("Usage Percentage: %.2f%%\n", (float)used_memory / total_memory * 100);
}

void display_memory_graph(long total_memory, long used_memory) {
    int graph_width = 50; // Width of the graph
    int used_width = (int)((float)used_memory / total_memory * graph_width);
    
    printf("Memory Usage Graph: [");
    for (int i = 0; i < graph_width; i++) {
        if (i < used_width) {
            printf("#");
        } else {
            printf("-");
        }
    }
    printf("] %.2f%% used\n", (float)used_memory / total_memory * 100);
}

int main() {
    while (1) {
        display_ram_usage();
        display_memory_graph(0, 0);  // Placeholder for memory graph

        // Sleep for 2 seconds before refreshing the display
        sleep(2);
        
        // Clear the console (Linux specific)
        printf("\033[H\033[J");
    }

    return 0;
}