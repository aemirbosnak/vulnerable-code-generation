//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_COMMAND 1024
#define MAX_ARGUMENTS 1024

// Function to split a string into an array of strings
int split(char *str, char *delimiter, char ***tokens) {
    int count = 0;
    char *token = strtok(str, delimiter);

    while (token!= NULL) {
        count++;
        token = strtok(NULL, delimiter);
    }

    *tokens = (char **) malloc(count * sizeof(char *));

    count = 0;
    token = strtok(str, delimiter);

    while (token!= NULL) {
        (*tokens)[count] = token;
        count++;
        token = strtok(NULL, delimiter);
    }

    (*tokens)[count] = NULL;

    return count;
}

// Function to execute a command and return its exit status
int execute_command(char **tokens) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(tokens[0], tokens) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid < 0) {
        // Error forking
        perror("Error forking");
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

// Function to read a line from standard input
char *read_line() {
    char *line = NULL;
    size_t size = 0;

    getline(&line, &size, stdin);

    return line;
}

// Function to print the prompt
void print_prompt() {
    printf("> ");
}

// Function to handle a command
void handle_command(char *line) {
    char *delimiter = " ";
    char **tokens = NULL;
    int count;

    // Split the line into tokens
    count = split(line, delimiter, &tokens);

    // Execute the command
    if (count > 0) {
        execute_command(tokens);
    }
}

// Main function
int main() {
    char *line;

    while (1) {
        print_prompt();
        line = read_line();

        // Exit the shell if the user enters "exit"
        if (strcmp(line, "exit") == 0) {
            break;
        }

        handle_command(line);
    }

    return 0;
}