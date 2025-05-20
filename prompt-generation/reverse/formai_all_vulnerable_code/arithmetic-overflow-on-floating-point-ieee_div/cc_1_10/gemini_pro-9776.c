//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define our CPU usage monitor struct
typedef struct {
    long long total_time;
    long long idle_time;
    long long active_time;
} cpu_usage;

// Get the CPU usage statistics
cpu_usage get_cpu_usage(void) {
    cpu_usage usage;

    // Open the /proc/stat file
    FILE *fp = fopen("/proc/stat", "r");

    // Read the first line of the file
    char line[1024];
    fgets(line, sizeof(line), fp);

    // Parse the line into the total time, idle time, and active time
    sscanf(line, "cpu %lld %lld %lld", &usage.total_time, &usage.idle_time, &usage.active_time);

    // Return the CPU usage struct
    return usage;
}

// Get a funny name for the CPU usage
char *get_cpu_usage_name(double usage) {
    if (usage < 0.25) {
        return "Sleeping";
    } else if (usage < 0.50) {
        return "Relaxing";
    } else if (usage < 0.75) {
        return "Working";
    } else {
        return "Struggling";
    }
}

// Print the CPU usage
void print_cpu_usage(cpu_usage usage) {
    double active_usage = (double)usage.active_time / (double)usage.total_time;
    printf("CPU usage: %.2f%% (%s)\n", active_usage * 100.0, get_cpu_usage_name(active_usage));
}

// Monitor the CPU usage
void monitor_cpu_usage(void) {
    // Get the current CPU usage
    cpu_usage current_usage = get_cpu_usage();

    // Get the previous CPU usage
    static cpu_usage previous_usage;

    // Calculate the change in CPU usage
    cpu_usage delta_usage;
    delta_usage.total_time = current_usage.total_time - previous_usage.total_time;
    delta_usage.idle_time = current_usage.idle_time - previous_usage.idle_time;
    delta_usage.active_time = current_usage.active_time - previous_usage.active_time;

    // Print the CPU usage
    print_cpu_usage(delta_usage);

    // Update the previous CPU usage
    previous_usage = current_usage;

    // Sleep for 1 second
    sleep(1);
}

int main(void) {
    // Monitor the CPU usage forever
    while (1) {
        monitor_cpu_usage();
    }

    return 0;
}