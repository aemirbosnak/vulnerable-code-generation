//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 255

void printPrompt() {
    char cwd[MAX_INPUT_LENGTH];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s> ", cwd);
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_INPUT_LENGTH/2 + 1];
    int shouldRun = 1;
    while (shouldRun) {
        printPrompt();
        fgets(input, MAX_INPUT_LENGTH, stdin);
        if (strlen(input) == 1 && input[0] == '\n') {
            continue;
        }
        input[strlen(input) - 1] = '\0';
        if (strcmp(input, "exit") == 0) {
            shouldRun = 0;
            continue;
        }
        int numArgs = 0;
        char *token = strtok(input, " ");
        while (token != NULL) {
            args[numArgs] = token;
            numArgs++;
            token = strtok(NULL, " ");
        }
        args[numArgs] = NULL;
        pid_t child_pid;
        child_pid = fork();
        if (child_pid == 0) {
            if (execvp(args[0], args) == -1) {
                printf("Could not execute command '%s'\n", args[0]);
            }
            exit(EXIT_FAILURE);
        } else if (child_pid < 0) {
            printf("Could not create child process\n");
        } else {
            int status;
            waitpid(child_pid, &status, 0);
        }
    }
    return 0;
}