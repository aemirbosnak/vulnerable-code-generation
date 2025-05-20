//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
char **split_arguments(char *arguments);
int execute_command(char **argv);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline character

        argv = split_command(input);
        if (argv == NULL) {
            printf("Invalid command\n");
            continue;
        }

        int status = execute_command(argv);
        if (status == -1) {
            printf("Error executing command\n");
        }

    }

    return 0;
}

char **split_command(char *command) {
    char *token = strtok(command, DELIM);
    int count = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char *));

    while (token!= NULL) {
        argv[count] = malloc(strlen(token) + 1);
        strcpy(argv[count], token);
        count++;
        token = strtok(NULL, DELIM);
    }
    argv[count] = NULL;

    return argv;
}

char **split_arguments(char *arguments) {
    char *token = strtok(arguments, DELIM);
    int count = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char *));

    while (token!= NULL) {
        argv[count] = malloc(strlen(token) + 1);
        strcpy(argv[count], token);
        count++;
        token = strtok(NULL, DELIM);
    }
    argv[count] = NULL;

    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        return -1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}