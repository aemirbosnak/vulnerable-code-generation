//Falcon-180B DATASET v1.0 Category: System administration ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

// Function to execute commands
void execute_command(char* command, char** arguments) {
    printf("Executing command: %s\n", command);
    for (int i = 0; arguments[i]!= NULL; i++) {
        printf("Argument %d: %s\n", i+1, arguments[i]);
    }
}

// Function to split a string into an array of strings
char** split_string(char* str, int* count) {
    char** result = malloc(MAX_ARGUMENTS * sizeof(char*));
    int index = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        result[index++] = token;
        if (index >= MAX_ARGUMENTS) {
            printf("Error: Too many arguments\n");
            exit(1);
        }
        token = strtok(NULL, " ");
    }
    *count = index;
    return result;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char* command = NULL;
    char** arguments = NULL;
    int argument_count = 0;

    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        command = strtok(input, "\n");
        arguments = split_string(command, &argument_count);
        execute_command(command, arguments);
        free(command);
        for (int i = 0; i < argument_count; i++) {
            free(arguments[i]);
        }
        free(arguments);
    }

    return 0;
}