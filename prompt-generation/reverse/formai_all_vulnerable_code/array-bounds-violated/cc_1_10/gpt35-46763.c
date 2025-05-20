//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024

void parse_input(char *input, char **args) {
    int i = 0;
    char *token = strtok(input, " \n");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;
}

int main() {
    char input[MAX_LENGTH];
    char *args[MAX_LENGTH/2 + 1];
    pid_t pid;
    int background = 0;

    while (1) {
        printf("osh> ");
        fflush(stdout);

        fgets(input, MAX_LENGTH, stdin);
        background = 0;

        if (input[strlen(input) - 1] == '&') {
            background = 1;
            input[strlen(input) - 1] = '\0';
        }

        parse_input(input, args);

        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            chdir(args[1]);
        } else {
            pid = fork();
            if (pid < 0) { // fork error
                fprintf(stderr, "Error: fork failed.\n");
                exit(1);
            } else if (pid == 0) { // child process
                execvp(args[0], args);
                fprintf(stderr, "Error: execvp failed to execute command.\n");
                exit(1);
            } else { // parent process
                if (!background) {
                    waitpid(pid, NULL, 0);
                }
            }
        }
    }

    return 0;
}