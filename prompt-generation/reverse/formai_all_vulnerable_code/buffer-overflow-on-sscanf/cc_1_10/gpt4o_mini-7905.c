//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to get the memory usage from /proc/meminfo
void get_memory_usage(int *total_memory, int *free_memory, int *used_memory) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %d kB", total_memory) == 1) {
            continue;
        }
        if (sscanf(line, "MemFree: %d kB", free_memory) == 1) {
            continue;
        }
    }
    fclose(fp);

    // Calculate used memory
    *used_memory = *total_memory - *free_memory;
}

// Function to convert memory from kilobytes to megabytes
void convert_memory_to_mb(int memory_kb, float *memory_mb) {
    *memory_mb = memory_kb / 1024.0;
}

// Function to display memory usage
void display_memory_usage(float total_memory_mb, float free_memory_mb, float used_memory_mb) {
    printf("\n 🎶 RAM Usage Monitor 🎶 \n");
    printf("=========================================\n");
    printf(" Total Memory:   %.2f MB\n", total_memory_mb);
    printf(" Free Memory:    %.2f MB\n", free_memory_mb);
    printf(" Used Memory:    %.2f MB\n", used_memory_mb);
    printf("=========================================\n");
}

int main() {
    int total_memory_kb = 0, free_memory_kb = 0, used_memory_kb = 0;
    float total_memory_mb = 0.0, free_memory_mb = 0.0, used_memory_mb = 0.0;

    while (1) {
        get_memory_usage(&total_memory_kb, &free_memory_kb, &used_memory_kb);
        convert_memory_to_mb(total_memory_kb, &total_memory_mb);
        convert_memory_to_mb(free_memory_kb, &free_memory_mb);
        used_memory_mb = total_memory_mb - free_memory_mb;

        display_memory_usage(total_memory_mb, free_memory_mb, used_memory_mb);
        
        sleep(5); // Wait for 5 seconds before updating
    }

    return 0;
}