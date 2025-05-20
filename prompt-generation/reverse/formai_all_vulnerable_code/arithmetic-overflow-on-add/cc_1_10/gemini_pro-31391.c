//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

// Define the CPU usage calculation formula
#define CPU_USAGE (100.0 * (1.0 - (double)idle / (double)total))

// Get the CPU usage in percentage
double get_cpu_usage() {
    // Get the current time
    struct timeval now;
    gettimeofday(&now, NULL);

    // Open the /proc/stat file
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1.0;
    }

    // Read the first line of the file
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("fgets");
        fclose(fp);
        return -1.0;
    }

    // Parse the CPU usage data from the line
    int user, nice, system, idle, iowait, irq, softirq;
    sscanf(line, "cpu %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    // Calculate the total CPU time
    int total = user + nice + system + idle + iowait + irq + softirq;

    // Calculate the CPU usage
    double cpu_usage = CPU_USAGE;

    // Close the file
    fclose(fp);

    // Return the CPU usage
    return cpu_usage;
}

// Print the CPU usage
void print_cpu_usage() {
    // Get the CPU usage
    double cpu_usage = get_cpu_usage();

    // Print the CPU usage
    printf("CPU usage: %.2f%%\n", cpu_usage);
}

// Main function
int main() {
    // Print the CPU usage every second
    while (1) {
        print_cpu_usage();
        sleep(1);
    }

    return 0;
}