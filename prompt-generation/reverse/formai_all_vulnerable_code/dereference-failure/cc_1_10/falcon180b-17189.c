//Falcon-180B DATASET v1.0 Category: System administration ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10

typedef struct {
    char **args;
    int num_args;
} command_t;

void execute_command(command_t *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        execvp(command->args[0], command->args);
        perror("execvp");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_input(char *input) {
    char *token;
    command_t command;

    command.num_args = 0;
    token = strtok(input, " ");
    while (token!= NULL) {
        if (command.num_args >= MAX_ARGS) {
            printf("Error: Too many arguments.\n");
            return;
        }
        command.args[command.num_args++] = token;
        token = strtok(NULL, " ");
    }
    if (command.num_args == 0) {
        printf("Error: No command specified.\n");
        return;
    }
    execute_command(&command);
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        handle_input(input);
    }

    return 0;
}