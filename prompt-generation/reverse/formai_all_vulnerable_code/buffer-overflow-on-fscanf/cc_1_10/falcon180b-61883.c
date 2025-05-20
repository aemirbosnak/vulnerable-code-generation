//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 80
#define MAX_COMMANDS 100

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int frequency;
} Command;

void readCommands(Command commands[], int numCommands) {
    FILE *file = fopen("commands.txt", "r");
    if (file == NULL) {
        printf("Error: could not open commands file.\n");
        exit(1);
    }

    int i = 0;
    while (i < numCommands && fscanf(file, "%s %d", commands[i].command, &commands[i].frequency)!= EOF) {
        i++;
    }

    fclose(file);
}

void executeCommand(char command[]) {
    system(command);
}

int main() {
    Command commands[MAX_COMMANDS];
    int numCommands = 0;

    readCommands(commands, MAX_COMMANDS);

    while (1) {
        char input[MAX_COMMAND_LENGTH];
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "list") == 0) {
            for (int i = 0; i < numCommands; i++) {
                printf("%s (%d)\n", commands[i].command, commands[i].frequency);
            }
        } else {
            int found = 0;
            for (int i = 0; i < numCommands; i++) {
                if (strcmp(input, commands[i].command) == 0) {
                    executeCommand(commands[i].command);
                    commands[i].frequency++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Command not found.\n");
            }
        }
    }

    return 0;
}