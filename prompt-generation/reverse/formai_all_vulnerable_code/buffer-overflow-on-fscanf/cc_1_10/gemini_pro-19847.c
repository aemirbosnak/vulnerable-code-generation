//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare our RAM usage monitor
struct ram_monitor {
    unsigned long long total_ram;
    unsigned long long free_ram;
    unsigned long long used_ram;
};

// Function to get the current RAM usage
struct ram_monitor get_ram_usage() {
    struct ram_monitor ram;

    // Open the /proc/meminfo file
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read the total RAM
    fscanf(meminfo, "MemTotal: %llu kB", &ram.total_ram);

    // Read the free RAM
    fscanf(meminfo, "MemFree: %llu kB", &ram.free_ram);

    // Calculate the used RAM
    ram.used_ram = ram.total_ram - ram.free_ram;

    // Close the /proc/meminfo file
    fclose(meminfo);

    return ram;
}

// Function to print the RAM usage
void print_ram_usage(struct ram_monitor ram) {
    printf("Total RAM: %llu kB\n", ram.total_ram);
    printf("Free RAM: %llu kB\n", ram.free_ram);
    printf("Used RAM: %llu kB\n", ram.used_ram);
}

int main() {
    // Declare our RAM usage monitor
    struct ram_monitor ram;

    // Get the current RAM usage
    ram = get_ram_usage();

    // Print the RAM usage
    print_ram_usage(ram);

    return 0;
}