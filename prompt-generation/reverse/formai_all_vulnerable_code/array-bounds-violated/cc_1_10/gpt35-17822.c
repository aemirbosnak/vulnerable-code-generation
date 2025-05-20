//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024 // Maximum size of user input
#define MAX_TOKEN_SIZE 64 // Maximum size of each token
#define MAX_NUM_TOKENS 64 // Maximum number of tokens per input

char *tokens[MAX_NUM_TOKENS]; // Array to store tokenized input

void tokenize_input(char *input) {
    char *token = strtok(input, " ");
    int i = 0;

    while (token != NULL && i < MAX_NUM_TOKENS) {
        tokens[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    tokens[i] = NULL;
}

void execute_command() {
    pid_t pid = fork(); // Create new process

    if (pid < 0) {
        printf("Error: Unable to create new process\n");
    } else if (pid == 0) {
        // Child process
        if (execvp(tokens[0], tokens) < 0) {
            printf("Error: Unable to execute command\n");
            exit(1);
        }
    } else {
        // Parent process
        wait(NULL);
    }
}

int main(int argc, char* argv[]) {
    char input[MAX_INPUT_SIZE];
    int running = 1;

    printf("Welcome to my basic Unix-like shell!\n");

    while (running) {
        printf("> ");
        fflush(stdout);
        fgets(input, MAX_INPUT_SIZE, stdin);

        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0'; // Remove newline character
        }

        tokenize_input(input); // Tokenize user input

        if (strcmp(tokens[0], "exit") == 0) {
            running = 0;
        } else {
            execute_command(); // Execute command
        }
    }
    return 0;
}