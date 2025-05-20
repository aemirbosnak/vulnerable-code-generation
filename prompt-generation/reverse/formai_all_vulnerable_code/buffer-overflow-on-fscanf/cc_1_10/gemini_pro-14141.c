//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of CPU cores
#define MAX_CORES 8

// Define the CPU usage structure
typedef struct {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;
    unsigned long long guest;
    unsigned long long guest_nice;
} cpu_usage_t;

// Get the CPU usage
cpu_usage_t get_cpu_usage() {
    cpu_usage_t usage;
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
        &usage.user, &usage.nice, &usage.system, &usage.idle, &usage.iowait, &usage.irq, &usage.softirq, &usage.steal, &usage.guest, &usage.guest_nice);
    fclose(fp);
    return usage;
}

// Print the CPU usage
void print_cpu_usage(cpu_usage_t usage) {
    printf("CPU usage:\n");
    printf("User: %llu\n", usage.user);
    printf("Nice: %llu\n", usage.nice);
    printf("System: %llu\n", usage.system);
    printf("Idle: %llu\n", usage.idle);
    printf("Iowait: %llu\n", usage.iowait);
    printf("Irq: %llu\n", usage.irq);
    printf("Softirq: %llu\n", usage.softirq);
    printf("Steal: %llu\n", usage.steal);
    printf("Guest: %llu\n", usage.guest);
    printf("Guest nice: %llu\n", usage.guest_nice);
}

// Main function
int main() {
    // Get the CPU usage
    cpu_usage_t usage = get_cpu_usage();

    // Print the CPU usage
    print_cpu_usage(usage);

    return EXIT_SUCCESS;
}