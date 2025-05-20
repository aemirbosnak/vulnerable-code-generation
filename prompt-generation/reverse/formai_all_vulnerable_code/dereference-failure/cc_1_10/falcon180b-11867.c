//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function prototypes
char **split_string(char *string);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Split input into arguments
        args = split_string(input);

        // Execute command
        status = execute_command(args);

        // Free memory allocated for arguments
        for (int i = 0; args[i]!= NULL; i++) {
            free(args[i]);
        }
        free(args);

        if (status == 1) {
            break;
        }
    }

    return 0;
}

// Splits a string into an array of strings based on delimiter
char **split_string(char *string) {
    int count = 0;
    char *token;
    char **tokens = NULL;

    token = strtok(string, DELIM);
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }
    tokens[count - 1] = NULL;

    return tokens;
}

// Executes a command and returns its exit status
int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        printf("Error: Command not found.\n");
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
        return 1;
    } else {
        // Parent process
        waitpid(pid, &status, 0);
        return status;
    }
}