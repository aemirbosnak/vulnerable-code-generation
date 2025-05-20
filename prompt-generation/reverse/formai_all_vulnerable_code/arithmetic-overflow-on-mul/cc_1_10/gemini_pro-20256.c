//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

// Get the current time in milliseconds
long long get_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000;
}

// Get the CPU usage as a percentage
double get_cpu_usage() {
    FILE *fp;
    char buf[1024];
    int user, nice, system, idle, iowait, irq, softirq;

    // Open the /proc/stat file
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        return -1;
    }

    // Read the first line of the file
    fgets(buf, sizeof(buf), fp);

    // Parse the values
    sscanf(buf, "cpu %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    // Close the file
    fclose(fp);

    // Calculate the CPU usage
    double total = user + nice + system + idle + iowait + irq + softirq;
    double idle_total = idle + iowait;
    double usage = (total - idle_total) / total * 100;

    // Return the CPU usage
    return usage;
}

// Print the CPU usage every second
int main() {
    while (1) {
        // Get the current time
        long long time_ms = get_time_ms();

        // Get the CPU usage
        double usage = get_cpu_usage();

        // Print the CPU usage
        printf("%lld %f\n", time_ms, usage);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}