//Falcon-180B DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_ARGS 10
#define MAX_COMMAND_LENGTH 80
#define MAX_ARG_LENGTH 80

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    char args[MAX_COMMANDS][MAX_ARG_LENGTH];
    int num_args;
} Command;

void execute_command(Command* command) {
    if (strcmp(command->command, "ls") == 0) {
        for (int i = 0; i < command->num_args; i++) {
            printf("%s ", command->args[i]);
        }
        printf("\n");
    } else if (strcmp(command->command, "mkdir") == 0) {
        system(command->args[0]);
    } else if (strcmp(command->command, "cd") == 0) {
        system(command->args[0]);
    } else if (strcmp(command->command, "pwd") == 0) {
        system(command->args[0]);
    } else {
        printf("Invalid command\n");
    }
}

void parse_command(char* input, Command* command) {
    int i = 0;
    char* token = strtok(input, " ");
    strcpy(command->command, token);
    i++;

    while (i < MAX_COMMANDS && (token = strtok(NULL, " "))!= NULL) {
        strcpy(command->args[i], token);
        i++;
    }

    command->num_args = i;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    Command command;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        parse_command(input, &command);
        execute_command(&command);
    }

    return 0;
}