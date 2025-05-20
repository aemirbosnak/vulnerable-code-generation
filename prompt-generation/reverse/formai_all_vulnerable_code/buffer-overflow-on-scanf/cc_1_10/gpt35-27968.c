//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROC_PATH_LENGTH 256

typedef struct {
    int pid;
    char command[256];
    float cpu_usage;
} Process;

int num_procs = 0;

Process* initProcesses(int* num_procs) {
    *num_procs = 0;
    Process* processes = malloc(sizeof(Process));
    return processes;
}

void addProcess(Process** processes, int* num_procs, int pid, char* command) {
    *num_procs += 1;
    *processes = realloc(*processes, *num_procs * sizeof(Process));
    (*processes)[*num_procs - 1].pid = pid;
    strcpy((*processes)[*num_procs - 1].command, command);
}

int cpuUsage(int pid) {
    char proc_path[MAX_PROC_PATH_LENGTH];
    sprintf(proc_path, "/proc/%d/stat", pid);
    FILE* f = fopen(proc_path, "r");

    if (!f) {
        return -1;
    }

    int utime, stime;
    fscanf(f, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %*u %d %d", &utime, &stime);
    fclose(f);
    return utime + stime;
}

void updateCpuUsage(Process** processes, int num_procs) {
    for (int i = 0; i < num_procs; i++) {
        int cpu_time = cpuUsage((*processes)[i].pid);
        if (cpu_time == -1) {
            continue;
        }

        float cpu_usage = (float)cpu_time / 1000;
        (*processes)[i].cpu_usage = cpu_usage;
    }
}

void printProcesses(Process* processes, int num_procs) {
    printf("+-----+--------------------------+-------------+\n");
    printf("| PID |          COMMAND         | CPU USAGE % |\n");
    printf("+-----+--------------------------+-------------+\n");

    for (int i = 0; i < num_procs; i++) {
        printf("| %3d | %-24s |   %6.2f    |\n", processes[i].pid, processes[i].command, processes[i].cpu_usage);
    }

    printf("+-----+--------------------------+-------------+\n");
}

int main() {
    Process* processes = initProcesses(&num_procs);

    // Prompt the user to enter the number of processes to monitor
    int n;
    printf("Enter number of processes to monitor: ");
    scanf("%d", &n);

    // Prompt the user to enter the process PIDs and add them to the list
    printf("Enter the process PIDs:\n");
    for (int i = 0; i < n; i++) {
        int pid;
        scanf("%d", &pid);
        char command[256];
        sprintf(command, "%d", pid);
        addProcess(&processes, &num_procs, pid, command);
    }

    // Continuously update and print the CPU usage of the monitored processes
    while (1) {
        updateCpuUsage(&processes, num_procs);
        printProcesses(processes, num_procs);
        sleep(1);
        system("clear"); // clear the console
    }

    return 0;
}