//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Structure to hold CPU usage statistics
typedef struct cpu_usage {
    double user;
    double system;
    double idle;
} cpu_usage;

// Function to get CPU usage statistics
cpu_usage get_cpu_usage() {
    // Open the /proc/stat file
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        exit(1);
    }

    // Read the first line of the file
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("Error reading /proc/stat");
        exit(1);
    }

    // Parse the first line of the file
    cpu_usage usage;
    sscanf(line, "cpu %lf %lf %lf", &usage.user, &usage.system, &usage.idle);

    // Close the /proc/stat file
    fclose(fp);

    // Return the CPU usage statistics
    return usage;
}

// Function to print CPU usage statistics
void print_cpu_usage(cpu_usage usage) {
    // Calculate the total CPU usage
    double total = usage.user + usage.system + usage.idle;

    // Calculate the percentage of CPU usage
    double user_percent = usage.user / total * 100;
    double system_percent = usage.system / total * 100;
    double idle_percent = usage.idle / total * 100;

    // Print the CPU usage statistics
    printf("CPU Usage:\n");
    printf("  User: %.2f%%\n", user_percent);
    printf("  System: %.2f%%\n", system_percent);
    printf("  Idle: %.2f%%\n", idle_percent);
}

// Main function
int main() {
    // Get the CPU usage statistics
    cpu_usage usage = get_cpu_usage();

    // Print the CPU usage statistics
    print_cpu_usage(usage);

    return 0;
}