//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **args);
void print_prompt(void);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t child_pid;

    print_prompt();

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        args = split_command(input);
        child_pid = fork();

        if (child_pid == -1) {
            fprintf(stderr, "Error forking: %s\n", strerror(errno));
        } else if (child_pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            waitpid(child_pid, NULL, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = malloc(MAX_COMMAND_LENGTH * sizeof(char*));

    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

pid_t fork(void) {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void print_prompt(void) {
    printf("> ");
}