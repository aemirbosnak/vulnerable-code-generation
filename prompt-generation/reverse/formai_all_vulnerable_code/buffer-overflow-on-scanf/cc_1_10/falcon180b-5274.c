//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_LENGTH 50

typedef struct {
    char command[MAX_LENGTH];
    void (*function)(void);
} Command;

void turnOnLight(void) {
    printf("Turning on the light!\n");
}

void turnOffLight(void) {
    printf("Turning off the light!\n");
}

void openDoor(void) {
    printf("Opening the door!\n");
}

void closeDoor(void) {
    printf("Closing the door!\n");
}

int main(int argc, char *argv[]) {
    Command commands[MAX_COMMANDS] = {{"turnOnLight", turnOnLight},
                                      {"turnOffLight", turnOffLight},
                                      {"openDoor", openDoor},
                                      {"closeDoor", closeDoor}};

    char input[MAX_LENGTH];

    printf("Welcome to the Smart Home Automation System!\n");
    printf("Enter a command: ");
    scanf("%s", input);

    int i;
    for (i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(input, commands[i].command) == 0) {
            commands[i].function();
            break;
        }
    }

    if (i == MAX_COMMANDS) {
        printf("Invalid command!\n");
    }

    return 0;
}

/*
Sample output:

Welcome to the Smart Home Automation System!
Enter a command: turnOnLight
Turning on the light!

Enter a command: closeDoor
Closing the door!

Enter a command: openDoor
Opening the door!

Enter a command: turnOffLight
Turning off the light!

Enter a command: hello
Invalid command!
*/