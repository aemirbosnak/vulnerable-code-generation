//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    char **args = split_string(input);
    int status = execute_command(args);
    if (status == -1) {
        printf("Command not found.\n");
    }
    return 0;
}

char **split_string(char *str) {
    int len = strlen(str);
    int count = 0;
    char **tokens = malloc(sizeof(char *) * (len + 1));
    char *token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;
    if (args[0] == NULL) {
        return -1;
    }
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }
    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
    return status;
}