//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1024

typedef struct {
    char name[32];
    int pid;
    int ram_usage;
} Process;

int main() {
    Process *processes = malloc(MAX_PROCESSES * sizeof(Process));
    int num_processes = 0;
    int i;
    FILE *file;

    // Open the /proc directory
    file = fopen("/proc", "r");
    if (file == NULL) {
        printf("Error: Failed to open /proc directory.\n");
        exit(1);
    }

    // Read the directory contents
    char path[32];
    while (fscanf(file, "%s", path)!= EOF) {
        if (num_processes >= MAX_PROCESSES) {
            printf("Warning: Maximum number of processes reached.\n");
            break;
        }

        // Get the process name
        strcpy(processes[num_processes].name, path);

        // Get the process ID
        processes[num_processes].pid = atoi(path);

        // Get the process RAM usage
        char filename[64];
        sprintf(filename, "/proc/%d/statm", processes[num_processes].pid);
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Warning: Failed to read RAM usage for process %s (%d).\n", processes[num_processes].name, processes[num_processes].pid);
            processes[num_processes].ram_usage = 0;
        } else {
            int size;
            fscanf(file, "%d", &size);
            processes[num_processes].ram_usage = size * 4096;
            fclose(file);
        }

        // Increment the number of processes
        num_processes++;
    }

    // Sort the processes by RAM usage
    for (i = 0; i < num_processes - 1; i++) {
        int j;
        for (j = i + 1; j < num_processes; j++) {
            if (processes[j].ram_usage > processes[i].ram_usage) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Print the processes
    printf("Process Name | PID | RAM Usage (KB)\n");
    printf("-------------------------------------------------\n");
    for (i = 0; i < num_processes; i++) {
        printf("%-32s | %5d | %10d\n", processes[i].name, processes[i].pid, processes[i].ram_usage / 1024);
    }

    free(processes);
    fclose(file);

    return 0;
}