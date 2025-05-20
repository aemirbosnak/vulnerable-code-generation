//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    size_t memory;
} ProcessInfo;

void get_memory_usage(ProcessInfo *processes, int *count) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read total memory
    char line[BUFFER_SIZE];
    size_t total_memory = 0;
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %zu kB", &total_memory) == 1) {
            break;
        }
    }
    fclose(file);

    // Read process memory
    for (int i = 1; i <= MAX_PROCESSES; ++i) {
        char path[BUFFER_SIZE];
        sprintf(path, "/proc/%d/statm", i);
        file = fopen(path, "r");
        if (file != NULL) {
            size_t resident, share, text, lib, data;
            if (fscanf(file, "%zu %zu %zu %zu %zu", &resident, &share, &text, &lib, &data) == 5) {
                processes[*count].pid = i;
                processes[*count].memory = resident * getpagesize() / 1024; // kB
                snprintf(processes[*count].name, BUFFER_SIZE, "%s", path);
                (*count)++;
            }
            fclose(file);
        }
    }
}

void display_memory_usage(ProcessInfo *processes, int count) {
    printf("%-10s %-25s %-15s\n", "PID", "Name", "Memory (kB)");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        printf("%-10d %-25s %-15zu\n", processes[i].pid, processes[i].name, processes[i].memory);
    }
}

void check_memory_limit(ProcessInfo *processes, int count, size_t limit) {
    printf("\nProcesses exceeding memory limit of %zu kB:\n", limit);
    printf("%-10s %-25s %-15s\n", "PID", "Name", "Memory (kB)");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        if (processes[i].memory > limit) {
            printf("%-10d %-25s %-15zu\n", processes[i].pid, processes[i].name, processes[i].memory);
        }
    }
}

int main(int argc, char *argv[]) {
    ProcessInfo processes[MAX_PROCESSES];
    int count = 0;
    size_t memory_limit = 0;

    if (argc > 1) {
        memory_limit = strtoul(argv[1], NULL, 10);
    } else {
        memory_limit = 500; // default limit in kB
    }

    get_memory_usage(processes, &count);
    display_memory_usage(processes, count);
    check_memory_limit(processes, count, memory_limit);

    return 0;
}