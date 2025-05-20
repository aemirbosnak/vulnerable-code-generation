//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARG_COUNT 100

typedef struct {
    char *name;
    char *description;
    void (*function)(int argc, char **argv);
} command_t;

void print_help() {
    printf("Available commands:\n");
    for (int i = 0; i < 2; i++) {
        printf("  %s - %s\n", "help", "Print this help message");
        printf("  %s - %s\n", "exit", "Exit the program");
    }
}

void execute_command(int argc, char **argv) {
    if (argc == 1) {
        print_help();
    } else if (strcmp(argv[1], "help") == 0) {
        print_help();
    } else if (strcmp(argv[1], "exit") == 0) {
        exit(0);
    } else {
        printf("Invalid command: %s\n", argv[1]);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *token;
    int argc;
    char **argv;

    command_t commands[] = {
        {"help", "Print this help message", execute_command},
        {"exit", "Exit the program", execute_command}
    };

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        argc = 0;
        argv = malloc(MAX_ARG_COUNT * sizeof(char *));
        if (argv == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }

        token = strtok(input, " ");
        while (token!= NULL) {
            argv[argc++] = token;
            if (argc >= MAX_ARG_COUNT) {
                printf("Error: Too many arguments\n");
                exit(1);
            }
            token = strtok(NULL, " ");
        }
        argv[argc] = NULL;

        for (int i = 0; i < 2; i++) {
            if (strcmp(argv[1], commands[i].name) == 0) {
                commands[i].function(argc, argv);
                break;
            }
        }
    }

    return 0;
}