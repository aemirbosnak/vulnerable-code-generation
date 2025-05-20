//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// Define the maximum number of CPU cores to monitor
#define MAX_CPU_CORES 16

// Define the refresh rate (in seconds)
#define REFRESH_RATE 1

// Get the CPU usage for a given core
float get_cpu_usage(int core) {
    // Open the proc file for the core
    char filename[64];
    sprintf(filename, "/proc/stat");
    FILE *f = fopen(filename, "r");
    if (!f) {
        return -1.0;
    }

    // Find the line for the core
    char line[1024];
    while (fgets(line, sizeof(line), f)) {
        if (strstr(line, "cpu")) {
            break;
        }
    }

    // Parse the line and get the CPU usage
    float user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    sscanf(line, "cpu  %f %f %f %f %f %f %f %f %f %f",
        &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    fclose(f);

    // Calculate the CPU usage
    float total = user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;
    float usage = (total - idle) / total * 100.0;
    return usage;
}

// Get the average CPU usage across all cores
float get_average_cpu_usage() {
    // Get the CPU usage for each core
    float usage[MAX_CPU_CORES];
    for (int i = 0; i < MAX_CPU_CORES; i++) {
        usage[i] = get_cpu_usage(i);
    }

    // Calculate the average CPU usage
    float average = 0.0;
    for (int i = 0; i < MAX_CPU_CORES; i++) {
        average += usage[i];
    }
    average /= MAX_CPU_CORES;
    return average;
}

// Display the CPU usage
void display_cpu_usage() {
    // Get the average CPU usage
    float usage = get_average_cpu_usage();

    // Display the CPU usage
    printf("CPU usage: %.2f%%\n", usage);
}

// Main function
int main() {
    // Display the CPU usage every second
    while (1) {
        display_cpu_usage();
        sleep(REFRESH_RATE);
    }

    return 0;
}