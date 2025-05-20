//Falcon-180B DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 80
#define MAX_ARGUMENTS 10
#define MAX_ARGUMENT_LENGTH 80

typedef struct {
    char *command;
    char **arguments;
    int num_arguments;
} command_t;

int num_commands = 0;
command_t commands[MAX_COMMANDS];

void add_command(char *command, int num_arguments, char **arguments) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Too many commands!\n");
        exit(1);
    }

    commands[num_commands].command = strdup(command);
    commands[num_commands].num_arguments = num_arguments;
    commands[num_commands].arguments = malloc(sizeof(char *) * num_arguments);

    for (int i = 0; i < num_arguments; i++) {
        commands[num_commands].arguments[i] = strdup(arguments[i]);
    }

    num_commands++;
}

int main(int argc, char **argv) {
    add_command("echo", 1, argv + 1);
    add_command("ls", 0, NULL);
    add_command("mkdir", 1, argv + 2);

    char *input;
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *command = strtok(input, " ");
        if (command == NULL) {
            continue;
        }

        int i = 0;
        while (commands[i].command!= NULL) {
            if (strcmp(command, commands[i].command) == 0) {
                if (commands[i].num_arguments > 0) {
                    char **arguments = malloc(sizeof(char *) * commands[i].num_arguments);

                    for (int j = 0; j < commands[i].num_arguments; j++) {
                        arguments[j] = strdup(input + strlen(command) + 1);
                    }

                    system(commands[i].command);
                    for (int j = 0; j < commands[i].num_arguments; j++) {
                        free(arguments[j]);
                    }
                    free(arguments);
                } else {
                    system(commands[i].command);
                }

                break;
            }

            i++;
        }

        if (commands[i].command == NULL) {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}