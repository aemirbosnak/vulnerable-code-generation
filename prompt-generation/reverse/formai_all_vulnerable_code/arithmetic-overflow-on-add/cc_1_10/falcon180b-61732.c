//Falcon-180B DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARG_LENGTH 512

typedef struct {
    char *command;
    char **args;
    int argc;
} command_t;

int execute_command(command_t *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(command->command, command->args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            return 128 + WTERMSIG(status);
        } else {
            return 1;
        }
    }
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    command_t command;

    printf("Enter commands to execute. Type 'exit' to quit.\n");

    while (1) {
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        command.command = strtok(input, " ");
        command.argc = 0;
        command.args = malloc(MAX_ARG_LENGTH * sizeof(char *));

        char *token = strtok(NULL, " ");
        while (token!= NULL) {
            command.args[command.argc++] = strdup(token);
            token = strtok(NULL, " ");
        }

        int status = execute_command(&command);
        if (status!= 0) {
            printf("Command failed with status %d\n", status);
        }
    }

    return 0;
}