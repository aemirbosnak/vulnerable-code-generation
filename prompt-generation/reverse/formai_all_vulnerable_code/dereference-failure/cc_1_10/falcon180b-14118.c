//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"
#define PATH ":/usr/local/bin:/usr/bin:/bin"

char **split_string(char *str) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Command not found.\n");
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int background = 0;
    int exit_shell = 0;

    printf("Unix-like Shell\n");

    while (!exit_shell) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            exit_shell = 1;
        } else if (strcmp(args[0], "bg") == 0 && args[1]!= NULL) {
            printf("Putting %s in background...\n", args[1]);
            background = 1;
            execute_command(args);
        } else if (strcmp(args[0], "fg") == 0 && args[1]!= NULL) {
            printf("Bringing %s to foreground...\n", args[1]);
        } else if (strcmp(args[0], "jobs") == 0) {
            printf("Currently running jobs:\n");
        } else {
            execute_command(args);
        }
    }

    free(args);
    return 0;
}