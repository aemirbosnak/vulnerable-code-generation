//Code Llama-13B DATASET v1.0 Category: CPU usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <math.h>

// Function to get CPU usage percentage
double get_cpu_usage() {
    FILE* fp;
    char line[256];
    double user, nice, system, idle, total, prev_total, prev_idle;
    double cpu_usage;

    // Read CPU stats from /proc/stat
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen /proc/stat");
        exit(1);
    }
    fgets(line, 256, fp);
    sscanf(line, "%*s %lf %lf %lf %lf", &user, &nice, &system, &idle);
    fclose(fp);

    // Calculate total CPU time
    total = user + nice + system + idle;

    // Calculate CPU usage
    cpu_usage = (total - prev_total) - (prev_idle - idle);
    cpu_usage /= (total - prev_total);
    cpu_usage *= 100;

    // Update previous CPU stats
    prev_total = total;
    prev_idle = idle;

    return cpu_usage;
}

int main() {
    double cpu_usage;
    time_t start, end;
    int i;

    // Initialize previous CPU stats
    get_cpu_usage();

    // Get start time
    start = time(NULL);

    // Loop for 5 seconds
    for (i = 0; i < 5; i++) {
        // Calculate CPU usage
        cpu_usage = get_cpu_usage();

        // Print CPU usage
        printf("CPU usage: %.2f%%\n", cpu_usage);

        // Sleep for 1 second
        sleep(1);
    }

    // Get end time
    end = time(NULL);

    // Calculate total time
    double total_time = difftime(end, start);

    // Calculate average CPU usage
    cpu_usage /= total_time;

    // Print average CPU usage
    printf("Average CPU usage: %.2f%%\n", cpu_usage);

    return 0;
}