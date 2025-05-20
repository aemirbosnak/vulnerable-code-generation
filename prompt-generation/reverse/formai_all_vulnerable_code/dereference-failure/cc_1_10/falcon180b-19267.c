//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " "

char **split_string(char *str);
char *trim_whitespace(char *str);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *command;
    char **args;
    int status;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        command = trim_whitespace(input);
        args = split_string(command);

        status = execute_command(args);

        if (status == 1) {
            printf("Command not found.\n");
        } else if (status == 127) {
            printf("Command not found or permission denied.\n");
        }
    }

    return 0;
}

char **split_string(char *str) {
    int count = 0;
    char **tokens = NULL;
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

char *trim_whitespace(char *str) {
    int i, j;

    for (i = 0; i < strlen(str); i++) {
        if (!isspace(str[i])) {
            break;
        }
    }

    for (j = strlen(str) - 1; j >= 0; j--) {
        if (!isspace(str[j])) {
            break;
        }
    }

    return strndup(str + i, j - i + 1);
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(127);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}