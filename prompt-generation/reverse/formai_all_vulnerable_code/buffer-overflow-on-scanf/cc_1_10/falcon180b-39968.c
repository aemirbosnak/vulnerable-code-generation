//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 100

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int pid;
    int status;
} process_t;

void add_process(process_t *processes, int num_processes, char *command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    process_t *new_process = &processes[num_processes];
    strncpy(new_process->command, command, MAX_COMMAND_LENGTH);
    new_process->pid = -1;
    new_process->status = 0;

    num_processes++;
}

void remove_process(process_t *processes, int num_processes, int pid) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = 1;
            break;
        }
    }
}

void update_processes(process_t *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].status == 1) {
            printf("Process %s (PID %d) has exited.\n", processes[i].command, processes[i].pid);
        }
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter a command to add or type 'exit' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        add_process(processes, num_processes, input);
    }

    while (1) {
        system("clear");
        printf("Process Viewer\n");

        for (int i = 0; i < num_processes; i++) {
            printf("%s (PID %d)\n", processes[i].command, processes[i].pid);
        }

        update_processes(processes, num_processes);

        printf("\nPress any key to continue...\n");
        getchar();
    }

    return 0;
}