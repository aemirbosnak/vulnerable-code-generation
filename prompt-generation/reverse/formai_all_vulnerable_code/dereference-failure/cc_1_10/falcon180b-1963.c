//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"
#define PATH ":/usr/local/bin:/usr/bin:/bin"

// Split a string into an array of strings using delimiter
char **split(char *str, char delim) {
    int count = 0;
    char **tokens = NULL;
    char *token;

    token = strtok(str, delim);
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, delim);
    }
    tokens[count - 1] = NULL;

    return tokens;
}

// Execute a command and return its exit status
int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
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
        return WEXITSTATUS(status);
    }
}

// Main shell loop
int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    printf("Welcome to the shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split(input, '\n');

        if (args[0] == NULL) {
            continue;
        }

        status = execute_command(args);

        if (WIFEXITED(status)) {
            printf("Command exited with status %d.\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Command terminated by signal %d.\n", WTERMSIG(status));
        } else {
            printf("Command terminated abnormally.\n");
        }

        free(args);
    }

    return 0;
}