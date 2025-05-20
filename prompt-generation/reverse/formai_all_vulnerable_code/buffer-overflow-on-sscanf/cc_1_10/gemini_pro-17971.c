//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define some happy colors
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_RED "\033[0;31m"
#define COLOR_RESET "\033[0m"

// Get the CPU usage
double get_cpu_usage() {
    // Open the /proc/stat file
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Read the first line of the file
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }

    // Close the file
    fclose(fp);

    // Parse the first line of the file to get the CPU usage
    int user, nice, system, idle, iowait, irq, softirq;
    sscanf(line, "cpu  %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    // Calculate the CPU usage
    double cpu_usage = 100.0 * (user + nice + system + iowait + irq + softirq) / (user + nice + system + idle + iowait + irq + softirq);

    // Return the CPU usage
    return cpu_usage;
}

// Print the CPU usage
void print_cpu_usage(double cpu_usage) {
    // Print the CPU usage to the console
    printf("CPU usage: %.2f%%\n", cpu_usage);

    // Change the color of the console output based on the CPU usage
    if (cpu_usage < 50.0) {
        printf(COLOR_GREEN);
    } else if (cpu_usage < 75.0) {
        printf(COLOR_YELLOW);
    } else {
        printf(COLOR_RED);
    }

    // Print a happy face or a sad face based on the CPU usage
    if (cpu_usage < 50.0) {
        printf(":)");
    } else {
        printf(":(");
    }

    // Reset the color of the console output
    printf(COLOR_RESET);
}

// Main function
int main() {
    // Get the CPU usage
    double cpu_usage = get_cpu_usage();

    // Print the CPU usage
    print_cpu_usage(cpu_usage);

    // Exit the program
    return EXIT_SUCCESS;
}