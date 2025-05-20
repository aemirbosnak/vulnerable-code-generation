//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void get_cpu_usage(double *user, double *nice, double *system, double *idle) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    
    // Open the /proc/stat file
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line which contains CPU usage stats
    fgets(buffer, BUFFER_SIZE, fp);
    sscanf(buffer, "cpu %lf %lf %lf %lf",
           user, nice, system, idle);

    fclose(fp);
}

double calculate_cpu_usage(double prev_total_idle, double prev_total_time, 
                            double total_idle, double total_time) {
    double idle = total_idle - prev_total_idle;
    double total = total_time - prev_total_time;

    return ((total - idle) / total) * 100.0;
}

int main() {
    double user, nice, system, idle;
    double prev_total_idle = 0, prev_total_time = 0;

    printf("Starting CPU usage monitor...\n");
    printf("Press Ctrl+C to stop.\n");

    while (1) {
        // Get CPU usage stats
        get_cpu_usage(&user, &nice, &system, &idle);

        double total_idle = idle;
        double total_time = user + nice + system + idle;

        if (prev_total_time > 0) {
            double cpu_usage = calculate_cpu_usage(prev_total_idle, prev_total_time,
                                                    total_idle, total_time);
            printf("CPU Usage: %.2f%%\n", cpu_usage);
        }

        // Store previous values for the next iteration
        prev_total_idle = total_idle;
        prev_total_time = total_time;

        // Sleep for 1 second before the next reading
        sleep(1);
    }

    return 0;
}