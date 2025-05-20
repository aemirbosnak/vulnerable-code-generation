//Falcon-180B DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [arguments...]\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    char *args[MAX_ARGUMENTS];
    int num_args = 0;

    char *token = strtok(command, " ");
    while (token!= NULL) {
        args[num_args++] = token;
        token = strtok(NULL, " ");
    }

    args[num_args] = NULL;

    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Error: Could not fork\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        execvp(args[0], args);
        fprintf(stderr, "Error: Could not execute command\n");
        return 1;
    } else {
        // Parent process
        waitpid(pid, &status, 0);
        return status;
    }
}