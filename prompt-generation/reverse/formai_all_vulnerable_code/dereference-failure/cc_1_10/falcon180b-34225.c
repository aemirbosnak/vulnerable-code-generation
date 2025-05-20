//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **arguments);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;
    int status;

    printf("Welcome to the Basic Unix-like Shell!\n");

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_string(input);
        if(arguments == NULL) {
            printf("Error: Invalid command\n");
            continue;
        }

        pid = fork();
        if(pid == -1) {
            printf("Error: Fork failed\n");
            exit(1);
        } else if(pid == 0) {
            execute_command(arguments);
            exit(0);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(string, DELIM);

    while(token!= NULL && count < MAX_ARGUMENTS) {
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

    if(arguments[0] == NULL) {
        printf("Error: Command not found\n");
        return 1;
    }

    pid = fork();
    if(pid == -1) {
        printf("Error: Fork failed\n");
        return 1;
    } else if(pid == 0) {
        if(execvp(arguments[0], arguments) == -1) {
            printf("Error: %s not found\n", arguments[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}