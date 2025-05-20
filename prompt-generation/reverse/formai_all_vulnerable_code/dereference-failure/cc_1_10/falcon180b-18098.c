//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str);
pid_t fork();
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t child_pid;

    printf("Welcome to the Basic Unix-like Shell\n");

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        args = split_string(input);

        if(args[0] == NULL)
            continue;

        child_pid = fork();

        if(child_pid == -1) {
            perror("fork");
            exit(1);
        } else if(child_pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            wait(NULL);
        }
    }

    return 0;
}

char **split_string(char *str) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    token = strtok(str, DELIM);

    while(token!= NULL) {
        tokens[position] = token;
        position++;

        if(position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}

pid_t fork() {
    return fork();
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL)
        return 1;

    pid = fork();

    if(pid == -1) {
        perror("fork");
        return 1;
    } else if(pid == 0) {
        if(execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}