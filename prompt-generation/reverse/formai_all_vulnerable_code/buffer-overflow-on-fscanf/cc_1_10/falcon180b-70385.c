//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 100

typedef struct {
    char *command;
    int frequency;
} Command;

void readCommands(Command commands[], int numCommands) {
    FILE *file = fopen("commands.txt", "r");
    if (file == NULL) {
        printf("Error: could not open commands file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %d", commands[i].command, &commands[i].frequency) == 2 && i < numCommands) {
        i++;
    }

    fclose(file);
}

void executeCommand(char *command) {
    system(command);
}

int main() {
    Command commands[MAX_COMMANDS];
    int numCommands = 0;

    readCommands(commands, MAX_COMMANDS);

    while (1) {
        char input[100];
        printf("Enter a command: ");
        fgets(input, 100, stdin);

        char *token = strtok(input, " ");
        while (token!= NULL) {
            int j;
            for (j = 0; j < numCommands; j++) {
                if (strcmp(token, commands[j].command) == 0) {
                    executeCommand(commands[j].command);
                    commands[j].frequency++;
                    break;
                }
            }

            if (j == numCommands) {
                printf("Unknown command: %s\n", token);
            }

            token = strtok(NULL, " ");
        }
    }

    return 0;
}