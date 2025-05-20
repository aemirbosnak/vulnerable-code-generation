//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PROCESSES 10
#define MAX_COMMAND_LENGTH 256

typedef struct process {
    pid_t pid;
    int status;
    char command[MAX_COMMAND_LENGTH];
} Process;

void execute_command(char *command) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Error forking process\n");
        exit(1);
    } else if (pid == 0) {
        execlp(command, command, NULL);
        printf("Error executing command\n");
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (num_processes < MAX_PROCESSES) {
        printf("Enter command to execute (or type 'done' to finish): ");
        scanf("%s", processes[num_processes].command);

        if (strcmp(processes[num_processes].command, "done") == 0) {
            break;
        }

        execute_command(processes[num_processes].command);
        num_processes++;
    }

    for (int i = 0; i < num_processes; i++) {
        waitpid(processes[i].pid, &processes[i].status, 0);
        printf("Process %d finished with status %d\n", processes[i].pid, processes[i].status);
    }

    return 0;
}