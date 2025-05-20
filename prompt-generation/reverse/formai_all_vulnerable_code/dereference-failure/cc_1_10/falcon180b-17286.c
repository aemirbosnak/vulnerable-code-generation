//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *input);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Unix-like Shell\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_string(input);
        int status = execute_command(args);
        if (status == 1) {
            printf("Child process terminated abnormally\n");
        }
        free(args);
    }
    return 0;
}

char **split_string(char *input) {
    char **args = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2));
    int count = 0;
    char *token = strtok(input, DELIM);
    while (token!= NULL) {
        args[count++] = token;
        if (count >= MAX_COMMAND_LENGTH / 2) {
            break;
        }
        token = strtok(NULL, DELIM);
    }
    args[count] = NULL;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;
    if (args[0] == NULL) {
        return 1;
    }
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
    return 0;
}