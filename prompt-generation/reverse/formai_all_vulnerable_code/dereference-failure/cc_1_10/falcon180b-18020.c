//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argc++;
        argv = realloc(argv, argc * sizeof(char*));
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "Error: No command specified.\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    int background = 0;
    int exit_shell = 0;

    while (!exit_shell) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        argv = split_command(input);
        if (argv[0] == NULL) {
            continue;
        }

        if (strcmp(argv[0], "exit") == 0) {
            exit_shell = 1;
        } else if (strcmp(argv[0], "bg") == 0 && argv[1]!= NULL) {
            background = 1;
            pid_t pid = fork();
            if (pid == -1) {
                perror("fork");
            } else if (pid == 0) {
                setsid();
                execute_command(argv);
                exit(EXIT_SUCCESS);
            }
        } else if (strcmp(argv[0], "jobs") == 0) {
            printf("No background jobs.\n");
        } else {
            execute_command(argv);
        }
    }

    return 0;
}