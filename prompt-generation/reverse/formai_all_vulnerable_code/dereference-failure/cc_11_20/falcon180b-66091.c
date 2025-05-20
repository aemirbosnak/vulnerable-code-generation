//Falcon-180B DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100

int main(int argc, char **argv) {
    char *command = NULL;
    char **arguments = NULL;
    int num_arguments = 0;
    int status;
    pid_t pid;

    if (argc < 2) {
        printf("Usage: %s command [argument1] [argument2]...\n", argv[0]);
        exit(1);
    }

    command = strdup(argv[1]);
    if (command == NULL) {
        printf("Error: could not allocate memory for command.\n");
        exit(1);
    }

    num_arguments = argc - 2;
    arguments = (char **)malloc(num_arguments * sizeof(char *));
    if (arguments == NULL) {
        printf("Error: could not allocate memory for arguments.\n");
        exit(1);
    }

    for (int i = 0; i < num_arguments; i++) {
        arguments[i] = strdup(argv[i + 2]);
        if (arguments[i] == NULL) {
            printf("Error: could not allocate memory for argument %d.\n", i + 1);
            exit(1);
        }
    }

    pid = fork();
    if (pid == -1) {
        printf("Error: could not fork.\n");
        exit(1);
    } else if (pid == 0) {
        execvp(command, arguments);
        printf("Error: could not execute command.\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status)!= 0) {
            printf("Error: command exited with non-zero status.\n");
        }
    }

    for (int i = 0; i < num_arguments; i++) {
        free(arguments[i]);
    }
    free(arguments);
    free(command);

    return 0;
}