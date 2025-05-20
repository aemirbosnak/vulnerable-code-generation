//Falcon-180B DATASET v1.0 Category: System administration ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

typedef struct {
    char *name;
    void (*function)(char **args);
} command_t;

int num_commands = 0;
command_t commands[MAX_COMMANDS];

void add_command(char *name, void (*function)(char **args)) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Too many commands.\n");
        return;
    }

    commands[num_commands].name = name;
    commands[num_commands].function = function;
    num_commands++;
}

void execute_command(char *input) {
    char *command = strtok(input, " ");
    int i;

    for (i = 0; i < num_commands; i++) {
        if (strcmp(command, commands[i].name) == 0) {
            char **args = malloc(sizeof(char *) * (strlen(input) / strlen(command) + 1));
            int j;

            args[0] = strdup(input);
            for (j = 1; j < strlen(input) / strlen(command); j++) {
                args[j] = strtok(NULL, " ");
            }
            args[j] = NULL;

            commands[i].function(args);
            free(args);
            return;
        }
    }

    printf("Error: Unknown command.\n");
}

void help_command(char **args) {
    printf("Available commands:\n");
    int i;

    for (i = 0; i < num_commands; i++) {
        printf("%s\n", commands[i].name);
    }
}

int main() {
    add_command("help", help_command);
    add_command("exit", NULL);

    char input[1024];

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        execute_command(input);
    }

    return 0;
}