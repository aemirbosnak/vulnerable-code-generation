//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int count = 0, i = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));

    while (*str) {
        if (strchr(DELIM, *str)) {
            *str = '\0';
            count++;
        }
        str++;
    }

    tokens[count] = NULL;

    str = strtok(strcpy(malloc(strlen(str) + 1), " "), DELIM);

    while (str!= NULL && count < MAX_ARGUMENTS - 1) {
        tokens[i++] = str;
        str = strtok(NULL, DELIM);
    }

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

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        execute_command(args);
    }

    return 0;
}