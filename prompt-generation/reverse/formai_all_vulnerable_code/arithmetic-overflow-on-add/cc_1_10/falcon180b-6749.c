//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 100
#define MAX_COMMAND_LENGTH 100

typedef struct {
    char *command;
    int frequency;
} Command;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    int num_commands = 0;
    Command commands[MAX_COMMANDS];

    char line[MAX_COMMAND_LENGTH];
    while (fgets(line, MAX_COMMAND_LENGTH, log_file)!= NULL) {
        if (num_commands >= MAX_COMMANDS) {
            printf("Maximum number of commands reached.\n");
            break;
        }

        char *command = strtok(line, " ");
        if (command == NULL) {
            continue;
        }

        Command *found_command = NULL;
        for (int i = 0; i < num_commands; i++) {
            if (strcmp(commands[i].command, command) == 0) {
                found_command = &commands[i];
                break;
            }
        }

        if (found_command == NULL) {
            found_command = &commands[num_commands++];
            strcpy(found_command->command, command);
        }

        found_command->frequency++;
    }

    fclose(log_file);

    printf("Commands:\n");
    for (int i = 0; i < num_commands; i++) {
        printf("%s: %d\n", commands[i].command, commands[i].frequency);
    }

    return 0;
}