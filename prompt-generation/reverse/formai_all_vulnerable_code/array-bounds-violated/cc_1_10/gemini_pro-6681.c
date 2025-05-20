//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE_SIZE 1024
#define MAX_ARGS 128

void parse_args(char *line, char **argv) {
    int argc = 0;
    char *p = line;
    char *q = NULL;
    while ((p = strtok_r(p, " ", &q)) != NULL) {
        argv[argc++] = p;
    }
    argv[argc] = NULL;
}

int main(int argc, char **argv) {
    char line[MAX_LINE_SIZE];
    char *args[MAX_ARGS];

    while (1) {
        printf("Enter a command: ");
        fflush(stdout);

        if (fgets(line, MAX_LINE_SIZE, stdin) == NULL) {
            printf("\n");
            exit(0);
        }

        line[strlen(line) - 1] = '\0';

        if (strcmp(line, "exit") == 0) {
            exit(0);
        }

        parse_args(line, args);

        if (fork() == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        }

        wait(NULL);
    }

    return 0;
}