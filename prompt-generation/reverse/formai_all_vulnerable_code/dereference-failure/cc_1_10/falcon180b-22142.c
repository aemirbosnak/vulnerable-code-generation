//Falcon-180B DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
#define DELIMITER " "

typedef struct {
    char *command;
    char **arguments;
    int argument_count;
} Command;

void parse_command(char *input, Command *command) {
    char *token = strtok(input, DELIMITER);
    command->command = strdup(token);
    command->arguments = malloc(sizeof(char *) * MAX_ARGUMENTS);
    int argument_count = 0;
    while ((token = strtok(NULL, DELIMITER))!= NULL) {
        if (argument_count >= MAX_ARGUMENTS) {
            printf("Error: Too many arguments for command '%s'\n", command->command);
            exit(1);
        }
        command->arguments[argument_count] = strdup(token);
        argument_count++;
    }
    command->argument_count = argument_count;
}

void execute_command(Command *command) {
    if (strcmp(command->command, "mkdir") == 0) {
        if (command->argument_count!= 2) {
            printf("Error: Invalid number of arguments for'mkdir' command\n");
            return;
        }
        mkdir(command->arguments[1], 0755);
    } else if (strcmp(command->command, "rmdir") == 0) {
        if (command->argument_count!= 2) {
            printf("Error: Invalid number of arguments for 'rmdir' command\n");
            return;
        }
        rmdir(command->arguments[1]);
    } else if (strcmp(command->command, "touch") == 0) {
        if (command->argument_count!= 2) {
            printf("Error: Invalid number of arguments for 'touch' command\n");
            return;
        }
        FILE *file = fopen(command->arguments[1], "w");
        if (file == NULL) {
            printf("Error: Could not create file '%s'\n", command->arguments[1]);
        } else {
            fclose(file);
        }
    } else {
        printf("Error: Unknown command '%s'\n", command->command);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command [arguments]\n", argv[0]);
        return 1;
    }

    char input[MAX_COMMAND_LENGTH];
    strcpy(input, argv[1]);
    Command command;
    parse_command(input, &command);
    execute_command(&command);

    return 0;
}