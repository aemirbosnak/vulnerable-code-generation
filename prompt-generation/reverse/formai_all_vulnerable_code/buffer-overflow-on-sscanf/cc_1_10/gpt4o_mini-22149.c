//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_PROCESSES 1024

typedef struct {
    int pid;
    char command[256];
    long memory; // Memory in KB
} ProcessInfo;

void fetch_process_memory_info(ProcessInfo *processes, int *count) {
    FILE *fp;
    char line[512];
    int index = 0;

    // Read the /proc/self/statm file to get memory usage
    fp = fopen("/proc/statm", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/statm");
        return;
    }

    while (fgets(line, sizeof(line), fp) && index < MAX_PROCESSES) {
        sscanf(line, "%ld %ld", &processes[index].memory, &processes[index].memory);
        processes[index].pid = index + 1;  // Simulate PID
        snprintf(processes[index].command, sizeof(processes[index].command), "Process %d", processes[index].pid);
        index++;
    }
    *count = index;
    fclose(fp);
}

void display_memory_usage(ProcessInfo *processes, int count) {
    printf("\n%-10s %-30s %-15s\n", "PID", "Command", "Memory (KB)");
    printf("%-10s %-30s %-15s\n", "---", "-------", "-----------");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-15ld\n", processes[i].pid, processes[i].command, processes[i].memory);
    }
}

void monitor_ram_usage() {
    ProcessInfo processes[MAX_PROCESSES];
    int count = 0;

    while (1) {
        // Fetch the current memory usage info
        fetch_process_memory_info(processes, &count);

        // Display memory usage
        display_memory_usage(processes, count);

        // Wait for a second before refreshing display
        sleep(1);

        // Clear the console
        printf("\033[H\033[J");
    }
}

int main() {
    printf("=== RAM Usage Monitor ===\n");
    printf("Press Ctrl+C to stop the monitor...\n\n");

    monitor_ram_usage();

    return 0;
}