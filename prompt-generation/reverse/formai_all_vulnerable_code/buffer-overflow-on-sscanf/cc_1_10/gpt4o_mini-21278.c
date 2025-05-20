//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define CLEAR "\033[H\033[J"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

void print_header() {
    printf(CLEAR);
    printf(COLOR_GREEN);
    printf("============================================\n");
    printf("       RAM Usage Monitor                    \n");
    printf("============================================\n");
    printf(COLOR_RESET);
}

void print_memory_info() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    unsigned long total_memory = 0;
    unsigned long free_memory = 0;
    unsigned long available_memory = 0;
    unsigned long cached_memory = 0;

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        if (sscanf(buffer, "MemTotal: %lu kB", &total_memory) == 1) continue;
        if (sscanf(buffer, "MemFree: %lu kB", &free_memory) == 1) continue;
        if (sscanf(buffer, "MemAvailable: %lu kB", &available_memory) == 1) continue;
        if (sscanf(buffer, "Cached: %lu kB", &cached_memory) == 1) continue;
    }
    
    fclose(file);

    // Calculate used memory
    unsigned long used_memory = total_memory - free_memory;

    // Print memory usage info in a decorative format
    printf(COLOR_YELLOW "Total Memory: %lu MB\n", total_memory / 1024);
    printf(COLOR_YELLOW "Free Memory: %lu MB\n", free_memory / 1024);
    printf(COLOR_YELLOW "Available Memory: %lu MB\n", available_memory / 1024);
    printf(COLOR_RED "Used Memory: %lu MB\n", used_memory / 1024);
    printf(COLOR_GREEN "Cached Memory: %lu MB\n", cached_memory / 1024);
    printf(COLOR_RESET);
}

int main() {
    while (1) {
        print_header();
        print_memory_info();
        sleep(3);  // Update every 3 seconds
    }
    return 0;
}