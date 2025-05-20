//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LINE_LENGTH 1024
#define MAX_ARGUMENTS 100
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings
char **split(char *str, char delimiter) {
    int count = 0;
    char **arr = NULL;
    char *token = strtok(str, delimiter);

    while (token!= NULL) {
        count++;
        arr = realloc(arr, sizeof(char *) * count);
        arr[count - 1] = token;
        token = strtok(NULL, delimiter);
    }

    arr[count - 1] = NULL;
    return arr;
}

// Function to execute a command
void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));
    }
}

// Function to handle user input
void handle_input(char *input) {
    char **args = split(input, DELIM);
    execute_command(args);
    free(args);
}

// Main function
int main() {
    char input[MAX_COMMAND_LINE_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LINE_LENGTH, stdin);
        handle_input(input);
    }

    return 0;
}