//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **arguments);
void signal_handler(int signal);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;
    int status;

    printf("Enter commands, type 'exit' to quit.\n");

    while (1) {
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        arguments = split_string(input);
        pid = fork();

        if (pid == 0) {
            execute_command(arguments);
            exit(0);
        } else if (pid < 0) {
            perror("fork");
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(string, DELIM);

    while (token!= NULL && count < MAX_ARGUMENTS) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void signal_handler(int signal) {
    switch (signal) {
        case SIGINT:
        case SIGTERM:
            printf("\nExiting...\n");
            exit(0);
        default:
            break;
    }
}