//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Get CPU usage in percentage
double get_cpu_usage() {
    FILE *fp;
    char buf[1024];
    double total, used;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    fgets(buf, sizeof(buf), fp);
    sscanf(buf, "cpu %lf %lf", &total, &used);
    fclose(fp);

    return used / total * 100;
}

int main() {
    // Initialize variables
    double cpu_usage;
    time_t start_time, end_time;
    int i;

    // Get the start time
    start_time = time(NULL);

    // Simulate CPU usage by performing a busy loop
    for (i = 0; i < 1000000000; i++) {
        // Update the CPU usage every 100ms
        if (i % 1000000 == 0) {
            cpu_usage = get_cpu_usage();
            printf("CPU usage: %f%%\n", cpu_usage);
        }
    }

    // Get the end time
    end_time = time(NULL);

    // Print the total time taken
    printf("Total time: %ld seconds\n", end_time - start_time);

    return 0;
}