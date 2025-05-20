//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/statvfs.h>

#define CONFIG_FILE "system_monitor.conf"

typedef struct {
    float cpu_usage_threshold;
    long memory_usage_threshold; // in bytes
    long disk_space_threshold; // in bytes
} Config;

void load_config(Config *config) {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (file == NULL) {
        perror("Could not open config file");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "cpu_usage_threshold=%f\n", &config->cpu_usage_threshold);
    fscanf(file, "memory_usage_threshold=%ld\n", &config->memory_usage_threshold);
    fscanf(file, "disk_space_threshold=%ld\n", &config->disk_space_threshold);

    fclose(file);
}

float get_cpu_usage() {
    // Dummy CPU usage calculation. Replace with actual implementation.
    return rand() % 100; // Simulate CPU usage between 0 to 100%
}

long get_memory_usage() {
    struct sysinfo info;
    sysinfo(&info);
    return info.totalram - info.freeram; // Memory in bytes
}

long get_disk_space() {
    struct statvfs disk_info;
    if (statvfs("/", &disk_info) != 0) {
        perror("Statvfs error");
        return -1;
    }
    return disk_info.f_bsize * disk_info.f_bavail; // Available disk space in bytes
}

void monitor_system(Config *config) {
    // Example of continuous monitoring
    while (1) {
        float cpu_usage = get_cpu_usage();
        long memory_usage = get_memory_usage();
        long disk_space = get_disk_space();

        // Log and check CPU usage
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        if (cpu_usage > config->cpu_usage_threshold) {
            printf("Alert! CPU usage exceeded threshold!\n");
        }

        // Log and check Memory usage
        printf("Memory Usage: %ld bytes\n", memory_usage);
        if (memory_usage > config->memory_usage_threshold) {
            printf("Alert! Memory usage exceeded threshold!\n");
        }

        // Log and check Disk space
        printf("Available Disk Space: %ld bytes\n", disk_space);
        if (disk_space < config->disk_space_threshold) {
            printf("Alert! Available disk space is below threshold!\n");
        }

        sleep(5); // Sleep for 5 seconds before the next check
    }
}

int main() {
    Config config;
    load_config(&config);
    
    printf("Starting system monitor...\n");
    monitor_system(&config);

    return 0;
}