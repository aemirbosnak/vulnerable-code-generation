//Falcon-180B DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

int main() {
    char *command;
    char **arguments;
    int num_arguments;
    pid_t pid;
    int status;

    printf("Enter command to execute: ");
    scanf("%s", command);

    num_arguments = 0;
    arguments = (char **) malloc(MAX_ARGUMENTS * sizeof(char *));

    char *token = strtok(command, " ");
    while (token!= NULL) {
        arguments[num_arguments] = token;
        num_arguments++;
        if (num_arguments == MAX_ARGUMENTS) {
            printf("Too many arguments\n");
            exit(1);
        }
        token = strtok(NULL, " ");
    }

    pid = fork();
    if (pid == -1) {
        printf("Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        execvp(arguments[0], arguments);
        printf("Execvp failed\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        printf("Child exited with status %d\n", WEXITSTATUS(status));
    }

    return 0;
}