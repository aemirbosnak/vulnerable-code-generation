//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings using delimiter
char **split_string(char *str) {
    int count = 0;
    char **arr = NULL;
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        count++;
        arr = realloc(arr, sizeof(char *) * count);
        arr[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }
    arr[count - 1] = NULL;

    return arr;
}

// Function to execute a command and wait for it to finish
void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid < 0) {
        // Error forking
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        exit(1);
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));
    }
}

// Function to handle user input and execute commands
void handle_input(char *input) {
    char **args = split_string(input);
    execute_command(args);
    for (int i = 0; args[i]!= NULL; i++) {
        free(args[i]);
    }
    free(args);
}

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];

    printf("CyberShell - A Cyberpunk-style Unix Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        handle_input(input);
    }

    return 0;
}