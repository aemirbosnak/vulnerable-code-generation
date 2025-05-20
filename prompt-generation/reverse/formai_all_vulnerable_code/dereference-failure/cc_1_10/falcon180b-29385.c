//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token = strtok(line, DELIM);

    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
        }

        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

pid_t fork() {
    pid_t pid;
    if ((pid = vfork()) == 0) {
        return pid;
    } else if (pid < 0) {
        perror("vfork");
        exit(1);
    }
    return pid;
}

int main(int argc, char **argv) {
    char *input = NULL;
    size_t input_size = 0;
    getline(&input, &input_size, stdin);

    char **tokens = split_line(input);
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }

    for (int i = 0; tokens[i]!= NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
    return 0;
}