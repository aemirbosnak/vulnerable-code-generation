//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define BAR_WIDTH 50

void display_memory_usage(int total_memory, int free_memory) {
    int used_memory = total_memory - free_memory;
    float used_percentage = ((float)used_memory / total_memory) * 100;
    int bar_length = (int)((used_percentage / 100) * BAR_WIDTH);

    // Clear the console
    printf("\033[H\033[J");

    // Display Memory Usage
    printf("Memory Usage Monitor\n");
    printf("---------------------\n");
    printf("Total Memory: %d KB\n", total_memory);
    printf("Free Memory:  %d KB\n", free_memory);
    printf("Used Memory:  %d KB (%.2f%%)\n", used_memory, used_percentage);
    printf("Memory Usage Bar: [");
    
    for (int i = 0; i < BAR_WIDTH; i++) {
        if (i < bar_length) {
            printf("█");
        } else {
            printf(" ");
        }
    }

    printf("]\n");
}

void get_memory_info(int *total_memory, int *free_memory) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %d kB", total_memory) == 1) {
            // Found total memory
        } else if (sscanf(line, "MemFree: %d kB", free_memory) == 1) {
            // Found free memory
        }

        // Break if both values are found
        if (*total_memory > 0 && *free_memory > 0) {
            break;
        }
    }

    fclose(fp);
}

int main() {
    int total_memory = 0, free_memory = 0;

    // Monitor memory usage every 2 seconds
    while (1) {
        get_memory_info(&total_memory, &free_memory);
        display_memory_usage(total_memory, free_memory);
        sleep(2);
    }

    return 0;
}