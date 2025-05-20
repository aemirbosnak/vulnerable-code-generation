//Falcon-180B DATASET v1.0 Category: System administration ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " "

int main(int argc, char **argv) {
    pid_t childpid;
    int status;
    char *command = NULL;
    char **arguments = NULL;
    int numarguments = 0;

    // Get the command from the user
    printf("Enter a command: ");
    if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read command.\n");
        exit(1);
    }
    command[strcspn(command, "\n")] = '\0'; // Remove the newline character

    // Parse the arguments
    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        if (numarguments >= MAX_ARGUMENTS) {
            fprintf(stderr, "Error: Too many arguments.\n");
            exit(1);
        }
        arguments[numarguments++] = token;
        token = strtok(NULL, DELIM);
    }
    arguments[numarguments] = NULL;

    // Fork a child process to execute the command
    childpid = fork();
    if (childpid == -1) {
        fprintf(stderr, "Error: Failed to fork.\n");
        exit(1);
    } else if (childpid == 0) {
        // Child process
        execvp(arguments[0], arguments);
        fprintf(stderr, "Error: Failed to execute command.\n");
        exit(1);
    } else {
        // Parent process
        waitpid(childpid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Command executed successfully.\n");
        } else if (WIFSIGNALED(status)) {
            printf("Command terminated by signal %d.\n", WTERMSIG(status));
        } else {
            printf("Unknown status code %d.\n", status);
        }
    }

    return 0;
}