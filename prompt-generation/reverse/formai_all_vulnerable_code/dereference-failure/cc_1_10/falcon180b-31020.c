//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (strchr(DELIM, *str)) {
            *str = '\0';
            token = strdup(str);
            str++;
            bufsize++;
        }
    }

    if (bufsize > 0) {
        tokens = (char **)malloc((bufsize + 1) * sizeof(char *));
        for (i = 0; i < bufsize; i++) {
            tokens[i] = strdup(token);
        }
        tokens[i] = NULL;
    }

    return tokens;
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL)
        return;

    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1]!= NULL) {
            if (chdir(tokens[1])!= 0) {
                perror("chdir");
            }
        }
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                perror("execvp");
            }
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    tokens = split_string(input);
    execute_command(tokens);

    free(tokens);
}

int main(void) {
    loop();

    return 0;
}