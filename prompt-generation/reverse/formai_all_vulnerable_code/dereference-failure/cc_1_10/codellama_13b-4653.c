//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: curious
/*
* This is a curious C Basic Unix-like Shell program that
* demonstrates the use of the `fork`, `exec`, and `wait`
* system calls to execute commands in a child process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char **argv) {
    char *command;
    char *args[100];
    int status;

    // Prompt the user for input
    printf("Curious Shell> ");
    fflush(stdout);

    // Read the input from the user
    fgets(command, 100, stdin);

    // Remove the newline character from the end of the input
    command[strlen(command) - 1] = '\0';

    // Split the input into arguments
    args[0] = strtok(command, " ");
    int i = 1;
    while (args[i - 1] != NULL) {
        args[i] = strtok(NULL, " ");
        i++;
    }

    // Create a new process to execute the command
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        printf("Error: Command not found.\n");
        exit(1);
    } else {
        // Parent process
        wait(&status);
    }

    // Print the output of the command
    printf("Output: %d\n", status);

    return 0;
}