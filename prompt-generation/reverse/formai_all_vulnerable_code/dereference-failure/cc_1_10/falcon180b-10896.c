//Falcon-180B DATASET v1.0 Category: System administration ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 100
#define MAX_ARG_LENGTH 100

// Function to execute commands
void execute_command(char *command) {
    char **args = NULL;
    int argc = 0;

    // Parse command line arguments
    args = malloc(MAX_ARG_LENGTH * sizeof(char *));
    if (args == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        exit(1);
    }
    char *token = strtok(command, " ");
    while (token!= NULL) {
        args[argc++] = token;
        if (argc >= MAX_ARG_LENGTH) {
            fprintf(stderr, "Error: Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, " ");
    }
    args[argc] = NULL;

    // Execute command
    if (strcmp(args[0], "ls") == 0) {
        printf("Listing files...\n");
    } else if (strcmp(args[0], "mkdir") == 0) {
        if (argc!= 3) {
            fprintf(stderr, "Error: Invalid number of arguments for'mkdir'.\n");
            exit(1);
        }
        printf("Creating directory '%s'...\n", args[2]);
    } else if (strcmp(args[0], "rmdir") == 0) {
        if (argc!= 3) {
            fprintf(stderr, "Error: Invalid number of arguments for 'rmdir'.\n");
            exit(1);
        }
        printf("Removing directory '%s'...\n", args[2]);
    } else if (strcmp(args[0], "touch") == 0) {
        if (argc!= 3) {
            fprintf(stderr, "Error: Invalid number of arguments for 'touch'.\n");
            exit(1);
        }
        printf("Creating file '%s'...\n", args[2]);
    } else {
        fprintf(stderr, "Error: Unknown command '%s'.\n", args[0]);
        exit(1);
    }

    // Free command line arguments
    for (int i = 0; i < argc; i++) {
        free(args[i]);
    }
    free(args);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No command specified.\n");
        exit(1);
    }

    // Execute command
    execute_command(argv[1]);

    return 0;
}