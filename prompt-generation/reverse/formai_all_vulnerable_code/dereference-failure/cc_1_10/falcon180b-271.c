//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} Process;

int num_processes = 0;
Process *processes = NULL;

void add_process(pid_t pid, char *command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes exceeded.\n");
        return;
    }

    Process *new_process = malloc(sizeof(Process));
    new_process->pid = pid;
    strncpy(new_process->command, command, MAX_COMMAND_LENGTH);
    processes[num_processes++] = *new_process;
}

void print_processes() {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    processes = malloc(sizeof(Process) * MAX_PROCESSES);

    while (1) {
        print_processes();

        char input[MAX_COMMAND_LENGTH];
        printf("Enter command to run or type 'q' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break;
        }

        pid_t pid = fork();
        if (pid == -1) {
            printf("Error: Fork failed.\n");
            continue;
        } else if (pid == 0) {
            execlp(input, input, NULL);
            perror("execlp");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
            add_process(pid, input);
        }
    }

    free(processes);
    return 0;
}