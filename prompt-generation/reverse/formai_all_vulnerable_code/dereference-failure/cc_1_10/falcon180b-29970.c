//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define MAX_ENVIRONMENT_VARIABLES 256

int main(int argc, char **argv) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <command> [arguments]\n", argv[0]);
        exit(1);
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    char *arguments[MAX_ARGUMENTS];
    int argument_count = 0;

    for(int i = 2; i < argc; i++) {
        if(argument_count >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            exit(1);
        }
        arguments[argument_count++] = argv[i];
    }

    char **environment = NULL;
    if(getenv("PATH")) {
        environment = malloc(MAX_ENVIRONMENT_VARIABLES);
        memset(environment, 0, MAX_ENVIRONMENT_VARIABLES);
        strcpy(environment[0], "PATH=");
        strcat(environment[0], getenv("PATH"));
    }

    pid_t pid = fork();
    if(pid == 0) {
        if(execve(command, arguments, environment) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }

    return 0;
}