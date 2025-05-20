//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10
#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    int light_index;
} Command;

int main() {
    char input[MAX_COMMAND_LENGTH];
    Command commands[MAX_COMMANDS];
    int num_commands = 0;
    int num_lights = 0;

    printf("Welcome to the Smart Home Light Control System!\n");

    // Initialize lights
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("Enter name for light %d: ", i+1);
        scanf("%s", input);
        strcpy(commands[num_commands].name, input);
        commands[num_commands].light_index = i;
        num_commands++;
        num_lights++;
    }

    while (1) {
        printf("\nEnter command: ");
        scanf("%s", input);

        if (strcmp(input, "on") == 0) {
            for (int i = 0; i < num_lights; i++) {
                printf("Turning on %s...\n", commands[i].name);
            }
        } else if (strcmp(input, "off") == 0) {
            for (int i = 0; i < num_lights; i++) {
                printf("Turning off %s...\n", commands[i].name);
            }
        } else if (strcmp(input, "status") == 0) {
            for (int i = 0; i < num_lights; i++) {
                printf("Light %s is %s\n", commands[i].name, (commands[i].light_index == 1? "on" : "off"));
            }
        } else {
            for (int i = 0; i < num_commands; i++) {
                if (strcmp(input, commands[i].name) == 0) {
                    printf("Turning on %s...\n", commands[i].name);
                    break;
                }
            }
        }
    }

    return 0;
}