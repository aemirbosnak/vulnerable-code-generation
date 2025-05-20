//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

// Function prototypes
void get_cpu_usage(double* user, double* nice, double* system, double* idle);
void display_usage();
double calculate_cpu_usage(double old_idle, double old_total, double new_idle, double new_total);

int main() {
    double user1, nice1, system1, idle1;
    double user2, nice2, system2, idle2;
    double total1, total2;
    double cpu_usage;
    
    // Initial CPU data reading
    get_cpu_usage(&user1, &nice1, &system1, &idle1);
    
    while (1) {
        sleep(1); // Pause execution for 1 second

        // Reading CPU data again
        get_cpu_usage(&user2, &nice2, &system2, &idle2);
        
        // Calculate total and usage values
        total1 = user1 + nice1 + system1 + idle1;
        total2 = user2 + nice2 + system2 + idle2;
        
        cpu_usage = calculate_cpu_usage(idle1, total1, idle2, total2);
        
        // Display usage in a well-defined format
        display_usage(cpu_usage);
        
        // Update previous values
        user1 = user2;
        nice1 = nice2;
        system1 = system2;
        idle1 = idle2;
    }
    
    return 0;
}

void get_cpu_usage(double* user, double* nice, double* system, double* idle) {
    // Open the /proc/stat file to retrieve CPU statistics
    FILE* file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    
    // Read the first line from /proc/stat
    if (fgets(buffer, BUFFER_SIZE, file) == NULL) {
        perror("Failed to read CPU data");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Parse the CPU usage data
    sscanf(buffer, "cpu %lf %lf %lf %lf", user, nice, system, idle);

    fclose(file);
}

double calculate_cpu_usage(double old_idle, double old_total, double new_idle, double new_total) {
    // Calculate CPU usage percentage
    double idle_diff = new_idle - old_idle;
    double total_diff = new_total - old_total;

    if (total_diff == 0) {
        return 0.0; // To prevent division by zero
    }

    return (1.0 - (idle_diff / total_diff)) * 100.0;
}

void display_usage(double cpu_usage) {
    // Clear the terminal and print CPU usage
    printf("\033[H\033[J"); // ANSI escape codes to clear the terminal
    printf("Current CPU Usage: %.2f%%\n", cpu_usage);
    fflush(stdout);
}