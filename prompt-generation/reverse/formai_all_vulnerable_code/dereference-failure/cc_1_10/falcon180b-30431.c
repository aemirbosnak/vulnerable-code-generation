//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **arguments);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;
    int status;

    printf("Welcome to the Unix-like shell!\n");

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        arguments = split_string(input_buffer);

        status = execute_command(arguments);

        if (status == 1) {
            printf("Command not found.\n");
        } else if (status == 127) {
            printf("Command not executable.\n");
        }
    }

    return 0;
}

char **split_string(char *string) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL) {
        arguments[argc] = malloc(strlen(token) + 1);
        strcpy(arguments[argc], token);
        argc++;
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(127);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}