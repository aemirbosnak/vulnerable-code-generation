//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXLINE 80 // Maximum length of input line
#define MAXARGS 20 // Maximum number of arguments in a command

void handle_sigint(int sig) {
    // Do nothing
}

// Parse the input line into arguments
void parse_args(char *line, char **args) {
    int i = 0;
    char *token = strtok(line, " ");

    while(token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; // Set the last argument to NULL
}

int main(void) {
    char *args[MAXARGS]; // Array of arguments in a command
    char line[MAXLINE]; // Input line buffer
    int should_run = 1; // Flag to determine when to exit shell

    // Set up signal handler for SIGINT
    signal(SIGINT, handle_sigint);

    while (should_run) {
        printf("myshell> "); // Prompt for user input
        fflush(stdout); // Flush output buffer

        // Read input from user
        if (fgets(line, MAXLINE, stdin) == NULL) {
            printf("\n");
            continue;
        }

        // Remove the newline character from the end of the input line
        line[strlen(line) - 1] = '\0';

        // Parse the input line into arguments
        parse_args(line, args);

        // Check if user wants to exit the shell
        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
            continue;
        }

        // Spawn a new process to execute the command
        pid_t pid = fork();

        if (pid < 0) { // Forking failed
            printf("Forking failed\n");
            continue;
        }
        else if (pid == 0) { // Child process
            execvp(args[0], args); // Execute the command
            printf("Command not found: %s\n", args[0]);
            exit(0);
        }
        else { // Parent process
            wait(NULL); // Wait for child to finish executing
        }
    }

    printf("Exiting myshell\n");

    return 0;
}