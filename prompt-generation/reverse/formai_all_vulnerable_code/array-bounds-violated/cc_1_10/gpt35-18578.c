//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 100
#define MAX_ARGS 10

int main() {
    char input[MAX_CMD_LENGTH];
    char *args[MAX_ARGS];
    int status;

    printf("Hello! I am your Unix-like shell.\n");
    printf("Please enter a command or type 'exit' to terminate.\n");

    while (1) {
        printf("> ");
        fflush(stdout);

        // get user input
        fgets(input, MAX_CMD_LENGTH, stdin);

        // remove newline character at end of input
        input[strlen(input) - 1] = '\0';

        // check if user wants to exit
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // tokenize input into separate arguments
        char *token = strtok(input, " ");
        int i = 0;

        while (token != NULL && i < MAX_ARGS - 1) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }

        args[i] = NULL;

        // fork process and execute command
        pid_t pid = fork();

        if (pid == 0) {
            // child process
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        }
        else if (pid < 0) {
            // error
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else {
            // parent process
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                printf("Child process returned with exit code %d\n", WEXITSTATUS(status));
            }
            else {
                printf("Child process exited abnormally\n");
            }
        }
    }

    return 0;
}