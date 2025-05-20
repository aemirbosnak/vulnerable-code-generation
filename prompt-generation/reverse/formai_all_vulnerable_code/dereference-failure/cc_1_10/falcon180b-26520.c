//Falcon-180B DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100
#define DELIM " "

int main(int argc, char **argv) {
    pid_t pid;
    int status;
    char **arguments = NULL;
    int argument_count = 0;
    char command[MAX_COMMAND_LENGTH];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [argument1] [argument2]...\n", argv[0]);
        return 1;
    }

    strcpy(command, argv[1]);
    argument_count = argc - 2;
    arguments = malloc(sizeof(char *) * argument_count);

    if (arguments == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        return 1;
    }

    for (int i = 0; i < argument_count; i++) {
        arguments[i] = strtok(argv[i + 2], DELIM);
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        execvp(command, arguments);
        fprintf(stderr, "Error: %s command not found.\n", command);
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }

    for (int i = 0; i < argument_count; i++) {
        free(arguments[i]);
    }
    free(arguments);

    return 0;
}