//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

// Define the number of seconds to monitor CPU usage
#define MONITOR_SECS 10

// Declare the function to get CPU usage
int get_cpu_usage();

int main() {
    // Get the starting time
    struct timeval start_time;
    gettimeofday(&start_time, NULL);

    // Monitor CPU usage for MONITOR_SECS seconds
    int cpu_usage = 0;
    for (int i = 0; i < MONITOR_SECS; i++) {
        cpu_usage += get_cpu_usage();
        sleep(1);
    }

    // Get the ending time
    struct timeval end_time;
    gettimeofday(&end_time, NULL);

    // Calculate the average CPU usage
    double avg_cpu_usage = (double)cpu_usage / MONITOR_SECS;

    // Print the average CPU usage
    printf("Average CPU usage over %d seconds: %.2f%%\n", MONITOR_SECS, avg_cpu_usage);

    return 0;
}

int get_cpu_usage() {
    // Open the /proc/stat file
    FILE *proc_stat = fopen("/proc/stat", "r");
    if (proc_stat == NULL) {
        perror("Error opening /proc/stat");
        exit(1);
    }

    // Read the first line of the file
    char line[1024];
    if (fgets(line, sizeof(line), proc_stat) == NULL) {
        perror("Error reading /proc/stat");
        exit(1);
    }

    // Close the /proc/stat file
    fclose(proc_stat);

    // Parse the first line of the file to get the CPU usage
    int cpu_usage;
    sscanf(line, "cpu %d %d %d %d %d %d %d %d", &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage);

    // Return the CPU usage
    return cpu_usage;
}