//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

struct Process {
    char name[20];
    int pid;
    float cpu_usage;
};

struct Process processes[MAX_PROCESSES];
int num_processes = 0;

// function to calculate CPU usage for a process using its PID
float get_cpu_usage(int pid) {
    float cpu_usage = 0.0;
    char command[100];
    sprintf(command, "ps -p %d -o %%cpu | tail -n 1", pid);
    FILE* fp = popen(command, "r");
    if (fp == NULL) {
        perror("Error: Failed to execute command");
        exit(1);
    }
    if (fgets(command, sizeof(command), fp) != NULL) {
        cpu_usage = atof(command);
    }
    pclose(fp);
    return cpu_usage;
}

int main() {
    // get names and PIDs of all running processes
    FILE* fp = popen("ps -e -o comm,pid | sed '1d'", "r");
    if (fp == NULL) {
        perror("Error: Failed to execute command");
        exit(1);
    }
    char name[20], pid[10];
    while (fscanf(fp, "%s %s", name, pid) == 2 && num_processes < MAX_PROCESSES) {
        strcpy(processes[num_processes].name, name);
        processes[num_processes].pid = atoi(pid);
        processes[num_processes].cpu_usage = 0.0;
        num_processes++;
    }
    pclose(fp);

    // calculate CPU usage for each process
    for (int i = 0; i < num_processes; i++) {
        processes[i].cpu_usage = get_cpu_usage(processes[i].pid);
    }

    // print list of processes sorted by CPU usage
    printf("CPU USAGE MONITOR\n");
    printf("=================\n");
    printf("PROCESS NAME\tPID\tCPU USAGE\n");
    printf("---------------------------------\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = i+1; j < num_processes; j++) {
            if (processes[j].cpu_usage > processes[i].cpu_usage) {
                // swap processes
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
        printf("%-20s\t%d\t%.2f%%\n", processes[i].name, processes[i].pid, processes[i].cpu_usage);
    }
    return 0;
}