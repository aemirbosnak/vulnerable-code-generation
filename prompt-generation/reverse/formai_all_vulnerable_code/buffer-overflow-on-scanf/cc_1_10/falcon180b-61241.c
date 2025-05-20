//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 20
#define MAX_COMMAND_LENGTH 80

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    int pid;
    int status;
} Process;

void update_process_list(Process *processes, int num_processes) {
    int num_running_processes = 0;
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].status == 0) {
            printf("Process %d: %s\n", processes[i].pid, processes[i].name);
            num_running_processes++;
        }
    }
    if (num_running_processes == 0) {
        printf("No running processes\n");
    }
}

void kill_process(Process *processes, int num_processes, int pid) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = 1;
            break;
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        printf("Enter command (list, kill, exit): ");
        char command[MAX_COMMAND_LENGTH];
        scanf("%s", command);

        if (strcmp(command, "list") == 0) {
            update_process_list(processes, num_processes);
        } else if (strcmp(command, "kill") == 0) {
            printf("Enter PID: ");
            int pid;
            scanf("%d", &pid);
            kill_process(processes, num_processes, pid);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}