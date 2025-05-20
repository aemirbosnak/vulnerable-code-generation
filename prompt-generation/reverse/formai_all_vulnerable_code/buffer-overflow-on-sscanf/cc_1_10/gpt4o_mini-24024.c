//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_PROCESSES 1024
#define ADVICE_BUFFER 256

typedef struct {
    int pid;
    char name[256];
    long memoryUsage;
} Process;

void fetch_current_processes(Process processes[], int *count) {
    FILE *fp;
    char line[512];

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Simulate reading currently running processes
    *count = 0;
    while (fgets(line, sizeof(line), fp) && *count < MAX_PROCESSES) {
        sscanf(line, "processes %d", &processes[*count].pid);
        snprintf(processes[*count].name, sizeof(processes[*count].name), "Process_%d", *count);
        processes[*count].memoryUsage = rand() % 2048; // Simulated memory usage in MB
        (*count)++;
    }

    fclose(fp);
}

void display_processes(Process processes[], int count) {
    printf("\nCurrent Running Processes:\n");
    printf("%-10s %-25s %s\n", "PID", "Process Name", "Memory Usage (MB)");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < count; ++i) {
        printf("%-10d %-25s %ld\n", processes[i].pid, processes[i].name, processes[i].memoryUsage);
    }
}

void suggest_optimizations(Process processes[], int count) {
    char advice[ADVICE_BUFFER];
    long totalMemory = 0;

    for (int i = 0; i < count; ++i) {
        totalMemory += processes[i].memoryUsage;
    }

    if (totalMemory > 1024) {
        snprintf(advice, sizeof(advice), "Consider closing some processes to free up memory.");
    } else {
        snprintf(advice, sizeof(advice), "Your system is running optimally.");
    }

    printf("\nOptimization Suggestions:\n");
    printf("%s\n\n", advice);
}

void display_system_info() {
    struct sysinfo sysInfo;
    if (sysinfo(&sysInfo) == 0) {
        printf("System Information:\n");
        printf("Uptime: %ld days, %ld hours, %ld minutes\n",
               sysInfo.uptime / (60 * 60 * 24),
               (sysInfo.uptime / (60 * 60)) % 24,
               (sysInfo.uptime / 60) % 60);
        printf("Total RAM: %ld MB\n", sysInfo.totalram / (1024 * 1024));
        printf("Free RAM: %ld MB\n", sysInfo.freeram / (1024 * 1024));
    } else {
        perror("Unable to retrieve system information");
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int processCount = 0;

    // Display initial system information
    display_system_info();
    
    // Fetch current processes
    fetch_current_processes(processes, &processCount);

    // Display processes
    display_processes(processes, processCount);

    // Suggest optimizations based on current processes
    suggest_optimizations(processes, processCount);

    return 0;
}