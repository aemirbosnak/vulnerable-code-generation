//Falcon-180B DATASET v1.0 Category: System administration ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " "

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;
    char *command;
    char *arguments[MAX_ARGUMENTS];
    int num_arguments;

    if (argc == 1) {
        printf("Usage: %s command [arguments]\n", argv[0]);
        return 1;
    }

    command = argv[1];
    num_arguments = argc - 2;

    if (num_arguments > MAX_ARGUMENTS) {
        printf("Too many arguments.\n");
        return 1;
    }

    command = strdup(command);
    arguments[0] = strtok(command, DELIM);

    for (int i = 1; i < num_arguments; i++) {
        arguments[i] = strtok(NULL, DELIM);
    }

    pid = fork();

    if (pid == -1) {
        printf("Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        execvp(arguments[0], arguments);
        printf("execvp failed.\n");
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}