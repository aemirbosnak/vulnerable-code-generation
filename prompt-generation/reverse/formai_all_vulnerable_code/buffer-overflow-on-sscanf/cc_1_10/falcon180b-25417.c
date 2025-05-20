//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 100

typedef struct process {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int memory_usage;
} Process;

int main() {
    int num_processes = 0;
    Process *processes = (Process *) malloc(MAX_PROCESSES * sizeof(Process));

    while (num_processes < MAX_PROCESSES) {
        FILE *fp;
        char line[1024];
        char *token;
        int pid;
        int memory_usage;

        // Open /proc/<pid>/stat for each process
        sprintf(line, "/proc/%d/stat", num_processes);
        fp = fopen(line, "r");
        if (fp == NULL) {
            break;
        }

        // Read process name
        fgets(line, sizeof(line), fp);
        token = strtok(line, " ");
        strcpy(processes[num_processes].name, token);

        // Read process ID
        fgets(line, sizeof(line), fp);
        sscanf(line, "%d", &pid);
        processes[num_processes].pid = pid;

        // Read process memory usage
        fgets(line, sizeof(line), fp);
        sscanf(line, "%*d %*d %*d %*d %*d %*d %d", &memory_usage);
        processes[num_processes].memory_usage = memory_usage;

        num_processes++;
        fclose(fp);
    }

    // Sort processes by memory usage
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[j].memory_usage < processes[i].memory_usage) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Print process list
    printf("Process\tPID\tMemory Usage (KB)\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].memory_usage);
    }

    free(processes);
    return 0;
}