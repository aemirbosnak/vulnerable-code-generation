//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    argv = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH + 1));
    if (argv == NULL) {
        fprintf(stderr, "Error: malloc failed.\n");
        exit(1);
    }

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_COMMAND_LENGTH) {
            fprintf(stderr, "Error: command too long.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "Error: empty command.\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error: execvp failed.\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            fprintf(stderr, "Error: child process terminated abnormally.\n");
            return 1;
        }
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        argv = split_command(input);
        if (argv[0] == NULL) {
            continue;
        }
        execute_command(argv);
    }

    return 0;
}