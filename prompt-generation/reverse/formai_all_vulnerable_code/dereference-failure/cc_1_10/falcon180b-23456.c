//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 4096
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    printf("Enter commands. Type 'exit' to quit.\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        args = split_command(input);
        status = execute_command(args);

        if (status == 0) {
            printf("Command executed successfully.\n");
        } else {
            printf("Command failed with status %d.\n", status);
        }

        free(args);
    }

    return 0;
}