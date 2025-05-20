//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024
#define MAX_ARGS 64

void parse_command(char *command, char **arguments) {
    int index = 0;
    arguments[index] = strtok(command, " ");
    while (arguments[index] != NULL) {
        index++;
        arguments[index] = strtok(NULL, " ");
    }
}

int main(int argc, char **argv) {
    char command[MAX_LENGTH];
    char *arguments[MAX_ARGS];
    pid_t pid;
    int status;

    printf("Welcome to my UNIX-like shell!\n");

    while (1) {
        // read in user input
        printf("> ");
        fgets(command, MAX_LENGTH, stdin);
        command[strlen(command) - 1] = '\0'; // remove newline character

        // exit shell if user types "exit" or "quit"
        if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0) {
            break;
        }

        // parse command into arguments
        parse_command(command, arguments);

        // execute command
        pid = fork();
        if (pid == 0) {
            // child process
            if (execvp(arguments[0], arguments) == -1) {
                printf("Error executing command.\n");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // fork error
            printf("Error forking process.\n");
        } else {
            // parent process
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return 0;
}