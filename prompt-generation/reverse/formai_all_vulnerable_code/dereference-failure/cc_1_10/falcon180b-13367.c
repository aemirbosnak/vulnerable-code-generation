//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_COMMANDS 100

typedef struct command {
    char *name;
    void (*function)();
} Command;

int num_commands = 0;
Command *commands = NULL;

void add_command(char *name, void (*function)()) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Too many commands.\n");
        return;
    }

    commands = realloc(commands, sizeof(Command) * (num_commands + 1));

    commands[num_commands].name = strdup(name);
    commands[num_commands].function = function;

    num_commands++;
}

void execute_command(char *input) {
    int i;
    char *command;
    char *arguments[10];
    int num_arguments = 0;

    command = strtok(input, " ");

    for (i = 0; i < num_commands; i++) {
        if (strcmp(command, commands[i].name) == 0) {
            commands[i].function();
            return;
        }
    }

    printf("Error: Unknown command '%s'.\n", command);
}

void help_command() {
    printf("Available commands:\n");
    for (int i = 0; i < num_commands; i++) {
        printf("%s\n", commands[i].name);
    }
}

void exit_command() {
    exit(0);
}

int main() {
    add_command("help", help_command);
    add_command("exit", exit_command);

    char input[100];

    while (TRUE) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        execute_command(input);
    }

    return 0;
}