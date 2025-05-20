//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LEN 50

typedef struct {
    int pid;
    char process_name[MAX_PROCESS_NAME_LEN];
    int memory_usage;
} ProcessInfo;

ProcessInfo processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(int pid, char *process_name, int memory_usage) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Max number of processes reached.\n");
        return;
    }

    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].process_name, process_name, MAX_PROCESS_NAME_LEN);
    processes[num_processes].memory_usage = memory_usage;

    num_processes++;
}

void print_processes() {
    printf("Process ID\tProcess Name\tMemory Usage (KB)\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].process_name, processes[i].memory_usage);
    }
}

int main() {
    system("CLS");
    printf("Welcome to Sherlock's RAM Usage Monitor!\n\n");

    char command[100];
    while (1) {
        system("CLS");
        printf("Enter a command:\n");
        scanf("%s", command);

        if (strcmp(command, "list") == 0) {
            print_processes();
        } else if (strcmp(command, "add") == 0) {
            int pid;
            char process_name[MAX_PROCESS_NAME_LEN];
            int memory_usage;

            printf("Enter process ID:\n");
            scanf("%d", &pid);

            printf("Enter process name:\n");
            scanf("%s", process_name);

            printf("Enter memory usage (in KB):\n");
            scanf("%d", &memory_usage);

            add_process(pid, process_name, memory_usage);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}