//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COMMANDS 4
#define COMMAND_MAX_LENGTH 10

typedef struct {
    char *name;
    void (*function)(void);
} Command;

void goForward(void) {
    printf("The vehicle moves forward.\n");
}

void goBackward(void) {
    printf("The vehicle moves backward.\n");
}

void turnLeft(void) {
    printf("The vehicle turns left.\n");
}

void turnRight(void) {
    printf("The vehicle turns right.\n");
}

Command commands[] = {
    {"forward", goForward},
    {"backward", goBackward},
    {"left", turnLeft},
    {"right", turnRight}
};

int main(void) {
    srand(time(NULL));

    printf("Welcome to the remote control vehicle simulation!\n");
    printf("Available commands: ");
    for (int i = 0; i < NUM_COMMANDS; i++) {
        printf("%s ", commands[i].name);
    }
    printf("\n");

    char command[COMMAND_MAX_LENGTH];
    while (1) {
        printf("Enter a command: ");
        scanf("%s", command);

        int found = 0;
        for (int i = 0; i < NUM_COMMANDS; i++) {
            if (strcmp(command, commands[i].name) == 0) {
                commands[i].function();
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Invalid command.\n");
        }
    }

    return 0;
}