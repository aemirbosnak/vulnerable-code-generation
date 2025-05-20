//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int bufsize = 0, words = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*string!= '\0') {
        if (isspace(*string)) {
            words++;
        }
        string++;
    }

    tokens = malloc((words + 1) * sizeof(char *));

    if (tokens == NULL) {
        fprintf(stderr, "Memory error\n");
        return NULL;
    }

    bufsize = strlen(string) + 1;
    token = malloc(bufsize);

    if (token == NULL) {
        fprintf(stderr, "Memory error\n");
        return NULL;
    }

    strcpy(token, string);
    string = strtok(token, DELIM);
    i = 0;

    while (string!= NULL) {
        tokens[i] = malloc((strlen(string) + 1) * sizeof(char));

        if (tokens[i] == NULL) {
            fprintf(stderr, "Memory error\n");
            return NULL;
        }

        strcpy(tokens[i], string);
        i++;
        string = strtok(NULL, DELIM);
    }

    tokens[i] = NULL;
    free(token);

    return tokens;
}

int launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("CyberShell 1.0\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args == NULL) {
            continue;
        }

        launch_shell(args);
    }

    return 0;
}