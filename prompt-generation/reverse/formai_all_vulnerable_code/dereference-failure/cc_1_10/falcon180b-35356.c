//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS_LENGTH 1024

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    char args[MAX_ARGS_LENGTH];
    pid_t pid;
    int status;
    int exit_code;
} Process;

void print_process_info(Process *process) {
    printf("Command: %s\nArguments: %s\nPID: %d\nStatus: %d\nExit code: %d\n", process->command, process->args, process->pid, process->status, process->exit_code);
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        printf("\nEnter a command or type 'list' to view running processes:\n");
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "list") == 0) {
            for (int i = 0; i < num_processes; i++) {
                print_process_info(&processes[i]);
            }
        } else {
            char *command = strtok(input, " ");
            char *args = strtok(NULL, " ");

            if (num_processes >= MAX_PROCESSES) {
                printf("Too many processes running.\n");
            } else {
                processes[num_processes].command[0] = '\0';
                strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH - 1);
                processes[num_processes].args[0] = '\0';
                strncpy(processes[num_processes].args, args, MAX_ARGS_LENGTH - 1);

                pid_t child_pid = fork();

                if (child_pid == 0) {
                    execlp(command, command, args, NULL);
                    exit(1);
                } else if (child_pid < 0) {
                    printf("Error forking process.\n");
                } else {
                    processes[num_processes].pid = child_pid;
                    processes[num_processes].status = 0;
                    processes[num_processes].exit_code = 0;
                    num_processes++;
                }
            }
        }
    }

    return 0;
}