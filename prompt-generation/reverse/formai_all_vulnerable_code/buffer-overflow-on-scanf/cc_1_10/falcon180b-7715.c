//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void add_process(process_t *processes, int num_processes, pid_t pid, char *command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH);
    processes[num_processes].pid = pid;
    num_processes++;
}

int main() {
    pid_t pid;
    int status;
    char input[MAX_COMMAND_LENGTH];
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    printf("Enter command to execute: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char *token = strtok(input, " ");
    while (token!= NULL) {
        if (num_processes >= MAX_PROCESSES) {
            printf("Error: Maximum number of processes reached.\n");
            return 1;
        }

        pid_t child_pid = fork();
        if (child_pid == -1) {
            printf("Error: Fork failed.\n");
            return 1;
        } else if (child_pid == 0) {
            execlp(token, token, NULL);
            printf("Error: Execlp failed.\n");
            return 1;
        } else {
            add_process(processes, num_processes, child_pid, token);
        }

        token = strtok(NULL, " ");
        num_processes++;
    }

    while (1) {
        printf("\n");
        for (int i = 0; i < num_processes; i++) {
            printf("%d: %s\n", processes[i].pid, processes[i].command);
        }

        printf("Enter PID to kill: ");
        scanf("%d", &pid);

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].pid == pid) {
                kill(processes[i].pid, SIGTERM);
                waitpid(processes[i].pid, &status, 0);
                processes[i].pid = 0;
            }
        }
    }

    return 0;
}