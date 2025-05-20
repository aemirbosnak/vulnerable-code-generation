//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_SIZE 256

void parse_memory_info(long *total_memory, long *free_memory) {
    FILE *fp;
    char line[MAX_LINE_SIZE];

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read the memory information
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "MemTotal: %ld kB", total_memory) == 1) {
            continue;
        }
        if (sscanf(line, "MemFree: %ld kB", free_memory) == 1) {
            continue;
        }
    }

    fclose(fp);
}

void display_memory_usage(long total_memory, long free_memory) {
    long used_memory = total_memory - free_memory;
    float usage_percentage = ((float)used_memory / (float)total_memory) * 100;

    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory : %ld kB\n", free_memory);
    printf("Used Memory : %ld kB (%.2f%% usage)\n", used_memory, usage_percentage);
}

int main(void) {
    long total_memory = 0;
    long free_memory = 0;

    while (1) {
        parse_memory_info(&total_memory, &free_memory);
        display_memory_usage(total_memory, free_memory);

        // Sleep for 5 seconds before refreshing the information
        sleep(5);
        printf("\nRefreshing memory usage...\n\n");
    }

    return 0;
}