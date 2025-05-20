//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

// Get the current CPU usage in percentage
double get_cpu_usage() {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            // Parse the "cpu " line
            char *fields[11];
            int num_fields = sscanf(line, "cpu %s %s %s %s %s %s %s %s %s %s %s",
                fields[0], fields[1], fields[2], fields[3], fields[4], fields[5],
                fields[6], fields[7], fields[8], fields[9], fields[10]);

            if (num_fields != 11) {
                fprintf(stderr, "Error parsing /proc/stat: %s\n", line);
                fclose(fp);
                return -1;
            }

            // Calculate the CPU usage
            long long total_time = 0;
            for (int i = 0; i < 10; i++) {
                total_time += atoll(fields[i]);
            }

            long long idle_time = atoll(fields[3]);
            double usage = (1 - (idle_time / (double)total_time)) * 100.0;

            fclose(fp);
            return usage;
        }
    }

    fclose(fp);
    return -1;
}

int main() {
    // Get the initial CPU usage
    double initial_usage = get_cpu_usage();
    if (initial_usage < 0) {
        fprintf(stderr, "Error getting initial CPU usage\n");
        return 1;
    }

    // Loop and print the CPU usage every second
    while (1) {
        // Get the current CPU usage
        double current_usage = get_cpu_usage();
        if (current_usage < 0) {
            fprintf(stderr, "Error getting current CPU usage\n");
            return 1;
        }

        // Print the CPU usage
        printf("CPU usage: %.2f%%\n", current_usage);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}