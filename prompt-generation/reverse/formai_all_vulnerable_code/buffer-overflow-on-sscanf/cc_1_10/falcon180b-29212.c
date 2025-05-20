//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int memoryUsage;
} Process;

int getProcessMemoryUsage(int pid) {
    char filename[20];
    sprintf(filename, "/proc/%d/statm", pid);

    FILE *file = fopen(filename, "r");
    int memoryUsage = 0;

    if (file!= NULL) {
        fscanf(file, "%d", &memoryUsage);
        fclose(file);
    }

    return memoryUsage;
}

void updateProcessMemoryUsage(Process *process) {
    process->memoryUsage = getProcessMemoryUsage(process->pid);
}

int compareProcesses(const void *a, const void *b) {
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;

    return processB->memoryUsage - processA->memoryUsage;
}

int main() {
    Process processes[MAX_PROCESSES];
    int numProcesses = 0;

    char command[100];
    sprintf(command, "ps -eo pid,comm --sort=-%mem | head -n %d", MAX_PROCESSES, MAX_PROCESSES);

    FILE *file = popen(command, "r");

    if (file!= NULL) {
        char line[100];
        while (fgets(line, sizeof(line), file)!= NULL) {
            int pid;
            char processName[MAX_PROCESS_NAME_LENGTH];

            sscanf(line, "%d %s", &pid, processName);

            if (numProcesses < MAX_PROCESSES) {
                strncpy(processes[numProcesses].name, processName, MAX_PROCESS_NAME_LENGTH);
                processes[numProcesses].pid = pid;
                processes[numProcesses].memoryUsage = 0;
                numProcesses++;
            }
        }

        pclose(file);

        qsort(processes, numProcesses, sizeof(Process), compareProcesses);

        printf("Process\tPID\tMemory Usage\n");

        for (int i = 0; i < numProcesses; i++) {
            updateProcessMemoryUsage(&processes[i]);
            printf("%s\t%d\t%d kB\n", processes[i].name, processes[i].pid, processes[i].memoryUsage);
        }
    }

    return 0;
}