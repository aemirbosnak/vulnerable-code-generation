//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 1024

void print_greeting() {
    printf("Welcome to ye olde Unix-like shell!\n");
    printf("May thou's commands be executed with success!\n");
}

void print_prompt() {
    printf("\nHonorable user, what be thy command?\n$ ");
}

int parse_input(char* input, char** args, int* argc) {
    int i = 0;
    char* token = strtok(input, " \n");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;
    *argc = i;
    return (i > 0) ? 1 : 0;
}

int execute_command(char** args, int argc) {
    pid_t pid = fork();
    if (pid < 0) {
        printf("Error: Unable to create a new process.\n");
        return -1;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) < 0) {
            printf("Error: Command execution failed.\n");
            exit(1);
        }
    } else {
        // Parent process
        wait(NULL);
    }
    return 0;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char* args[MAX_INPUT_LENGTH / 2 + 1];
    int argc = 0;

    print_greeting();
    while (1) {
        print_prompt();
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // Remove the trailing newline character
        input[strlen(input) - 1] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Parse the input into arguments
        if (parse_input(input, args, &argc)) {
            // Execute the command
            execute_command(args, argc);
        }
    }

    return 0;
}