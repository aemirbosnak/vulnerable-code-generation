//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    argv = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2 + 1));
    if (argv == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv[argc] = token;
        argc++;
        if (argc >= MAX_COMMAND_LENGTH / 2) {
            fprintf(stderr, "Error: command too long\n");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: fork failed\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error: execvp failed: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            fprintf(stderr, "Error: command terminated abnormally\n");
            return 1;
        }
    }
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    printf("Enter commands, type 'exit' to quit:\n");

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        args = split_command(input);
        status = execute_command(args);
        if (status!= 0) {
            fprintf(stderr, "Command returned status %d\n", status);
        }
    }

    return 0;
}