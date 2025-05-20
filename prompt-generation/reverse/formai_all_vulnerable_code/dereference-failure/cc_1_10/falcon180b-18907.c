//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function for splitting a string into an array of strings
char **split(char *str, char delimiter) {
    int count = 0;
    char **result = NULL;
    char *token = strtok(str, delimiter);

    while (token!= NULL) {
        count++;
        result = realloc(result, sizeof(char *) * count);
        result[count - 1] = token;
        token = strtok(NULL, delimiter);
    }

    return result;
}

// Function for executing a command and returning its output as a string
char *execute_command(char **args) {
    pid_t pid;
    int status;
    char *output = NULL;
    FILE *pipe;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: No command specified.\n");
        return NULL;
    }

    pipe = popen(args[0], "r");

    if (pipe == NULL) {
        fprintf(stderr, "Error: Failed to execute command.\n");
        return NULL;
    }

    while (fgets(output, MAX_COMMAND_LENGTH, pipe)!= NULL) {
        output[strcspn(output, "\n")] = '\0';
    }

    pclose(pipe);

    return output;
}

// Function for freeing a 2D char array
void free_char_array(char **array, int size) {
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}

// Main function for the shell
int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    char *output;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split(input, DELIM);

        if (args[0] == NULL) {
            continue;
        }

        output = execute_command(args);

        if (output!= NULL) {
            printf("%s\n", output);
        }

        free_char_array(args, argc);
    }

    return 0;
}