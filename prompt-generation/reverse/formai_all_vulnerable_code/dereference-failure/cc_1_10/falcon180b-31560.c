//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\n\r\a"

char **split(char *str, char delimiter) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(sizeof(char *));
    char *token = malloc(bufsize * sizeof(char));

    for (char *p = strtok_r(str, delimiter, &p); p!= NULL; p = strtok_r(NULL, delimiter, &p)) {
        strncpy(token, p, bufsize - 1);
        token[bufsize - 1] = '\0';
        tokens = realloc(tokens, sizeof(char *) * ++position);
        tokens[position - 1] = token;
    }

    tokens[position] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: command not found.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("Error");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split(input, '\n');
        execute_command(args);

        free(args[0]);
        free(args);
    }

    return 0;
}