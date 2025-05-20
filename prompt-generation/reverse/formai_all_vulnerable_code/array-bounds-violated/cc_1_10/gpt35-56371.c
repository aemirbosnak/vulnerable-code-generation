//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    char input[256];
    char *args[64];
    int status;
    pid_t pid;

    // Loop until user exits
    while (1) {
        // Print shell prompt
        printf(">> ");

        // Read user input
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline character
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        // Tokenize input
        char *token = strtok(input, " ");
        int i = 0;
        while (token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // Check if user wants to exit
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        // Create child process
        pid = fork();

        if (pid < 0) {
            printf("Fork failed.");
        }
        else if (pid == 0) {
            // Child process
            if (execvp(args[0], args) < 0) {
                printf("Command not found.");
            }
            exit(0);
        }
        else {
            // Parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}