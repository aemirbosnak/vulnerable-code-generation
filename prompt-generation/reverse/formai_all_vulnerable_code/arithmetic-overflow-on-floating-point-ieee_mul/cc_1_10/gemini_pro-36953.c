//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

// Get CPU usage in percentage
double get_cpu_usage() {
    FILE *fp;
    char line[1024];
    double user, nice, system, idle, iowait, irq, softirq;

    // Open /proc/stat file
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Read first line of /proc/stat
    fgets(line, sizeof(line), fp);

    // Parse CPU usage data from the first line
    sscanf(line, "cpu %lf %lf %lf %lf %lf %lf %lf",
            &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    // Calculate CPU usage percentage
    double total = user + nice + system + idle + iowait + irq + softirq;
    double usage = (total - idle) / total * 100;

    // Close /proc/stat file
    fclose(fp);

    // Return CPU usage percentage
    return usage;
}

// Print CPU usage in a user-friendly format
void print_cpu_usage() {
    // Get CPU usage in percentage
    double usage = get_cpu_usage();

    // Print CPU usage in a user-friendly format
    printf("CPU usage: %.2f%%\n", usage);
}

// Main function
int main() {
    // Get CPU usage every second
    while (1) {
        print_cpu_usage();
        sleep(1);
    }

    return 0;
}