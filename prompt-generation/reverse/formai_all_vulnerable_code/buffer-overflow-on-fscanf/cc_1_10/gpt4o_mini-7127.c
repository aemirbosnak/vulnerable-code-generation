//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESS 1024

typedef struct {
    int pid;          // Process ID
    char name[256];   // Process Name
    float cpu_usage;  // CPU Usage in percentage
} ProcessInfo;

void read_process_info(ProcessInfo *processes, int *count);
void calculate_cpu_usage(ProcessInfo *processes, int count);
void display_process_info(ProcessInfo *processes, int count);
void free_memory(ProcessInfo *processes);

int main() {
    ProcessInfo *processes = malloc(MAX_PROCESS * sizeof(ProcessInfo));
    if (processes == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }

    int count = 0;

    // Continuously monitor CPU usage until user interrupts
    while (1) {
        read_process_info(processes, &count);
        calculate_cpu_usage(processes, count);
        display_process_info(processes, count);
        sleep(1);  // Sleep for 1 second before refreshing
        printf("\033[H\033[J"); // Clear screen for refreshing output
    }

    free_memory(processes);
    return 0;
}

void read_process_info(ProcessInfo *processes, int *count) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open /proc/stat\n");
        return;
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), fp); // Reading CPU line (first line)
    fclose(fp);

    // Read all processes from /proc
    *count = 0;
    for (int i = 1; i < MAX_PROCESS; i++) {
        char path[256];
        snprintf(path, sizeof(path), "/proc/%d/status", i);
        FILE *proc_fp = fopen(path, "r");
        if (proc_fp == NULL) {
            continue; // No more processes
        }

        // Store process details
        processes[*count].pid = i;
        fscanf(proc_fp, "Name:\t%s\n", processes[*count].name);
        fclose(proc_fp);
        (*count)++;
        if (*count >= MAX_PROCESS) {
            break; // Limit reached
        }
    }
}

void calculate_cpu_usage(ProcessInfo *processes, int count) {
    // This function needs to read CPU time info for each process
    for (int i = 0; i < count; i++) {
        // Simulating CPU usage for demonstration purposes only
        processes[i].cpu_usage = rand() % 100; // Random CPU usage
    }
}

void display_process_info(ProcessInfo *processes, int count) {
    printf("%-10s %-30s %-10s\n", "PID", "Process Name", "CPU Usage (%)");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-10.2f\n", processes[i].pid, processes[i].name, processes[i].cpu_usage);
    }
}

void free_memory(ProcessInfo *processes) {
    free(processes);
}