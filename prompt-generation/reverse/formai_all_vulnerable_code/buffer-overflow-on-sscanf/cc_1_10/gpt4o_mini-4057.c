//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void read_memory_info(long *total_mem, long *free_mem, long *available_mem) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %ld kB", total_mem) == 1)
            continue;
        if (sscanf(line, "MemFree: %ld kB", free_mem) == 1)
            continue;
        if (sscanf(line, "MemAvailable: %ld kB", available_mem) == 1)
            continue;
    }

    fclose(fp);
}

void display_memory_usage(long total_mem, long free_mem, long available_mem) {
    long used_mem = total_mem - free_mem;
    float used_percentage = ((float)used_mem / total_mem) * 100;

    printf("\n");
    printf("Memory Usage:\n");
    printf("-------------\n");
    printf("Total Memory: %.2f GB\n", total_mem / 1024.0 / 1024.0);
    printf("Used Memory: %.2f GB (%.2f% used)\n", used_mem / 1024.0 / 1024.0, used_percentage);
    printf("Free Memory: %.2f GB\n", free_mem / 1024.0 / 1024.0);
    printf("Available Memory: %.2f GB\n", available_mem / 1024.0 / 1024.0);
    printf("-------------\n");
}

int main() {
    long total_mem, free_mem, available_mem;

    while (1) {
        read_memory_info(&total_mem, &free_mem, &available_mem);
        display_memory_usage(total_mem, free_mem, available_mem);
        sleep(1);
    }

    return 0;
}