//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define MAX_ARGUMENTS 10

char **split(char *line);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split(input);
        status = execute_command(args);

        for (int i = 0; i < status; i++) {
            wait(NULL);
        }
    }

    return 0;
}

char **split(char *line) {
    char delimiter[2] = " ";
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    int argc = 0;
    char *token;

    for (token = strtok(line, delimiter); token!= NULL; token = strtok(NULL, delimiter)) {
        tokens[argc] = token;
        argc++;

        if (argc >= MAX_ARGUMENTS) {
            break;
        }
    }

    tokens[argc] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status = 0;

    if (args[0] == NULL) {
        return 0;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 1;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            printf("Expected argument to 'cd'\n");
        } else {
            if (chdir(args[1])!= 0) {
                perror("chdir");
            }
        }
    } else if (strcmp(args[0], "pwd") == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd))!= NULL) {
            printf("%s\n", cwd);
        } else {
            perror("getcwd");
        }
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return status;
}