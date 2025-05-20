//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(command, DELIM);

    while (token!= NULL && argc < MAX_ARGUMENTS) {
        arguments[argc++] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    arguments[argc] = NULL;
    return arguments;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        fprintf(stderr, "Command not found.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

void loop(char *prompt) {
    char input[MAX_COMMAND_LENGTH];
    char *command;
    char **arguments;
    int result;

    while (1) {
        printf("%s", prompt);
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        command = strtok(input, "\n");
        arguments = split_command(command);
        result = execute_command(arguments);

        free(arguments[0]);
        free(arguments);
    }
}

int main(int argc, char *argv[]) {
    loop("> ");
    return 0;
}