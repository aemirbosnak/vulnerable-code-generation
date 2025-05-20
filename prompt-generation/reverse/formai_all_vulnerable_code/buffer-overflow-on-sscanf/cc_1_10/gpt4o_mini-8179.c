//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void get_memory_info(long *total, long *free, long *available) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (sscanf(buffer, "MemTotal: %ld kB", total) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %ld kB", free) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemAvailable: %ld kB", available) == 1) {
            continue;
        }
    }
    fclose(file);
}

void display_memory_info() {
    long total = 0, free = 0, available = 0;
    get_memory_info(&total, &free, &available);

    printf("\nMemory Usage Information:\n");
    printf("Total Memory: %ld kB\n", total);
    printf("Free Memory: %ld kB\n", free);
    printf("Available Memory: %ld kB\n", available);
    printf("Used Memory: %ld kB\n", total - free);
    printf("Used Percentage: %.2f%%\n", (float)(total - free) / total * 100);
}

void clear_screen() {
    // Clear the terminal screen using ANSI escape code
    printf("\033[H\033[J");
}

int main() {
    int refresh_rate = 5; // Refresh every 5 seconds

    while (1) {
        clear_screen();
        display_memory_info();
        printf("\nRefreshing every %d seconds...\n", refresh_rate);
        sleep(refresh_rate);
    }

    return 0;
}