//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NUM_PROCESSES 100

typedef struct process_info {
    int pid;
    char name[64];
    int memory_usage;
} ProcessInfo;

ProcessInfo processes[MAX_NUM_PROCESSES];
int num_processes = 0;

void add_process(int pid, char* name, int memory_usage) {
    if (num_processes >= MAX_NUM_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].name, name, sizeof(processes[num_processes].name));
    processes[num_processes].memory_usage = memory_usage;

    num_processes++;
}

void update_process_memory_usage(int pid, int new_memory_usage) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].memory_usage = new_memory_usage;
            break;
        }
    }
}

void print_process_info() {
    printf("Process ID\tName\t\tMemory Usage (KB)\n");

    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t\t%d\n", processes[i].pid, processes[i].name, processes[i].memory_usage);
    }
}

int main() {
    char command[100];
    bool is_running = true;

    while (is_running) {
        printf("Enter command (list, add, update, exit): ");
        scanf("%s", command);

        if (strcmp(command, "list") == 0) {
            print_process_info();
        } else if (strcmp(command, "add") == 0) {
            int pid;
            char name[64];
            int memory_usage;

            printf("Enter process ID: ");
            scanf("%d", &pid);

            printf("Enter process name: ");
            scanf("%s", name);

            printf("Enter process memory usage (in KB): ");
            scanf("%d", &memory_usage);

            add_process(pid, name, memory_usage);
        } else if (strcmp(command, "update") == 0) {
            int pid;
            int new_memory_usage;

            printf("Enter process ID: ");
            scanf("%d", &pid);

            printf("Enter new memory usage (in KB): ");
            scanf("%d", &new_memory_usage);

            update_process_memory_usage(pid, new_memory_usage);
        } else if (strcmp(command, "exit") == 0) {
            is_running = false;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}