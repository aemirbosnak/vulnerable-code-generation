//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char *command;
    void (*function)(void);
} Command;

void turnOnLight(void) {
    printf("Turning on the lights...\n");
}

void turnOffLight(void) {
    printf("Turning off the lights...\n");
}

void lockDoor(void) {
    printf("Locking the door...\n");
}

void unlockDoor(void) {
    printf("Unlocking the door...\n");
}

int main(int argc, char *argv[]) {
    int numCommands = 0;
    Command commands[MAX_COMMANDS];

    strcpy(commands[numCommands].command, "turnOnLight");
    commands[numCommands].function = turnOnLight;
    numCommands++;

    strcpy(commands[numCommands].command, "turnOffLight");
    commands[numCommands].function = turnOffLight;
    numCommands++;

    strcpy(commands[numCommands].command, "lockDoor");
    commands[numCommands].function = lockDoor;
    numCommands++;

    strcpy(commands[numCommands].command, "unlockDoor");
    commands[numCommands].function = unlockDoor;
    numCommands++;

    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        input[strcspn(input, "\n")] = '\0';

        for (int i = 0; i < numCommands; i++) {
            if (strcmp(commands[i].command, input) == 0) {
                commands[i].function();
            }
        }
    }

    return 0;
}