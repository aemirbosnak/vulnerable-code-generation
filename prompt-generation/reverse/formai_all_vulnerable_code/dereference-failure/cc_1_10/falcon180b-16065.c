//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
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
    command_t commands[MAX_COMMANDS] = {{"turn_on_light", turn_on_light},
                                        {"turn_off_light", turn_off_light},
                                        {"set_light_brightness", set_light_brightness}};
    char input[MAX_COMMAND_LENGTH];
    int i;

    printf("Smart Home Light Control\n");
    printf("Enter commands followed by ENTER:\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)) {
        input[strcspn(input, "\n")] = '\0';
        for (i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                commands[i].function();
                break;
            }
        }
        if (i == MAX_COMMANDS) {
            printf("Invalid command.\n");
        }
    }

    return 0;
}