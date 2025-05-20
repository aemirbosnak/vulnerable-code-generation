//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 1024

typedef struct {
    char name[256];
    float cpu_usage;
} Process;

void gather_cpu_usage(Process *processes, int *process_count) {
    FILE *fp;
    char buffer[256];
    float total_time = 0.0f;

    // Open the stat file to read processes information
    if ((fp = fopen("/proc/stat", "r")) == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the total CPU time line
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    // Split the line into components
    float user, nice, system, idle;
    sscanf(buffer, "cpu %f %f %f %f", &user, &nice, &system, &idle);
    total_time = user + nice + system + idle;

    // Read process statistics
    *process_count = 0;

    for (int i = 1; i <= MAX_PROCESSES; i++) {
        char path[32];
        snprintf(path, sizeof(path), "/proc/%d/stat", i);

        // Access the process stat file
        if ((fp = fopen(path, "r")) != NULL) {
            int pid;
            char comm[256];
            char state;
            unsigned long utime, stime;

            // Read the first few values of the stat
            fscanf(fp, "%d %s %c %*s %*s %*s %*s %*s %*s %*s %lu %lu", 
                   &pid, comm, &state, &utime, &stime);

            // Simple CPU usage calculation
            unsigned long total_process_time = utime + stime;
            float cpu_percentage = (total_process_time / total_time) * 100;

            // Store process details in the array
            strncpy(processes[*process_count].name, comm, sizeof(processes[*process_count].name));
            processes[*process_count].cpu_usage = cpu_percentage;

            (*process_count)++;
            fclose(fp);
        }
    }
}

void display_usage(Process *processes, int process_count) {
    // Sorting processes by CPU usage
    for (int i = 0; i < process_count - 1; i++) {
        for (int j = i + 1; j < process_count; j++) {
            if (processes[i].cpu_usage < processes[j].cpu_usage) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Display the CPU usage report in a post-apocalyptic style
    printf("\n--- Survivors CPU Usage Report ---\n");
    printf("In this wasteland where machines once roamed...\n");
    printf("Here are the remaining processes, clinging to life:\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < process_count && i < 10; i++) { // Show top 10 processes
        printf("Process: %-20s | CPU Usage: %.2f%%\n", processes[i].name, processes[i].cpu_usage);
    }

    printf("-------------------------------------------\n");
}

int main() {
    Process processes[MAX_PROCESSES];
    int process_count = 0;

    while (1) {
        // Gather CPU usage
        gather_cpu_usage(processes, &process_count);

        // Display the usage information
        display_usage(processes, process_count);

        // Sleep for a while to prevent overwhelming the terminal
        sleep(5);
    }

    return 0;
}