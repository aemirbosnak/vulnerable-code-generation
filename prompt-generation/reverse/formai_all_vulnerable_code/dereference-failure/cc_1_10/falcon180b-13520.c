//Falcon-180B DATASET v1.0 Category: System administration ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " "

int main(int argc, char *argv[]) {
    pid_t child_pid;
    int status;
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int num_arguments = 0;

    if (argc < 2) {
        printf("Usage: %s command [argument1] [argument2]...\n", argv[0]);
        return 1;
    }

    strncpy(command, argv[1], MAX_COMMAND_LENGTH - 1);
    command[MAX_COMMAND_LENGTH - 1] = '\0';

    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        arguments[num_arguments] = strdup(token);
        num_arguments++;
        if (num_arguments >= MAX_ARGUMENTS) {
            printf("Too many arguments.\n");
            return 1;
        }
        token = strtok(NULL, DELIM);
    }

    child_pid = fork();

    if (child_pid == -1) {
        printf("Fork failed.\n");
        return 1;
    } else if (child_pid == 0) {
        execvp(arguments[0], arguments);
        printf("Exec failed.\n");
        return 1;
    } else {
        waitpid(child_pid, &status, 0);
        return 0;
    }
}