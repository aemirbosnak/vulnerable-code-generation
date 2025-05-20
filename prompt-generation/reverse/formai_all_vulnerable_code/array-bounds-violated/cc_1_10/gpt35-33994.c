//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LENGTH 1024
#define MAX_ARGS 64

// Function to display the shell prompt
void display_prompt() {
    char* user = getenv("USER");
    char* pwd = getenv("PWD");
    printf("%s:%s$ ", user, pwd);
}

// Function to split the command input into arguments
int split_command(char* input, char** args) {
    int argc = 0;
    char* token = strtok(input, " ");
    while (token != NULL) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL;
    return argc;
}

int main() {
    char input[MAX_LENGTH];
    char* args[MAX_ARGS];
    int argc;

    while (1) {
        display_prompt();
        fgets(input, MAX_LENGTH, stdin);

        // Removing newline character
        input[strlen(input) - 1] = '\0';

        argc = split_command(input, args);

        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            execvp(args[0], args);
            printf("%s: command not found\n", args[0]);
            exit(0);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}