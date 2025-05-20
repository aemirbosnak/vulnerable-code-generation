//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 1000

struct process {
    char name[20];
    int pid;
    int ram_usage;
};

int main() {
    int num_processes = 0;
    struct process processes[MAX_PROCESSES];

    FILE *fp;
    char line[100];
    char *token;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the number of processes
    fgets(line, 100, fp);
    sscanf(line, "VmSize: %d kB", &num_processes);

    fclose(fp);

    // Read the list of processes
    for (int i = 0; i < num_processes; i++) {
        sprintf(line, "/proc/%d/status", i);
        fp = fopen(line, "r");
        if (fp == NULL) {
            printf("Error opening file.\n");
            exit(1);
        }

        // Read the name and PID of the process
        fgets(line, 100, fp);
        token = strtok(line, " ");
        strcpy(processes[i].name, token);
        token = strtok(NULL, " ");
        processes[i].pid = atoi(token);

        // Read the RAM usage of the process
        fgets(line, 100, fp);
        sscanf(line, "VmSize: %d kB", &processes[i].ram_usage);

        fclose(fp);
    }

    // Sort the processes by RAM usage
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[j].ram_usage < processes[i].ram_usage) {
                struct process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Print the list of processes
    printf("Process\tPID\tRAM Usage (kB)\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].ram_usage);
    }

    return 0;
}