//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGUMENTS 64

int main() {

    char userInput[MAX_INPUT_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int backgroundProcess = 0; // flag to determine if the program should run in the background

    while (1) {

        // print a prompt for user input
        printf(">> ");
        fflush(stdout);

        // read user input
        fgets(userInput, MAX_INPUT_LENGTH, stdin);

        // remove newline character from user input
        userInput[strlen(userInput) - 1] = '\0';

        // tokenize user input by space
        char *token = strtok(userInput, " ");

        // loop through tokens and populate arguments array
        int i = 0;
        while (token != NULL) {

            // check for background process flag
            if (strcmp(token, "&") == 0) {
                backgroundProcess = 1;
            } else {
                arguments[i] = malloc(strlen(token) + 1);
                strcpy(arguments[i], token);
                i++;
            }

            token = strtok(NULL, " ");
        }
        arguments[i] = NULL;

        // if the user entered no command or a comment, continue
        if (arguments[0] == NULL || arguments[0][0] == '#') {
            continue;
        }

        // fork a child process to execute commands
        int pid = fork();

        if (pid == 0) { // child process

            // execute the command specified by the user
            execvp(arguments[0], arguments);

            // if execvp returns, there was an error
            printf("Error executing command\n");
            exit(1);

        } else if (pid < 0) { // error forking process
            printf("Error forking process\n");
            exit(1);
        } else { // parent process

            // if the command wasn't specified to run in the background, wait for the child process to finish
            if (!backgroundProcess) {
                waitpid(pid, NULL, 0);
            }

            // reset background process flag
            backgroundProcess = 0;
        }

        // free memory allocated for arguments array
        for (int j = 0; arguments[j] != NULL; j++) {
            free(arguments[j]);
        }
    }

    return 0;
}