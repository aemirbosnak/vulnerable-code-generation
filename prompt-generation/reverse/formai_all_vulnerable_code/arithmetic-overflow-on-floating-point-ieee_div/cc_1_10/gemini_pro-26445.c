//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the maximum length of the CPU usage string
#define MAX_CPU_USAGE_LENGTH 100

// Get the CPU usage as a string
char *get_cpu_usage() {
    // Open the file that contains the CPU usage information
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("fopen");
        return NULL;
    }

    // Read the first line of the file
    char line[MAX_CPU_USAGE_LENGTH];
    if (fgets(line, MAX_CPU_USAGE_LENGTH, file) == NULL) {
        perror("fgets");
        fclose(file);
        return NULL;
    }

    // Close the file
    fclose(file);

    // Return the CPU usage string
    return strdup(line);
}

// Parse the CPU usage string and return the idle time
unsigned long long parse_cpu_usage(char *cpu_usage) {
    // Split the CPU usage string into tokens
    char *tokens[10];
    char *token = strtok(cpu_usage, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }

    // Return the idle time
    return strtoull(tokens[4], NULL, 10);
}

// Print the CPU usage
void print_cpu_usage(unsigned long long cpu_usage) {
    // Calculate the percentage of CPU usage
    double percentage = (double)cpu_usage / (double)sysconf(_SC_CLK_TCK) * 100.0;

    // Print the CPU usage
    printf("CPU usage: %.2f%%\n", percentage);
}

// Get the CPU usage and print it every second
int main() {
    // Get the initial CPU usage
    char *cpu_usage = get_cpu_usage();
    unsigned long long idle_time = parse_cpu_usage(cpu_usage);
    free(cpu_usage);

    // Loop forever
    while (1) {
        // Get the current CPU usage
        cpu_usage = get_cpu_usage();
        unsigned long long current_idle_time = parse_cpu_usage(cpu_usage);
        free(cpu_usage);

        // Calculate the change in idle time
        unsigned long long delta_idle_time = current_idle_time - idle_time;

        // Calculate the CPU usage
        double percentage = (double)delta_idle_time / (double)sysconf(_SC_CLK_TCK) * 100.0;

        // Print the CPU usage
        printf("CPU usage: %.2f%%\n", percentage);

        // Update the idle time
        idle_time = current_idle_time;

        // Sleep for one second
        sleep(1);
    }

    return 0;
}