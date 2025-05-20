//Falcon-180B DATASET v1.0 Category: System administration ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
#define MAX_ARGUMENT_LENGTH 50

typedef struct {
    char *command;
    char **arguments;
    int num_arguments;
} Command;

void execute_command(Command *cmd) {
    if (strcmp(cmd->command, "ls") == 0) {
        printf("Listing files...\n");
        for (int i = 0; i < cmd->num_arguments; i++) {
            printf("%s\n", cmd->arguments[i]);
        }
    } else if (strcmp(cmd->command, "mkdir") == 0) {
        printf("Creating directory...\n");
    } else if (strcmp(cmd->command, "rm") == 0) {
        printf("Deleting file...\n");
    } else {
        printf("Unknown command: %s\n", cmd->command);
    }
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    Command command;

    while (fgets(input_buffer, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        int num_arguments = 0;
        char *token = strtok(input_buffer, " ");
        while (token!= NULL) {
            if (num_arguments >= MAX_ARGUMENTS) {
                printf("Too many arguments\n");
                break;
            }
            if (strlen(token) >= MAX_ARGUMENT_LENGTH) {
                printf("Argument too long\n");
                break;
            }
            command.arguments[num_arguments] = strdup(token);
            num_arguments++;
            token = strtok(NULL, " ");
        }
        if (num_arguments == 0) {
            printf("No arguments\n");
        } else {
            command.command = strdup(command.arguments[0]);
            command.num_arguments = num_arguments;
            execute_command(&command);
        }
    }

    return 0;
}