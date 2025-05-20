//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void add_process(pid_t pid, char *command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH);
    num_processes++;
}

void remove_process(pid_t pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            memmove(&processes[i], &processes[i + 1], sizeof(Process) * (num_processes - i - 1));
            num_processes--;
            break;
        }
    }
}

void print_processes() {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    signal(SIGCHLD, SIG_IGN);

    while (1) {
        printf("Enter command to execute or type 'list' to view processes:\n");
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *command = strtok(input, " ");
        if (strcmp(command, "list") == 0) {
            print_processes();
        } else {
            pid_t pid = fork();
            if (pid == -1) {
                perror("fork");
            } else if (pid == 0) {
                execlp(command, command, NULL);
                perror("execlp");
                exit(1);
            } else {
                add_process(pid, command);
            }
        }
    }

    return 0;
}