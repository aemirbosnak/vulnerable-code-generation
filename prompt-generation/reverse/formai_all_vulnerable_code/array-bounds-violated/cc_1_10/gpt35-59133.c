//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256
#define MAX_ARG_COUNT 10

void execute_command(char *command);

int main() {
    char command[MAX_CMD_LEN];
    printf("Custom UNIX-like Shell. Type 'exit' to quit.\n");
    while (1) {
        printf("$> ");
        fgets(command, MAX_CMD_LEN, stdin);
        // Remove trailing newline character
        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }
        if (strcmp(command, "exit") == 0) {
            break;
        }
        execute_command(command);
    }
    return 0;
}

void execute_command(char *command) {
    // Split command into arguments
    char *token;
    char *args[MAX_ARG_COUNT];
    int arg_count = 0;
    token = strtok(command, " ");
    while (token != NULL) {
        args[arg_count] = token;
        arg_count++;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;
    // Fork a new process to execute the command
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error: Failed to fork a new process.\n");
        return;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            printf("Error: Failed to execute command.\n");
        }
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        pid_t wait_pid = waitpid(pid, &status, 0);
        if (wait_pid == -1) {
            printf("Error: Failed to wait for child process.\n");
            return;
        }
    }
}