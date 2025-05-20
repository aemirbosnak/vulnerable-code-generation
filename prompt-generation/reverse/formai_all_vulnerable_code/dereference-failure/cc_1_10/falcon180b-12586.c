//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 1024
#define DELIM " \t\r\n\a"

// Function to split a line into an array of strings
char **split_line(char *line) {
    int count = 0;
    char **tokens = malloc(sizeof(char *));

    char *token = strtok(line, DELIM);
    while (token!= NULL) {
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

// Function to execute a command and return its exit status
int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command found.\n");
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        // Error forking
        perror("fork");
        return 1;
    } else {
        // Parent process
        waitpid(pid, &status, 0);
        return status;
    }
}

// Function to handle input and execute commands
void handle_input(char *input) {
    char **args = split_line(input);
    int status = execute_command(args);

    if (status == 0) {
        printf("Command executed successfully.\n");
    } else {
        printf("Command failed with exit status %d.\n", status);
    }

    for (int i = 0; args[i]!= NULL; i++) {
        free(args[i]);
    }
    free(args);
}

int main() {
    char input[MAX_LINE];

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        handle_input(input);
    }

    return 0;
}