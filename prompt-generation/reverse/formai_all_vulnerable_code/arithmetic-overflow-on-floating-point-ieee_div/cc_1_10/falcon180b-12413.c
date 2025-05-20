//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <string.h>

// Function to get CPU usage
void getCPUUsage(double *cpuUsage) {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    *cpuUsage = (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000;
    *cpuUsage /= (double)sysconf(_SC_CLK_TCK);
}

int main() {
    double cpuUsage;
    char buffer[256];
    FILE *fp;
    int count = 0;

    // Open log file
    fp = fopen("cpu_usage.log", "a");
    if (fp == NULL) {
        fprintf(stderr, "Error opening log file\n");
        exit(1);
    }

    // Infinite loop to monitor CPU usage
    while (1) {
        // Get current CPU usage
        getCPUUsage(&cpuUsage);

        // Format output string
        snprintf(buffer, sizeof(buffer), "CPU usage: %.2f%%\n", cpuUsage * 100);

        // Write to log file
        fprintf(fp, "%s", buffer);
        fflush(fp);

        // Print to console
        printf("%s", buffer);

        // Wait for 5 seconds before next check
        usleep(5000000);

        // Increment log count
        count++;

        // If log file exceeds 1MB, rename and start a new one
        if (ftell(fp) >= 1048576) {
            fclose(fp);
            snprintf(buffer, sizeof(buffer), "cpu_usage_%d.log", count);
            fp = fopen(buffer, "a");
        }
    }

    return 0;
}