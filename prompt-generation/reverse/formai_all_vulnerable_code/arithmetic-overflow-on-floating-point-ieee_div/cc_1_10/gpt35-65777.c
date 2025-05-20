//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get current CPU usage
float get_cpu_usage() {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    float cpu_usage = 0.0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Could not open system stats file");
        exit(EXIT_FAILURE);
    }

    // Get total CPU time
    getline(&line, &len, fp);
    unsigned long long user, nice, system, idle, iowait, irq, softirq, stealstolen, guest;
    sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &stealstolen, &guest);
    unsigned long long total_cpu_time = user + nice + system + idle + iowait + irq + softirq + stealstolen + guest;

    // Get idle CPU time
    rewind(fp); // Go back to beginning of file
    getline(&line, &len, fp);
    sscanf(line, "cpu %*u %*u %*u %llu", &idle);

    // Calculate CPU usage percentage
    float cpu_usage_percentage = (total_cpu_time - idle) * 100.0 / total_cpu_time;

    fclose(fp);

    return cpu_usage_percentage;
}

int main() {
    // Main program loop
    while (1) {
        // Get current CPU usage
        float cpu_usage = get_cpu_usage();
        printf("Current CPU usage: %.2f%%\n", cpu_usage);

        // Delay for one second
        struct timespec delay;
        delay.tv_sec = 1;
        delay.tv_nsec = 0;
        nanosleep(&delay, NULL);
    }

    return 0;
}