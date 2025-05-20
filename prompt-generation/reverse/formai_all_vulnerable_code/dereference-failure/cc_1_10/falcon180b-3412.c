//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork();
int execute_command(char **arguments);
void print_prompt();

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_command(input);
        if (arguments == NULL) {
            continue;
        }

        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
        } else if (child_pid == 0) {
            execute_command(arguments);
            exit(0);
        } else {
            int status;
            waitpid(child_pid, &status, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char *token = strtok(command, DELIM);
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));

    while (token!= NULL && argc < MAX_ARGUMENTS) {
        arguments[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    arguments[argc] = NULL;
    return arguments;
}

pid_t fork() {
    return fork();
}

int execute_command(char **arguments) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            return 1;
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}

void print_prompt() {
    printf("> ");
}