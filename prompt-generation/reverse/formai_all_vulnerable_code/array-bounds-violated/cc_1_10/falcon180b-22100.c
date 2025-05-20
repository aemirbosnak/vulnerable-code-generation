//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

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

    // Get the current number of processes
    fp = popen("ps -ef | grep -v grep | wc -l", "r");
    if (fp == NULL) {
        printf("Error: Cannot open process list.\n");
        exit(1);
    }
    fscanf(fp, "%d", &num_processes);
    pclose(fp);

    // Get the name, PID, and RAM usage for each process
    fp = popen("ps -ef | grep -v grep", "r");
    if (fp == NULL) {
        printf("Error: Cannot open process list.\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_processes >= MAX_PROCESSES) {
            printf("Error: Too many processes. Increase MAX_PROCESSES.\n");
            exit(1);
        }
        token = strtok(line, " ");
        strcpy(processes[num_processes].name, token);
        processes[num_processes].pid = atoi(token);
        token = strtok(NULL, " ");
        processes[num_processes].ram_usage = atoi(token);
        num_processes++;
    }
    pclose(fp);

    // Sort the processes by RAM usage
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[j].ram_usage > processes[i].ram_usage) {
                struct process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Print the RAM usage for each process
    printf("Process Name | PID | RAM Usage (KB)\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%-20s | %-5d | %-10d\n", processes[i].name, processes[i].pid, processes[i].ram_usage);
    }

    return 0;
}