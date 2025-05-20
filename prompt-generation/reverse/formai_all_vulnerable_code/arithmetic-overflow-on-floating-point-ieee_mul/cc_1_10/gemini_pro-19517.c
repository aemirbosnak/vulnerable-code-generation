//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Define the number of CPU cores
#define NUM_CORES 8

// Define the update interval (in seconds)
#define UPDATE_INTERVAL 1

// Define the maximum CPU usage (in percentage)
#define MAX_CPU_USAGE 100

// Define the colors for the CPU usage bar
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RED "\033[31m"
#define COLOR_RESET "\033[0m"

// Function to get the CPU usage for a single core
double get_cpu_usage(int core) {
    // Open the proc/stat file
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Find the line for the specified core
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "cpu", 3) == 0 && atoi(line + 3) == core) {
            break;
        }
    }

    // Close the proc/stat file
    fclose(fp);

    // Parse the line to get the CPU usage
    double user, nice, system, idle, iowait, irq, softirq, steal;
    sscanf(line, "cpu %lf %lf %lf %lf %lf %lf %lf %lf", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);

    // Calculate the CPU usage
    double total = user + nice + system + idle + iowait + irq + softirq + steal;
    double usage = (total - idle) / total * 100;

    // Return the CPU usage
    return usage;
}

// Function to get the overall CPU usage
double get_overall_cpu_usage() {
    // Get the CPU usage for each core
    double cpu_usage[NUM_CORES];
    for (int i = 0; i < NUM_CORES; i++) {
        cpu_usage[i] = get_cpu_usage(i);
    }

    // Calculate the overall CPU usage
    double overall_cpu_usage = 0;
    for (int i = 0; i < NUM_CORES; i++) {
        overall_cpu_usage += cpu_usage[i];
    }
    overall_cpu_usage /= NUM_CORES;

    // Return the overall CPU usage
    return overall_cpu_usage;
}

// Function to print the CPU usage bar
void print_cpu_usage_bar(double cpu_usage) {
    // Calculate the number of green, yellow, and red bars
    int num_green_bars = (int) ((cpu_usage / MAX_CPU_USAGE) * 100);
    int num_yellow_bars = (int) (((cpu_usage - num_green_bars * MAX_CPU_USAGE / 100) / MAX_CPU_USAGE) * 100);
    int num_red_bars = 100 - num_green_bars - num_yellow_bars;

    // Print the CPU usage bar
    printf("[");
    for (int i = 0; i < num_green_bars; i++) {
        printf(COLOR_GREEN "%c" COLOR_RESET, '=');
    }
    for (int i = 0; i < num_yellow_bars; i++) {
        printf(COLOR_YELLOW "%c" COLOR_RESET, '=');
    }
    for (int i = 0; i < num_red_bars; i++) {
        printf(COLOR_RED "%c" COLOR_RESET, '=');
    }
    printf("] %.1f%%\n", cpu_usage);
}

// Main function
int main() {
    // Get the initial CPU usage
    double cpu_usage = get_overall_cpu_usage();

    // Print the initial CPU usage bar
    print_cpu_usage_bar(cpu_usage);

    // Loop forever
    while (1) {
        // Sleep for the update interval
        sleep(UPDATE_INTERVAL);

        // Get the new CPU usage
        cpu_usage = get_overall_cpu_usage();

        // Print the new CPU usage bar
        print_cpu_usage_bar(cpu_usage);
    }

    // Return 0
    return 0;
}