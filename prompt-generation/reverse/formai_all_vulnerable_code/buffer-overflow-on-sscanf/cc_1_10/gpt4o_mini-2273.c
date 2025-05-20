//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MEMORY_INFO_FILE "/proc/meminfo"
#define MAX_LINE_LENGTH 256

void clear_console() {
    printf("\033[H\033[J");
}

void display_ram_usage() {
    char line[MAX_LINE_LENGTH];
    FILE *fp = fopen(MEMORY_INFO_FILE, "r");
    if (fp == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    long total_memory = 0;
    long free_memory = 0;
    long available_memory = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %ld kB", &total_memory) == 1) {}
        else if (sscanf(line, "MemFree: %ld kB", &free_memory) == 1) {}
        else if (sscanf(line, "MemAvailable: %ld kB", &available_memory) == 1) {}
    }
    fclose(fp);

    long used_memory = total_memory - free_memory;
    long cached_memory = available_memory - free_memory;

    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Used Memory: %ld kB\n", used_memory);
    printf("Available Memory: %ld kB\n", available_memory);
    printf("Cached Memory: %ld kB\n", cached_memory);
}

void display_memory_info() {
    clear_console();
    display_ram_usage();
    printf("\nPress CTRL+C to exit...\n");
}

int main() {
    printf("***** Welcome to the Cosmic RAM Usage Monitor *****\n");
    printf("Prepare for a mind-bending journey through your RAM!\n");
    printf("We'll be monitoring the great memory expanse beneath your fingertips.\n");

    while (1) {
        display_memory_info();
        sleep(2); // Update every 2 seconds
    }

    return 0;
}