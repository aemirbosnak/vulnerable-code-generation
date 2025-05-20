//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[16];
    int pid;
    int memUsage;
} Process;

int main() {
    int numProcesses = 0;
    Process processes[MAX_PROCESSES];
    char input[64];

    // Get list of running processes
    FILE *fp = popen("ps -eo pid,comm --sort=-%mem | head -n 11", "r");
    if (fp == NULL) {
        printf("Error: Failed to get process list.\n");
        return 1;
    }

    // Read in process data
    while (fgets(input, sizeof(input), fp)!= NULL) {
        int pid = atoi(strtok(input, " "));
        strcpy(processes[numProcesses].name, strtok(NULL, " "));
        processes[numProcesses].pid = pid;
        numProcesses++;
    }

    // Sort processes by memory usage
    for (int i = 0; i < numProcesses - 1; i++) {
        for (int j = i + 1; j < numProcesses; j++) {
            if (processes[i].memUsage < processes[j].memUsage) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Print process list
    printf("Process\t\tPID\t\tMemory Usage\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%s\t\t%d\t\t%d\n", processes[i].name, processes[i].pid, processes[i].memUsage);
    }

    // Close file
    pclose(fp);

    return 0;
}