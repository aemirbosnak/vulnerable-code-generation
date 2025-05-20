//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_ARGS 16
#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv) {
    char line[MAX_LINE_LENGTH];
    char *args[MAX_ARGS];
    int status;

    while (1) {
        printf("> ");
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            break;
        }

        char *ptr = line;
        int i = 0;
        while (*ptr != '\n' && *ptr != '\0') {
            if (*ptr == ' ') {
                *ptr = '\0';
                args[i++] = strdup(ptr + 1);
                ptr++;
            } else {
                ptr++;
            }
        }
        args[i++] = NULL;

        if (i == 0) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        if (strcmp(args[0], "cd") == 0) {
            if (chdir(args[1]) != 0) {
                perror("chdir");
            }
            continue;
        }

        pid_t child_pid = fork();
        if (child_pid == 0) {
            if (execvp(args[0], args) != 0) {
                perror("execvp");
                exit(1);
            }
        } else {
            wait(&status);
        }
    }

    return 0;
}