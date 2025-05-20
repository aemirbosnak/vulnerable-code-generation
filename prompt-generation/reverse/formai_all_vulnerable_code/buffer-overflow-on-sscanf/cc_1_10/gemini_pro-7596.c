//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

// Max RAM usage to alert at, in MiB
#define MAX_RAM_USAGE_ALERT 1024

// Structure to store RAM usage information
typedef struct ram_usage_info {
    unsigned long long total_ram;
    unsigned long long free_ram;
    unsigned long long used_ram;
    unsigned long long shared_ram;
    unsigned long long buffer_ram;
    unsigned long long cached_ram;
} ram_usage_info_t;

// Function to get RAM usage information
ram_usage_info_t get_ram_usage() {
    ram_usage_info_t usage;

    FILE *fp = fopen("/proc/meminfo", "r");
    if(fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while(fgets(line, sizeof(line), fp) != NULL) {
        if(strncmp(line, "MemTotal:", 9) == 0) {
            sscanf(line, "MemTotal: %llu kB", &usage.total_ram);
        } else if(strncmp(line, "MemFree:", 8) == 0) {
            sscanf(line, "MemFree: %llu kB", &usage.free_ram);
        } else if(strncmp(line, "MemAvailable:", 13) == 0) {
            sscanf(line, "MemAvailable: %llu kB", &usage.free_ram);
        } else if(strncmp(line, "Shmem:", 6) == 0) {
            sscanf(line, "Shmem: %llu kB", &usage.shared_ram);
        } else if(strncmp(line, "Buffers:", 8) == 0) {
            sscanf(line, "Buffers: %llu kB", &usage.buffer_ram);
        } else if(strncmp(line, "Cached:", 7) == 0) {
            sscanf(line, "Cached: %llu kB", &usage.cached_ram);
        }
    }

    fclose(fp);

    return usage;
}

// Function to check if RAM usage is above the alert threshold
int is_ram_usage_above_alert(ram_usage_info_t usage) {
    return usage.used_ram >= (MAX_RAM_USAGE_ALERT * 1024 * 1024);
}

// Function to print RAM usage information
void print_ram_usage(ram_usage_info_t usage) {
    // Calculate used RAM as total RAM minus free RAM
    unsigned long long used_ram = usage.total_ram - usage.free_ram;

    printf("---------------------- RAM Usage ----------------------\n");
    printf("Total RAM:             %llu MiB\n", usage.total_ram / 1024 / 1024);
    printf("Free RAM:               %llu MiB\n", usage.free_ram / 1024 / 1024);
    printf("Used RAM:               %llu MiB\n", used_ram / 1024 / 1024);
    printf("Shared RAM:             %llu MiB\n", usage.shared_ram / 1024 / 1024);
    printf("Buffer RAM:             %llu MiB\n", usage.buffer_ram / 1024 / 1024);
    printf("Cached RAM:             %llu MiB\n", usage.cached_ram / 1024 / 1024);
    printf("-----------------------------------------------------\n");
}

// Function to monitor RAM usage
void monitor_ram_usage() {
    // Get RAM usage information
    ram_usage_info_t usage = get_ram_usage();

    while(1) {
        // Check if RAM usage is above the alert threshold
        if(is_ram_usage_above_alert(usage)) {
            printf("WARNING: RAM usage is above the alert threshold!\n");
            printf("Taking corrective action...\n");
            // Take corrective action, such as killing processes or reducing memory usage
        }

        // Print RAM usage information
        print_ram_usage(usage);

        // Sleep for 1 second
        sleep(1);
    }
}

int main() {
    monitor_ram_usage();

    return EXIT_SUCCESS;
}