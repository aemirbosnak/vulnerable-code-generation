//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void turn_on_light(void) {
    printf("Turning on the light.\n");
}

void turn_off_light(void) {
    printf("Turning off the light.\n");
}

void set_light_brightness(int brightness) {
    printf("Setting light brightness to %d.\n", brightness);
}

int main(void) {
    int i;
    command_t commands[MAX_COMMANDS];
    char input[MAX_COMMAND_LENGTH];

    // Initialize commands
    commands[0] = (command_t) {"turn_on_light", turn_on_light};
    commands[1] = (command_t) {"turn_off_light", turn_off_light};
    commands[2] = (command_t) {"set_light_brightness", set_light_brightness};

    // Get user input
    printf("Enter a command:\n");
    scanf("%s", input);

    // Convert input to lowercase
    for (i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // Check if input matches a command
    for (i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(input, commands[i].command) == 0) {
            (*commands[i].function)();
            return 0;
        }
    }

    // Input not recognized
    printf("Invalid command.\n");
    return 1;
}