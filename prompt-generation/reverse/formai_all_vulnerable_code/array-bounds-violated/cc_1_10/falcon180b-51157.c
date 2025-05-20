//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_PROCESSES 10
#define DELIM " "

typedef struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} Process;

void print_processes(Process processes[], int num_processes) {
    printf("PID\tCOMMAND\tSTATUS\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].command, processes[i].status);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *token = strtok(input, DELIM);
        if (token == NULL) {
            continue;
        }

        pid_t pid = fork();

        if (pid == -1) {
            printf("Fork failed\n");
            continue;
        } else if (pid == 0) {
            processes[num_processes].pid = getpid();
            strcpy(processes[num_processes].command, input);
            num_processes++;

            if (num_processes >= MAX_PROCESSES) {
                printf("Maximum number of processes reached\n");
                exit(1);
            }

            execlp(token, token, NULL);
            perror("execlp");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
            processes[num_processes - 1].status = status;
        }
    }

    return 0;
}