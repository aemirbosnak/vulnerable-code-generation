//Code Llama-13B DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
/*
 * cpu_usage.c
 *
 * A simple CPU usage monitor program that prints the CPU usage
 * to the console.
 *
 * Usage:
 *      cpu_usage
 *
 * Author:
 *      John Doe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Struct to hold CPU usage information
typedef struct {
    float user;
    float nice;
    float system;
    float idle;
    float iowait;
    float irq;
    float softirq;
    float steal;
    float guest;
    float guest_nice;
} cpu_usage_t;

// Function to read CPU usage information from /proc/stat
cpu_usage_t read_cpu_usage(void) {
    FILE *file;
    char line[256];
    cpu_usage_t usage;

    // Open /proc/stat file
    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open /proc/stat file\n");
        exit(1);
    }

    // Read the first line of the file
    fgets(line, sizeof(line), file);

    // Close the file
    fclose(file);

    // Extract the CPU usage information
    sscanf(line, "cpu %f %f %f %f %f %f %f %f %f %f", &usage.user, &usage.nice, &usage.system, &usage.idle, &usage.iowait, &usage.irq, &usage.softirq, &usage.steal, &usage.guest, &usage.guest_nice);

    return usage;
}

// Function to print CPU usage information to the console
void print_cpu_usage(cpu_usage_t usage) {
    printf("CPU Usage: %.2f%%\n", (usage.user + usage.nice + usage.system + usage.idle + usage.iowait + usage.irq + usage.softirq + usage.steal) * 100);
}

// Main function
int main(void) {
    // Read CPU usage information
    cpu_usage_t usage = read_cpu_usage();

    // Print CPU usage information to the console
    print_cpu_usage(usage);

    return 0;
}