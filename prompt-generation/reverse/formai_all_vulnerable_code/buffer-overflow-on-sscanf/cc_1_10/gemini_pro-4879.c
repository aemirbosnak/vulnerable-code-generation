//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

// Define the cyberpunk style
#define CYBERPUNK_STYLE "\033[1;32m"
#define CYBERPUNK_END "\033[0m"

// Define the CPU usage variables
float cpu_usage;
float cpu_max_usage;
float cpu_min_usage;

// Define the main function
int main() {
    // Initialize the CPU usage variables
    cpu_usage = 0.0;
    cpu_max_usage = 0.0;
    cpu_min_usage = 100.0;

    // Start the main loop
    while (true) {
        // Get the current CPU usage
        FILE *fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        char line[1024];
        while (fgets(line, sizeof(line), fp) != NULL) {
            if (strncmp(line, "cpu ", 4) == 0) {
                // Parse the CPU usage line
                unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
                sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

                // Calculate the CPU usage
                cpu_usage = 100.0 * (user + nice + system + irq + softirq) / (user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice);

                // Update the CPU usage variables
                if (cpu_usage > cpu_max_usage) {
                    cpu_max_usage = cpu_usage;
                }
                if (cpu_usage < cpu_min_usage) {
                    cpu_min_usage = cpu_usage;
                }

                // Print the CPU usage
                printf(CYBERPUNK_STYLE "CPU usage: %.2f%% (max: %.2f%%, min: %.2f%%)\n" CYBERPUNK_END, cpu_usage, cpu_max_usage, cpu_min_usage);

                break;
            }
        }

        fclose(fp);

        // Sleep for a second
        sleep(1);
    }

    // Exit the program
    return EXIT_SUCCESS;
}