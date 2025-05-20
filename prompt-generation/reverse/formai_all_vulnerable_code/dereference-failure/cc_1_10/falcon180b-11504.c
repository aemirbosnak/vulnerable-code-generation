//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int frequency;
    int duration;
} Command;

int main() {
    int num_commands = 0;
    Command commands[MAX_COMMANDS];
    char input[MAX_COMMAND_LENGTH];

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Enter commands in the format 'command frequency duration':\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)) {
        if (num_commands >= MAX_COMMANDS) {
            printf("Maximum number of commands reached.\n");
            break;
        }

        char *command = strtok(input, " ");
        if (command == NULL) {
            continue;
        }

        int frequency = atoi(strtok(NULL, " "));
        int duration = atoi(strtok(NULL, " "));

        strncpy(commands[num_commands].command, command, MAX_COMMAND_LENGTH - 1);
        commands[num_commands].command[MAX_COMMAND_LENGTH - 1] = '\0';
        commands[num_commands].frequency = frequency;
        commands[num_commands].duration = duration;

        num_commands++;
    }

    if (num_commands == 0) {
        printf("No commands entered.\n");
        return 1;
    }

    printf("Commands entered:\n");
    for (int i = 0; i < num_commands; i++) {
        printf("%s %d %d\n", commands[i].command, commands[i].frequency, commands[i].duration);
    }

    int choice;
    printf("Choose a command to execute:\n");
    for (int i = 0; i < num_commands; i++) {
        printf("%d. %s\n", i + 1, commands[i].command);
    }

    scanf("%d", &choice);

    Command *selected_command = &commands[choice - 1];

    printf("Executing command '%s' at %d Hz for %d seconds...\n", selected_command->command, selected_command->frequency, selected_command->duration);

    for (int i = 0; i < selected_command->duration; i++) {
        for (int j = 0; j < selected_command->frequency; j++) {
            printf("%s ", selected_command->command);
        }
        printf("\n");
    }

    return 0;
}