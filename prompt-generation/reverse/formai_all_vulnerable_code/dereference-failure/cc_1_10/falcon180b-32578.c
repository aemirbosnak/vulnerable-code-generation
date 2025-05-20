//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int memoryUsage;
} Process;

int main() {
    int numProcesses = 0;
    Process processes[MAX_PROCESSES];
    FILE *fp;
    char line[1024];
    char *token;
    int i;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ":");
        if (strcmp(token, "VmSize") == 0) {
            token = strtok(NULL, ":");
            int memoryUsage = atoi(token);
            processes[numProcesses].memoryUsage = memoryUsage;
        } else if (strcmp(token, "Name") == 0) {
            strncpy(processes[numProcesses].name, strtok(NULL, ":"), MAX_PROCESS_NAME_LENGTH - 1);
            processes[numProcesses].name[MAX_PROCESS_NAME_LENGTH - 1] = '\0';
            int pid = atoi(strtok(NULL, ":"));
            processes[numProcesses].pid = pid;
            numProcesses++;
        }
    }

    fclose(fp);

    printf("Process Name\tPID\tMemory Usage (KB)\n");
    for (i = 0; i < numProcesses; i++) {
        printf("%s\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].memoryUsage >> 10);
    }

    return 0;
}