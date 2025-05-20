//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 512 // maximum size of user input
#define MAX_ARGS 16 // maximum number of arguments in command

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];
    int should_run = 1; // flag to keep shell running

    while (should_run) {
        printf("mysh>"); // prompt for input
        fflush(stdout);
        fgets(input, MAX_INPUT, stdin); // read user input

        // remove newline character from input
        if (input[strlen(input)-1] == '\n') {
            input[strlen(input)-1] = '\0';
        }

        // tokenize user input into separate arguments
        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL && i < MAX_ARGS-1) {
            i++;
            args[i] = strtok(NULL, " ");
        }
        args[i+1] = NULL; // make sure last argument is NULL for execvp

        // handle built-in commands
        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
        }
        else if (strcmp(args[0], "cd") == 0) {
            if (chdir(args[1]) != 0) {
                perror("cd");
            }
        }
        else {
            pid_t pid = fork(); // create child process
            if (pid < 0) {
                perror("fork");
                exit(1);
            }
            else if (pid == 0) { // child process
                if (execvp(args[0], args) < 0) { // execute command
                    printf("mysh: command not found: %s\n", args[0]);
                    exit(1);
                }
            }
            else { // parent process
                int status = 0;
                waitpid(pid, &status, 0); // wait for child to finish
            }
        }
    }

    return 0; // exit shell
}