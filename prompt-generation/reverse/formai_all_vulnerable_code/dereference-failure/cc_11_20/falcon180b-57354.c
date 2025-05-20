//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 256
#define MAX_ARGC 256
#define MAX_ARG_LENGTH 1024
#define MAX_ENV_LENGTH 1024
#define MAX_ENV_VARIABLES 256

char *prompt = ">> ";
char *delimiter = " \t\n\r\f\v";
char **environ;

int main() {
    char input[MAX_LINE_LENGTH];
    char *command;
    char *argv[MAX_ARGC];
    int argc;
    char *envp[MAX_ENV_VARIABLES];
    int envc;
    int status;

    environ = malloc(sizeof(char *) * MAX_ENV_VARIABLES);
    if (environ == NULL) {
        printf("Error: Unable to allocate memory for environment variables.\n");
        exit(1);
    }

    envc = 0;
    while ((envp[envc] = strtok(environ[envc], delimiter))!= NULL) {
        envc++;
    }

    while (1) {
        printf("%s", prompt);
        fgets(input, MAX_LINE_LENGTH, stdin);

        command = strtok(input, delimiter);
        if (command == NULL || strcmp(command, "exit") == 0) {
            break;
        }

        argc = 0;
        argv[argc++] = command;
        while ((command = strtok(NULL, delimiter))!= NULL) {
            if (argc >= MAX_ARGC) {
                printf("Error: Too many arguments.\n");
                exit(1);
            }
            argv[argc++] = command;
        }

        status = system(command);
        if (status == -1) {
            printf("Error: Command not found.\n");
        } else if (WIFEXITED(status)) {
            printf("Command exited with status %d.\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Command killed by signal %d.\n", WTERMSIG(status));
        } else {
            printf("Command terminated abnormally.\n");
        }
    }

    free(environ);
    return 0;
}