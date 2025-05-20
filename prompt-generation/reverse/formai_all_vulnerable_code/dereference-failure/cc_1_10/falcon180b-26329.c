//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 64
#define NUM_COMMANDS 5

typedef struct {
    char *command;
    void (*function)(char *);
} command_t;

void turn_on_lights(char *room) {
    printf("Turning on lights in %s\n", room);
}

void turn_off_lights(char *room) {
    printf("Turning off lights in %s\n", room);
}

void set_light_color(char *room, char *color) {
    printf("Setting light color in %s to %s\n", room, color);
}

void set_light_brightness(char *room, int brightness) {
    printf("Setting light brightness in %s to %d\n", room, brightness);
}

command_t commands[NUM_COMMANDS] = {
    {"turn_on_lights", turn_on_lights},
    {"turn_off_lights", turn_off_lights},
    {"set_light_color", set_light_color},
    {"set_light_brightness", set_light_brightness}
};

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *room = NULL;
    char *color = NULL;
    int brightness = 0;

    printf("Enter a command (e.g. turn_on_lights living_room): ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char *command = strtok(input, " ");
    while (command!= NULL) {
        if (isalpha(command[0])) {
            room = command;
        } else {
            for (int i = 0; i < NUM_COMMANDS; i++) {
                if (strcmp(command, commands[i].command) == 0) {
                    commands[i].function(room);
                    break;
                }
            }
        }
        command = strtok(NULL, " ");
    }

    return 0;
}