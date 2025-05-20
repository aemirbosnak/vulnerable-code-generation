//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ARRAY_SIZE 10000000
#define INTERVAL 1

// A simple data structure to store the CPU usage of a process
typedef struct {
    double user;
    double system;
    double idle;
} cpu_usage;

// Get the CPU usage of the current process
cpu_usage get_cpu_usage() {
    // Open the /proc/stat file
    FILE *proc_stat = fopen("/proc/stat", "r");
    if (proc_stat == NULL) {
        perror("fopen");
        exit(1);
    }

    // Read the first line of the file
    char line[1024];
    if (fgets(line, sizeof(line), proc_stat) == NULL) {
        perror("fgets");
        exit(1);
    }

    // Parse the line to get the CPU usage
    double user, system, idle;
    if (sscanf(line, "cpu %lf %lf %lf", &user, &system, &idle) != 3) {
        fprintf(stderr, "sscanf failed\n");
        exit(1);
    }

    // Close the file
    fclose(proc_stat);

    // Return the CPU usage
    return (cpu_usage){user, system, idle};
}

// Print the CPU usage
void print_cpu_usage(cpu_usage usage) {
    printf("CPU usage:\n");
    printf("  User: %.2f%%\n", usage.user);
    printf("  System: %.2f%%\n", usage.system);
    printf("  Idle: %.2f%%\n", usage.idle);
}

int main() {
    // Get the initial CPU usage
    cpu_usage initial_usage = get_cpu_usage();

    // Loop forever, printing the CPU usage every second
    while (1) {
        // Sleep for one second
        sleep(INTERVAL);

        // Get the current CPU usage
        cpu_usage current_usage = get_cpu_usage();

        // Calculate the difference between the initial CPU usage and the current CPU usage
        double delta_user = current_usage.user - initial_usage.user;
        double delta_system = current_usage.system - initial_usage.system;
        double delta_idle = current_usage.idle - initial_usage.idle;

        // Print the CPU usage
        print_cpu_usage((cpu_usage){delta_user, delta_system, delta_idle});
    }

    return 0;
}