//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

// Function to execute a command
int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error");
            exit(1);
        }
    } else if (pid < 0) {
        // Error forking
        perror("Error");
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }

    return 0;
}

// Function to parse a command line
char **parse_command(char *line) {
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argc = 0;
    char *token;

    token = strtok(line, " ");
    while (token!= NULL) {
        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Error: Too many arguments.\n");
            exit(1);
        }
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL;

    return args;
}

// Function to print the prompt
void print_prompt(char *username) {
    printf("%s@localhost:~$ ", username);
}

// Function to read a line of input
char *read_line(FILE *stream) {
    char *line = NULL;
    size_t capacity = 0;
    ssize_t read;

    getline(&line, &capacity, stream);

    if (line == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(1);
    }

    return line;
}

int main() {
    char *username;
    char *line;
    char **args;
    FILE *input;

    // Get username
    username = getlogin();
    if (username == NULL) {
        fprintf(stderr, "Error getting username.\n");
        exit(1);
    }

    // Open input file
    input = fdopen(0, "r");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        exit(1);
    }

    // Print welcome message
    printf("Welcome to the %s shell!\n", username);

    while (1) {
        // Print prompt
        print_prompt(username);

        // Read line of input
        line = read_line(input);

        // Parse command
        args = parse_command(line);

        // Execute command
        execute_command(args);

        // Free memory
        free(line);
        for (int i = 0; args[i]!= NULL; i++) {
            free(args[i]);
        }
        free(args);
    }

    return 0;
}