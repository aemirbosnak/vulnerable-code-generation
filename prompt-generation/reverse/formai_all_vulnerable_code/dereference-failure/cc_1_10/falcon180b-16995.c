//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PROCESSES 10
#define MAX_COMMAND_LENGTH 100

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void add_process(char* command) {
    if (num_processes < MAX_PROCESSES) {
        strcpy(processes[num_processes].command, command);
        processes[num_processes].pid = fork();

        if (processes[num_processes].pid == -1) {
            printf("Error forking process.\n");
            exit(1);
        } else if (processes[num_processes].pid == 0) {
            execlp(processes[num_processes].command, processes[num_processes].command, NULL);
            printf("Error executing %s.\n", processes[num_processes].command);
            exit(1);
        }

        num_processes++;
    } else {
        printf("Maximum number of processes reached.\n");
    }
}

void remove_process(int pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            waitpid(pid, NULL, 0);
            num_processes--;
            memmove(&processes[i], &processes[i+1], sizeof(Process) * (num_processes - i - 1));
            break;
        }
    }
}

int main() {
    int choice, status;

    while (1) {
        printf("\n");
        printf("1. Add process\n");
        printf("2. Remove process\n");
        printf("3. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter command: ");
            scanf("%s", processes[num_processes-1].command);
            add_process(processes[num_processes-1].command);
            break;

        case 2:
            printf("Enter PID: ");
            scanf("%d", &status);
            remove_process(status);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}