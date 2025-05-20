//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100 /* Maximum length of command */
#define MAX_NUMBER_OF_ARGUMENTS 10 /* Maximum number of arguments in command */

int main() {

    char command[MAX_COMMAND_LENGTH]; /* Command entered by user */
    char *arguments[MAX_NUMBER_OF_ARGUMENTS + 1]; /* Arguments parsed from the command */
    pid_t pid; /* Process ID */
    int status; /* Status of child process */

    while (1) {
        printf("Enter a command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        /* Remove trailing newline character */
        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }

        /* Parse command into arguments */
        arguments[0] = strtok(command, " ");
        int argument_count = 0;
        while (arguments[argument_count] != NULL) {
            argument_count++;
            arguments[argument_count] = strtok(NULL, " ");
        }

        /* Exit program if user enters "exit" */
        if (strcmp(arguments[0], "exit") == 0) {
            exit(0);
        }

        /* Create new process to execute command */
        pid = fork();

        if (pid < 0) {
            printf("Error: Failed to fork.\n");
            exit(1);
        } else if (pid == 0) { /* Child process */
            /* Execute command in child process */
            if (execvp(arguments[0], arguments) < 0) {
                printf("Error: Failed to execute command.\n");
                exit(1);
            }
        } else { /* Parent process */
            /* Wait for child process to finish */
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}