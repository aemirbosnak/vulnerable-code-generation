//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split(char *line) {
    int count = 0;
    char **tokens = malloc(MAX_LINE * sizeof(char *));
    char *token = strtok(line, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;
    return tokens;
}

int main(int argc, char **argv) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t pid;
    int status;
    char **args;

    if (argc < 2) {
        printf("Usage: %s [command]\n", argv[0]);
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[1], argv + 1) == -1) {
            perror("execvp");
            return 1;
        }
    } else {
        signal(SIGCHLD, SIG_IGN);
        while ((read = getline(&line, &len, stdin))!= -1) {
            if (line[read - 1] == '\n') {
                line[--read] = '\0';
            }

            args = split(line);

            if (strcmp(args[0], "exit") == 0) {
                break;
            }

            pid = fork();

            if (pid == -1) {
                perror("fork");
                return 1;
            } else if (pid == 0) {
                if (execvp(args[0], args) == -1) {
                    perror("execvp");
                    return 1;
                }
            }

            waitpid(pid, &status, WUNTRACED);
        }

        free(line);
        return 0;
    }
}