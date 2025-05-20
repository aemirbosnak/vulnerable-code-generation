//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int buf_size = 0, word_count = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (isspace(*str)) {
            buf_size++;
        }
        str++;
    }

    tokens = malloc((word_count + 1) * sizeof(char *));

    str = strtok(str, DELIM);
    while (str!= NULL) {
        tokens[word_count++] = strdup(str);
        str = strtok(NULL, DELIM);
    }
    tokens[word_count] = NULL;

    return tokens;
}

int launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed: %s\n", strerror(errno));
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Execvp failed: %s\n", strerror(errno));
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input_buffer);

        if (args[0] == NULL) {
            continue;
        }

        launch_shell(args);
    }

    return 0;
}