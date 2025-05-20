//Falcon-180B DATASET v1.0 Category: System administration ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_ENVIRONMENT_VARIABLES 20

typedef struct {
    char *name;
    char *value;
} environment_variable_t;

int main(int argc, char *argv[]) {
    pid_t child_pid;
    int status;
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    environment_variable_t environment_variables[MAX_ENVIRONMENT_VARIABLES];
    int num_arguments = 0;
    int num_environment_variables = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [arguments...]\n", argv[0]);
        return 1;
    }

    strcpy(command, argv[1]);
    for (int i = 2; i < argc; i++) {
        arguments[num_arguments] = argv[i];
        num_arguments++;
    }

    for (int i = 0; i < num_arguments; i++) {
        if (strstr(arguments[i], "=")) {
            char *name = strtok(arguments[i], "=");
            char *value = strtok(NULL, "=");
            environment_variables[num_environment_variables].name = name;
            environment_variables[num_environment_variables].value = value;
            num_environment_variables++;
        }
    }

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        return 1;
    } else if (child_pid == 0) {
        for (int i = 0; i < num_environment_variables; i++) {
            if (setenv(environment_variables[i].name, environment_variables[i].value, 1) == -1) {
                perror("setenv");
                return 1;
            }
        }

        execvp(command, arguments);
        perror("execvp");
        return 1;
    } else {
        waitpid(child_pid, &status, 0);
    }

    return 0;
}