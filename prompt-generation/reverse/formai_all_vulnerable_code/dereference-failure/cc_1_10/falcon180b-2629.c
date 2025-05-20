//Falcon-180B DATASET v1.0 Category: System administration ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function to execute a command and wait for its completion
void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        printf("Error: fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execlp(command, command, NULL) == -1) {
            printf("Error: %s not found\n", command);
            exit(1);
        }
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

// Function to split a string into tokens using delimiter
char **split_string(char *string, char delimiter) {
    int count = 0;
    char **tokens = NULL;
    char *token;

    token = strtok(string, delimiter);
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, delimiter);
    }
    tokens[count - 1] = NULL;

    return tokens;
}

// Main function to read commands from user and execute them
int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input, DELIM);

        if (args[0] == NULL) {
            continue;
        }

        execute_command(args[0]);

        for (int i = 0; args[i]!= NULL; i++) {
            free(args[i]);
        }
        free(args);
    }

    return 0;
}