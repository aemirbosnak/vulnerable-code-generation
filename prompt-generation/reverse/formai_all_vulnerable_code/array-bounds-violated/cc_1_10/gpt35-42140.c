//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 100
#define MAX_BUF 1024

char* get_line() {
    char buf[MAX_BUF];
    fgets(buf, MAX_BUF, stdin);
    int len = strlen(buf);
    if (buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    }
    char* line = malloc(sizeof(char) * (len + 1));
    strcpy(line, buf);
    return line;
}

char** parse_line(char* line) {
    char** args = malloc(sizeof(char*) * MAX_ARGS);
    int i = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

int main() {
    while (1) {
        printf("> ");
        fflush(stdout);

        char* line = get_line();
        char** args = parse_line(line);

        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            printf("Goodbye!\n");
            free(line);
            free(args);
            exit(0);
        }

        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("Error");
            exit(1);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("Error");
        }

        free(line);
        free(args);
    }

    return 0;
}