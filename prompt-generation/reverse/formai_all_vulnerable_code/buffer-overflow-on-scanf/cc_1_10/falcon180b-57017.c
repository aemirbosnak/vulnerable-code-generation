//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_PROCESSES 10

struct process {
    char name[20];
    int pid;
};

void print_processes(struct process processes[], int num_processes) {
    printf("Active processes:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s (PID: %d)\n", processes[i].name, processes[i].pid);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        printf("Enter command (run/kill/exit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "run") == 0) {
            if (num_processes >= MAX_PROCESSES) {
                printf("Maximum number of processes reached.\n");
            } else {
                printf("Enter process name: ");
                scanf("%s", processes[num_processes].name);
                processes[num_processes].pid = fork();

                if (processes[num_processes].pid == 0) {
                    // Child process
                    execlp("./child_process", "child_process", NULL);
                    exit(1);
                } else if (processes[num_processes].pid < 0) {
                    printf("Error forking process.\n");
                } else {
                    num_processes++;
                }
            }
        } else if (strcmp(command, "kill") == 0) {
            printf("Enter PID to kill: ");
            int pid;
            scanf("%d", &pid);

            for (int i = 0; i < num_processes; i++) {
                if (processes[i].pid == pid) {
                    kill(pid, SIGKILL);
                    processes[i].pid = 0;
                    num_processes--;
                    break;
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }

        print_processes(processes, num_processes);
    }

    return 0;
}