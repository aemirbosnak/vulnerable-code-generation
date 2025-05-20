//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Size of the buffer for reading the CPU usage
#define BUFFER_SIZE 1024

// Number of CPU cores
#define NUM_CORES 4

// Array to hold the last CPU usage values
double last_cpu_usages[NUM_CORES];

// Function declaration
void get_cpu_usage(double* cpu_usages);

int main() {
    // Initialize the last CPU usage array with 0s
    for(int i = 0; i < NUM_CORES; i++) {
        last_cpu_usages[i] = 0;
    }

    // Loop indefinitely
    while(1) {
        // Declare and initialize the CPU usage array
        double cpu_usages[NUM_CORES];
        memset(cpu_usages, 0, sizeof(cpu_usages));

        // Get the CPU usage values
        get_cpu_usage(cpu_usages);

        // Print the CPU usage
        printf("CPU Usage:\n");
        for(int i = 0; i < NUM_CORES; i++) {
            printf("Core %d: %.2f%%\n", i, cpu_usages[i]);
        }

        // Sleep for 1 second
        sleep(1);
    }
}

void get_cpu_usage(double* cpu_usages) {
    // Open the stat file for the CPU
    FILE* file = fopen("/proc/stat", "r");

    // Check if the file was opened successfully
    if(file == NULL) {
        printf("Error: Unable to open /proc/stat.\n");
        return;
    }

    // Variables to hold the values from the CPU stat file
    char buffer[BUFFER_SIZE];
    unsigned long long cpu_times[NUM_CORES][10];
    memset(cpu_times, 0, sizeof(cpu_times));

    // Read the values from the CPU stat file
    int i = 0;
    while(fgets(buffer, BUFFER_SIZE, file)) {
        if(strncmp(buffer, "cpu", 3) == 0) {
            sscanf(buffer + 4, "%llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
                   &cpu_times[i][0], &cpu_times[i][1], &cpu_times[i][2], &cpu_times[i][3],
                   &cpu_times[i][4], &cpu_times[i][5], &cpu_times[i][6], &cpu_times[i][7],
                   &cpu_times[i][8], &cpu_times[i][9]);
            i++;
        }
    }

    // Close the file
    fclose(file);

    // Calculate the total CPU time and idle time across all cores
    unsigned long long total_time = 0;
    unsigned long long idle_time = 0;
    for(int j = 0; j < NUM_CORES; j++) {
        total_time += cpu_times[j][0] + cpu_times[j][1] + cpu_times[j][2] + cpu_times[j][3] +
                      cpu_times[j][4] + cpu_times[j][5] + cpu_times[j][6] + cpu_times[j][7] +
                      cpu_times[j][8] + cpu_times[j][9];
        idle_time += cpu_times[j][3];
    }

    // Calculate the CPU usage percentage for each core
    for(int j = 0; j < NUM_CORES; j++) {
        double usage = 100.0 * ((double)(total_time - cpu_times[j][3]) - (double)last_cpu_usages[j])
                             / ((double)(total_time - idle_time) - (double)last_cpu_usages[j]);
        if(usage > 100.0) {
            usage = 100.0;
        }
        else if(usage < 0.0) {
            usage = 0.0;
        }
        cpu_usages[j] = usage;
        last_cpu_usages[j] = (double)cpu_times[j][3];
    }
}