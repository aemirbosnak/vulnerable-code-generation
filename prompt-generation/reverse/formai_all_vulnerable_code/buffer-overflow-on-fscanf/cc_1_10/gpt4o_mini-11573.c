//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    pid_t pid;
    char name[64];
    float memory_usage; // in MB
} ProcessInfo;

// Function to read memory usage statistics from /proc/[pid]/statm
float get_memory_usage(pid_t pid) {
    char filepath[BUFFER_SIZE];
    snprintf(filepath, sizeof(filepath), "/proc/%d/statm", pid);
    
    FILE *file = fopen(filepath, "r");
    if (!file) return 0.0;

    unsigned long size, resident, share, text, lib, data, dt;
    fscanf(file, "%lu %lu %lu %lu %lu %lu %lu",
           &size, &resident, &share, &text, &lib, &data, &dt);
    fclose(file);

    // Convert resident pages to MB (assuming 4KB per page)
    return (resident * 4.0) / 1024.0;
}

// Function to get a list of processes with their memory usage
int get_processes(ProcessInfo *processes) {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) return -1;

    int count = 0;
    char line[BUFFER_SIZE];

    // Read each process from the /proc directory
    for (pid_t pid = 1; pid < MAX_PROCESSES; pid++) {
        snprintf(line, sizeof(line), "/proc/%d/comm", pid);
        FILE *proc_file = fopen(line, "r");
        if (proc_file) {
            fgets(processes[count].name, sizeof(processes[count].name), proc_file);
            strtok(processes[count].name, "\n"); // remove newline

            processes[count].pid = pid;
            processes[count].memory_usage = get_memory_usage(pid);
            count++;
            fclose(proc_file);
        }
    }

    fclose(fp);
    return count;
}

// Function to sort the processes by memory usage (descending)
int compare_memory(const void *a, const void *b) {
    ProcessInfo *proc1 = (ProcessInfo *)a;
    ProcessInfo *proc2 = (ProcessInfo *)b;

    return (proc2->memory_usage > proc1->memory_usage) - (proc2->memory_usage < proc1->memory_usage);
}

// Function to display process information
void display_processes(ProcessInfo *processes, int count) {
    printf("%-10s %-50s %-10s\n", "PID", "Process Name", "Memory (MB)");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (processes[i].memory_usage > 0) {
            printf("%-10d %-50s %-10.2f\n", processes[i].pid, processes[i].name, processes[i].memory_usage);
        }
    }
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int process_count;

    while (1) {
        // Retrieve the process information
        process_count = get_processes(processes);
        if (process_count < 0) {
            fprintf(stderr, "Error reading processes\n");
            exit(EXIT_FAILURE);
        }

        // Sort the processes by memory usage
        qsort(processes, process_count, sizeof(ProcessInfo), compare_memory);

        // Clear the terminal
        printf("\e[1;1H\e[2J"); // ANSI escape code to clear screen

        // Display the sorted processes
        display_processes(processes, process_count);

        sleep(5); // Update every 5 seconds
    }

    return 0;
}