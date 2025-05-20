//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function prototypes
char *get_next_token(char *line);
int execute_command(char **args);
void print_prompt(char *username);

int main(int argc, char **argv) {
    char username[50];
    char input_buffer[MAX_COMMAND_LENGTH];

    // Get the username
    printf("Enter your name: ");
    scanf("%s", username);
    printf("\n");

    // Print the prompt with the username
    print_prompt(username);

    // Main loop for reading and executing commands
    while (1) {
        // Read a line of input
        printf("%s ", username);
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        // Remove the newline character from the end of the input
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        // Tokenize the input line
        char *line = strdup(input_buffer);
        char *token = get_next_token(line);
        char **args = malloc(sizeof(char *) * (argc + 1));
        int argc_count = 0;
        while (token!= NULL) {
            args[argc_count] = strdup(token);
            argc_count++;
            token = get_next_token(NULL);
        }
        args[argc_count] = NULL;

        // Execute the command
        int result = execute_command(args);

        // Check if the shell should exit
        if (result == 1) {
            break;
        }
    }

    return 0;
}

// Function to get the next token in a line
char *get_next_token(char *line) {
    char *token = strtok(line, DELIM);
    return token;
}

// Function to execute a command
int execute_command(char **args) {
    if (args[0] == NULL) {
        return 0;
    }

    // Check if the command is "exit"
    if (strcmp(args[0], "exit") == 0) {
        return 1;
    }

    // TODO: Implement more commands here

    return 0;
}

// Function to print the prompt with the username
void print_prompt(char *username) {
    printf("%s@Sherlock: ", username);
}