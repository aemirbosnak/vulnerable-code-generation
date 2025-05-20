//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void get_cpu_usage(double *user, double *nice, double *system, double *idle) {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[BUFFER_SIZE];
    if (fgets(line, sizeof(line), file)) {
        sscanf(line, "cpu %lf %lf %lf %lf", user, nice, system, idle);
    }

    fclose(file);
}

double calculate_cpu_usage(double prev_user, double prev_nice, double prev_system, double prev_idle,
                            double curr_user, double curr_nice, double curr_system, double curr_idle) {
    double total_prev = prev_user + prev_nice + prev_system + prev_idle;
    double total_curr = curr_user + curr_nice + curr_system + curr_idle;

    double used = total_curr - total_prev - (curr_idle - prev_idle);
    double cpu_usage = (used / (total_curr - total_prev)) * 100.0;

    return cpu_usage;
}

int main() {
    double prev_user, prev_nice, prev_system, prev_idle;
    double curr_user, curr_nice, curr_system, curr_idle;

    get_cpu_usage(&prev_user, &prev_nice, &prev_system, &prev_idle);

    while (1) {
        sleep(1);
        get_cpu_usage(&curr_user, &curr_nice, &curr_system, &curr_idle);

        double cpu_usage = calculate_cpu_usage(prev_user, prev_nice, prev_system, prev_idle,
                                                curr_user, curr_nice, curr_system, curr_idle);

        printf("CPU Usage: %.2f%%\n", cpu_usage);
        
        // Update previous values for the next iteration
        prev_user = curr_user;
        prev_nice = curr_nice;
        prev_system = curr_system;
        prev_idle = curr_idle;
    }

    return 0;
}