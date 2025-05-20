//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 100

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int memoryUsage;
} Process;

int getProcesses(Process* processes, int maxProcesses) {
    FILE* file = fopen("/proc/self/status", "r");
    if (file == NULL) {
        return -1;
    }

    char line[1024];
    int numProcesses = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (sscanf(line, "Name:\t%s", processes[numProcesses].name) == 1) {
            numProcesses++;
            if (numProcesses >= maxProcesses) {
                break;
            }
        }
    }

    fclose(file);

    return numProcesses;
}

int main() {
    Process processes[MAX_PROCESSES];
    int numProcesses = getProcesses(processes, MAX_PROCESSES);

    if (numProcesses < 0) {
        printf("Error: could not get process list.\n");
        return 1;
    }

    printf("Process\tPID\tMemory Usage (KB)\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%s\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].memoryUsage);
    }

    return 0;
}