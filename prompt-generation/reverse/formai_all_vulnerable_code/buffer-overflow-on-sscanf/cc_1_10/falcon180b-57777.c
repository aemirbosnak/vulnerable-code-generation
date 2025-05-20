//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 100

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int memory_usage;
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void add_process(char *name, int pid, int memory_usage) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    strncpy(processes[num_processes].name, name, MAX_PROCESS_NAME_LENGTH);
    processes[num_processes].pid = pid;
    processes[num_processes].memory_usage = memory_usage;
    num_processes++;
}

void print_processes() {
    printf("Processes:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s (PID %d) - %d bytes\n", processes[i].name, processes[i].pid, processes[i].memory_usage);
    }
}

int main() {
    char command[512];
    while (1) {
        printf("> ");
        fgets(command, 512, stdin);

        if (strcmp(command, "list") == 0) {
            print_processes();
        } else if (sscanf(command, "add %s %d %d", processes[num_processes].name, &processes[num_processes].pid, &processes[num_processes].memory_usage) == 3) {
            add_process(processes[num_processes].name, processes[num_processes].pid, processes[num_processes].memory_usage);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}