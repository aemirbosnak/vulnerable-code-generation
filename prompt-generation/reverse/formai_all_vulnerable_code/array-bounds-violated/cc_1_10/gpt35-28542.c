//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_LENGTH 64
#define MAX_NUM_ARGS 64

int main() {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_NUM_ARGS];
    int status;

    while(1) {
        // Print the prompt
        printf("myShell > ");

        // Read user input
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // Remove the newline character at the end of the input
        input[strlen(input) - 1] = '\0';

        // Parse the user input into arguments
        char *token = strtok(input, " ");

        int i = 0;
        while(token != NULL && i < MAX_NUM_ARGS) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // If the user wants to exit the shell, break out of the loop
        if(strcmp(args[0], "exit") == 0) {
            break;
        }

        // Fork a child process to execute the user's command
        pid_t pid;
        pid = fork();

        if(pid == 0) { // child process
            // Execute the command
            if(execvp(args[0], args) < 0) {
                printf("myShell: command not found: %s\n", args[0]);
            }

            exit(0);
        } else if(pid < 0) { // error forking
            printf("myShell: error forking\n");
        } else { // parent process
            // Wait for the child process to finish executing
            waitpid(pid, &status, WUNTRACED);
        }
    }

    return 0;
}