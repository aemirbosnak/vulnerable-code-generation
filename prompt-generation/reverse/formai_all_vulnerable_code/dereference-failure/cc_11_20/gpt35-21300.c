//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char input[1024];
    char* args[64];
    int i = 0;
    int background = 0;

    while (1) {
        printf("HahaShell> ");
        fgets(input, 1024, stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // Split the input into arguments
        char* token = strtok(input, " ");
        while (token != NULL) {
            if (strcmp(token, "&") == 0) {
                background = 1;
            }
            else {
                args[i++] = token;
            }
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Built-in commands
        if (strcmp(args[0], "exit") == 0) {
            printf("Goodbye! Thanks for playing with HahaShell.\n");
            exit(0);
        }
        else if (strcmp(args[0], "echo") == 0) {
            for (int j = 1; j < i; j++) {
                printf("%s ", args[j]);
            }
            printf("\n");
        }
        else if (strcmp(args[0], "cd") == 0) {
            if (i >= 2) {
                int result = chdir(args[1]);
                if (result != 0) {
                    printf("Error: Could not change directory.\n");
                }
            }
            else {
                chdir(getenv("HOME"));
            }
        }
        else if (strcmp(args[0], "pwd") == 0) {
            char cwd[1024];
            getcwd(cwd, sizeof(cwd));
            printf("%s\n", cwd);
        }
        else {
            pid_t pid = fork();
            if (pid == 0) { // Child process
                execvp(args[0], args);
                printf("Error: Could not execute command.\n");
                exit(0);
            }
            else if (pid > 0) { // Parent process
                if (!background) {
                    wait(NULL);
                }
            }
            else { // Error
                printf("Error: Could not create child process.\n");
            }
        }

        // Reset variables
        i = 0;
        background = 0;
    }

    return 0;
}