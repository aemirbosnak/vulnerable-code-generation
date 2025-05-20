//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

typedef struct {
    char *argv[MAX_ARGS];
    int argc;
} Command;

int main() {
    char line[MAX_LINE_LENGTH];
    Command command;

    while (1) {
        printf("> ");
        fflush(stdout);

        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            break;
        }

        if (strlen(line) == 1) {
            continue;
        }

        line[strlen(line) - 1] = '\0';

        command.argc = 0;

        char *token = strtok(line, " ");
        while (token != NULL) {
            command.argv[command.argc++] = strdup(token);
            token = strtok(NULL, " ");
        }

        if (strcmp(command.argv[0], "exit") == 0) {
            break;
        }

        int pid = fork();

        if (pid == 0) {
            execvp(command.argv[0], command.argv);
            perror("execvp");
            exit(1);
        }

        int status;
        waitpid(pid, &status, 0);

        for (int i = 0; i < command.argc; i++) {
            free(command.argv[i]);
        }
    }

    return 0;
}