//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// An array of all the lights in the house
struct light {
    char *name;
    int state; // 0 = off, 1 = on
};

struct light lights[] = {
    { "Kitchen", 0 },
    { "Living Room", 0 },
    { "Bedroom", 0 },
    { "Bathroom", 0 },
    { "Garage", 0 },
};

// A function to print the state of all the lights
void print_lights() {
    for (int i = 0; i < sizeof(lights) / sizeof(struct light); i++) {
        printf("%s: %s\n", lights[i].name, lights[i].state ? "on" : "off");
    }
}

// A function to turn a light on
void turn_on(char *name) {
    for (int i = 0; i < sizeof(lights) / sizeof(struct light); i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].state = 1;
            break;
        }
    }
}

// A function to turn a light off
void turn_off(char *name) {
    for (int i = 0; i < sizeof(lights) / sizeof(struct light); i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].state = 0;
            break;
        }
    }
}

// A function to handle commands
void handle_command(char *command) {
    char *parts[3];
    int num_parts = 0;

    // Split the command into parts
    char *part = strtok(command, " ");
    while (part != NULL) {
        parts[num_parts++] = part;
        part = strtok(NULL, " ");
    }

    // Check if the command is valid
    if (num_parts != 3 || strcmp(parts[0], "turn") != 0 || (strcmp(parts[1], "on") != 0 && strcmp(parts[1], "off") != 0)) {
        printf("Invalid command\n");
        return;
    }

    // Execute the command
    if (strcmp(parts[1], "on") == 0) {
        turn_on(parts[2]);
    } else {
        turn_off(parts[2]);
    }
}

// The main function
int main() {
    // Print the initial state of the lights
    print_lights();

    // Get the first command
    char command[100];
    printf("Enter a command: ");
    fgets(command, sizeof(command), stdin);

    // Handle the command
    handle_command(command);

    // Print the new state of the lights
    print_lights();

    return 0;
}