//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void get_memory_usage(long *total, long *used) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "MemTotal: %ld kB", total) == 1) continue;
        if (sscanf(line, "MemAvailable: %ld kB", used) == 1) continue;
    }
    fclose(fp);
    //* We calculate used memory as follows: used = total - available
    *used = *total - *used;
}

void print_memory_usage(long total, long used) {
    printf("\033[1;32m"); // Set color to green
    printf("---------------------------------------------------\n");
    printf("                 RAM Usage Monitor                 \n");
    printf("---------------------------------------------------\n");
    printf("\033[1;37m"); // Set color to white
    printf("Total Memory:    \033[1;34m%ld kB\033[0m\n", total);
    printf("Used Memory:     \033[1;31m%ld kB\033[0m\n", used);
    printf("Free Memory:     \033[1;36m%ld kB\033[0m\n", total - used);
    printf("---------------------------------------------------\n");
    printf("\033[0m"); // Reset color
}

int main() {
    long total_memory = 0;
    long used_memory = 0;

    // Welcome message
    printf("\033[1;35m"); // Set color to purple
    printf("Welcome to the RAM Usage Monitor! 🎉\n");
    printf("Monitoring your system's RAM usage... 🚀\n");
    printf("\033[0m"); // Reset color

    // Infinite loop to monitor memory usage
    while (1) {
        get_memory_usage(&total_memory, &used_memory);
        print_memory_usage(total_memory, used_memory);
        
        sleep(1); // Update every second
        printf("\033[2J\033[H"); // Clear screen
    }

    return 0;
}