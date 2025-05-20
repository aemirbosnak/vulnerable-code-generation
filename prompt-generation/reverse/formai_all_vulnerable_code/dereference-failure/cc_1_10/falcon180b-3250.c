//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function to split a string into tokens
char **split_string(char *str) {
    int buf_size = 0, word_count = 0;
    char **tokens = NULL;
    char *token;
    char *saveptr;

    // Count the number of words in the input string
    char *copy = strdup(str);
    char *word = strtok_r(copy, DELIM, &saveptr);
    while (word!= NULL) {
        buf_size++;
        word = strtok_r(NULL, DELIM, &saveptr);
    }

    // Allocate memory for the tokens array and populate it
    tokens = malloc((buf_size + 1) * sizeof(char *));
    if (tokens == NULL) {
        perror("malloc");
        exit(1);
    }
    word_count = 0;
    copy = strdup(str);
    word = strtok_r(copy, DELIM, &saveptr);
    while (word!= NULL) {
        tokens[word_count++] = word;
        word = strtok_r(NULL, DELIM, &saveptr);
    }
    tokens[word_count] = NULL;

    return tokens;
}

// Function to execute a command
void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL)
        return;

    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\"\n");
        } else {
            if (chdir(tokens[1])!= 0) {
                perror("chdir");
            }
        }
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid > 0) {
            waitpid(pid, &status, 0);
        } else {
            if (execvp(tokens[0], tokens) == -1) {
                perror("execvp");
            }
            exit(1);
        }
    }
}

// Main function to read commands and execute them
int main() {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;

    printf("Welcome to the Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        tokens = split_string(input);
        execute_command(tokens);
    }

    return 0;
}