//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void get_memory_usage(float *total_memory, float *used_memory) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    float mem_total, mem_free, mem_available;

    // Open the /proc/meminfo file to read memory stats
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Read total memory
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "MemTotal: %f kB", &mem_total);
    }

    // Read available memory
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "MemAvailable: %f kB", &mem_available);
    }

    fclose(fp);

    // Calculate used memory
    mem_free = mem_available; // Assuming available is free memory
    *used_memory = mem_total - mem_free;
    *total_memory = mem_total;
}

void display_memory_usage() {
    float total_memory = 0;
    float used_memory = 0;

    get_memory_usage(&total_memory, &used_memory);

    printf("Memory Usage:\n");
    printf("Total Memory: %.2f MB\n", total_memory / 1024);
    printf("Used Memory: %.2f MB\n", used_memory / 1024);
    printf("Free Memory: %.2f MB\n", (total_memory - used_memory) / 1024);
}

void monitor_memory_usage() {
    while (1) {
        display_memory_usage();
        sleep(5); // Update every 5 seconds
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Calm RAM Usage Monitor.\n");
    printf("This program will display the current RAM usage on your system.\n");
    printf("Monitoring in progress...\n");
    printf("Press Ctrl+C to stop the monitoring.\n\n");

    // Call the function that monitors memory usage
    monitor_memory_usage();

    return 0;
}