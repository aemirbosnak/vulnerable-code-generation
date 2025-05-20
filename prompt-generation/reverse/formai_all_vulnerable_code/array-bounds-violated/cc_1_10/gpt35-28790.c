//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    printf("Welcome to Chuck Norris' shell!\n");
    printf("Type 'exit' to leave, or enter any command to see the magic:\n");

    char input[1000]; // Maximum length of user input
    int status;

    while(1) {

        printf("Chuck Norris commands you: ");
        fgets(input, sizeof(input), stdin); // Get user input as a string

        // Remove trailing new line character
        if(input[strlen(input)-1] == '\n') {
            input[strlen(input)-1] = '\0';
        }

        // Check if user entered 'exit'
        if(strcmp(input, "exit") == 0) {
            printf("Goodbye, mortal!\n");
            break;
        }

        // Execute user input as a command in a new process
        pid_t pid = fork();

        if(pid == -1) {
            printf("Chuck Norris is too busy to run your command. Try again later.\n");
            exit(1);
        }
        else if(pid == 0) {
            // Child process
            char *arguments[100]; // Maximum number of arguments in a command
            char *token = strtok(input, " ");

            // Parse user input into arguments
            int i = 0;
            while(token != NULL) {
                arguments[i] = token;
                token = strtok(NULL, " ");
                i++;
            }
            arguments[i] = NULL; // Last argument must be null

            execvp(arguments[0], arguments);
            printf("Chuck Norris is displeased with your command. Try again.\n");
            exit(1);
        }
        else {
            // Parent process waiting for child to finish executing
            wait(&status);
        }
    }

    return 0;
}