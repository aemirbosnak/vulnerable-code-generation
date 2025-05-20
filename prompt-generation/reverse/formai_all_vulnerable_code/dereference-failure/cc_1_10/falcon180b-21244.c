//Falcon-180B DATASET v1.0 Category: System administration ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
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

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
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
    char **arguments;

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    arguments = split_string(input);

    if (arguments[0] == NULL) {
        printf("Invalid command\n");
    } else {
        execute_command(arguments);
    }

    return 0;
}