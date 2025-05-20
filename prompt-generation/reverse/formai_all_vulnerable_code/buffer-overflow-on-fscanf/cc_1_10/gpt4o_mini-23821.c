//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024

typedef struct {
    int pid;
    char comm[256];
    long rss; // Resident Set Size
} Process;

void parse_memory_info(Process processes[], int *count) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %*d kB") == 0) break; // Read the line without using the values
    }

    fclose(file);

    file = fopen("/proc/self/stat", "r");
    if (file == NULL) {
        perror("Could not open /proc/self/stat");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%*d %*s %*s %*c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %d", &processes[(*count)].pid);
    fclose(file);
}

int get_process_memory_usage(Process processes[]) {
    int count = 0;
    FILE *file = fopen("/proc/self/statm", "r");

    if (file == NULL) {
        perror("Could not open /proc/self/statm");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%ld", &processes[count].rss) == 1 && count < MAX_PROCESSES) {
        processes[count].pid = getpid(); // Using the PID of the current process
        snprintf(processes[count].comm, sizeof(processes[count].comm), "[Current Process]");
        count++;
    }

    fclose(file);
    return count;
}

void display_memory_usage(Process processes[], int count) {
    printf("%-10s %-30s %-10s\n", "PID", "COMMAND", "RSS(kB)");
    printf("------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-10ld\n", processes[i].pid, processes[i].comm, processes[i].rss);
    }
}

void sort_processes_by_memory(Process processes[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (processes[j].rss < processes[j + 1].rss) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int processCount = 0;

    parse_memory_info(processes, &processCount);
    printf("Monitoring RAM usage...\n");

    while(1) {
        processCount = get_process_memory_usage(processes);
        sort_processes_by_memory(processes, processCount);

        display_memory_usage(processes, processCount);
        printf("\n");

        sleep(5); // Update every 5 seconds
    }

    return 0;
}