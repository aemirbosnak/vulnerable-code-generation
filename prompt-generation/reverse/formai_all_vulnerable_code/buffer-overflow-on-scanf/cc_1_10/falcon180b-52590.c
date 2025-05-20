//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct process {
    int pid;
    char name[20];
    int ram_usage;
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void add_process(int pid, char* name, int ram_usage) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }
    processes[num_processes].pid = pid;
    strcpy(processes[num_processes].name, name);
    processes[num_processes].ram_usage = ram_usage;
    num_processes++;
}

void remove_process(int pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            num_processes--;
            break;
        }
    }
}

void update_ram_usage(int pid, int new_ram_usage) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].ram_usage = new_ram_usage;
            break;
        }
    }
}

void print_processes() {
    int i;
    printf("Processes:\n");
    for (i = 0; i < num_processes; i++) {
        printf("PID: %d, Name: %s, RAM Usage: %d\n", processes[i].pid, processes[i].name, processes[i].ram_usage);
    }
}

int main() {
    int pid;
    char name[20];
    int ram_usage;

    while (1) {
        printf("Enter PID: ");
        scanf("%d", &pid);
        printf("Enter Name: ");
        scanf("%s", name);
        printf("Enter RAM Usage: ");
        scanf("%d", &ram_usage);
        add_process(pid, name, ram_usage);
    }

    return 0;
}