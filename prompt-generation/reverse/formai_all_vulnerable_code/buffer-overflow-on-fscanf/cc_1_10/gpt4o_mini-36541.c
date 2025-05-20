//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024

typedef struct {
    int pid;
    char name[256];
    size_t rss;  // Resident Set Size
} ProcessMemory;

void print_memory_usage(ProcessMemory *processes, int process_count) {
    printf("\n-------------------------------------------\n");
    printf("| PID   | Name                           | RSS Size (KB) |\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < process_count; i++) {
        printf("| %5d | %-30s | %13zu  |\n", processes[i].pid, processes[i].name, processes[i].rss);
    }
    printf("-------------------------------------------\n");
}

int get_memory_usage(ProcessMemory *processes) {
    char line[256];
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to read /proc/meminfo");
        return -1;
    }

    int process_count = 0;
    FILE *proc_file;
    char stat_file[256];
    for (int pid = 1; pid <= MAX_PROCESSES; pid++) {
        snprintf(stat_file, sizeof(stat_file), "/proc/%d/stat", pid);
        proc_file = fopen(stat_file, "r");
        if (proc_file != NULL) {
            // Read the first 24 fields
            fscanf(proc_file, "%d %s", &processes[process_count].pid, processes[process_count].name);
            // Remove parentheses from command name
            memmove(processes[process_count].name, processes[process_count].name + 1,
                    strlen(processes[process_count].name) - 2);
            // Now find RSS size in /proc/<pid>/statm
            snprintf(stat_file, sizeof(stat_file), "/proc/%d/statm", pid);
            FILE *statm_file = fopen(stat_file, "r");
            if (statm_file != NULL) {
                size_t pages;
                fscanf(statm_file, "%zu", &pages);
                processes[process_count].rss = pages * getpagesize() / 1024;  // Convert to KB
                fclose(statm_file);
                process_count++;
                if (process_count >= MAX_PROCESSES) {
                    break;  // Limit to MAX_PROCESSES
                }
            }
            fclose(proc_file);
        }
    }
    fclose(fp);
    return process_count;
}

int main() {
    ProcessMemory processes[MAX_PROCESSES];
    while (1) {
        int process_count = get_memory_usage(processes);
        if (process_count < 0) {
            return EXIT_FAILURE;
        }

        print_memory_usage(processes, process_count);
        printf("\nPress Ctrl+C to stop monitoring...\n");
        sleep(5);  // Monitor every 5 seconds
    }
    return EXIT_SUCCESS;
}