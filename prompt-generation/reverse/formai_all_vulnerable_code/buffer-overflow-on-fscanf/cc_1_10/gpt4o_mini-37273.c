//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define STATUS_LINE_COUNT 5

typedef struct {
    int pid;
    char comm[256];
    int memory; // in kB
} Process;

void read_process_memory(Process *processes, int *count);
void sort_processes_by_memory(Process *processes, int count);
void display_memory_usage(Process *processes, int count);

int main() {
    Process processes[MAX_PROCESSES];
    int count = 0;

    while (1) {
        read_process_memory(processes, &count);
        sort_processes_by_memory(processes, count);
        display_memory_usage(processes, count);
        sleep(5); // Update every 5 seconds
    }

    return 0;
}

void read_process_memory(Process *processes, int *count) {
    *count = 0;
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) {
        perror("Unable to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(fp, "%s %d", processes[*count].comm, &processes[*count].memory) != EOF) {
        if (strstr(processes[*count].comm, "VmSize:") != NULL) {
            processes[*count].memory *= 1024; // Convert to kB
            processes[*count].pid = *count + 1; // Not a real PID, only for display
            (*count)++;
            if (*count >= MAX_PROCESSES) break;
        }
    }
    fclose(fp);
}

void sort_processes_by_memory(Process *processes, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (processes[j].memory < processes[j + 1].memory) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void display_memory_usage(Process *processes, int count) {
    system("clear"); // Clear console for updated display
    printf("Top memory-consuming processes:\n");
    printf("%-10s %-25s %-10s\n", "PID", "Command", "Memory (kB)");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < (count < STATUS_LINE_COUNT ? count : STATUS_LINE_COUNT); i++) {
        printf("%-10d %-25s %-10d\n", processes[i].pid, processes[i].comm, processes[i].memory);
    }
}