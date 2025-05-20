//FormAI DATASET v1.0 Category: Smart home automation ; Style: immersive
#include <stdio.h>
#include <string.h>

// Function to turn on the lights in the living room
void living_room_lights_on() {
    printf("Living room lights turned on\n");
}

// Function to turn off the lights in the living room
void living_room_lights_off() {
    printf("Living room lights turned off\n");
}

// Function to turn on the A/C in the living room
void living_room_ac_on() {
    printf("Living room A/C turned on\n");
}

// Function to turn off the A/C in the living room
void living_room_ac_off() {
    printf("Living room A/C turned off\n");
}

int main() {
    printf("Welcome to Smart Home Automation System\n");
    printf("--------------------------------------\n\n");

    int living_room_lights = 0;
    int living_room_ac = 0;

    printf("What would you like to do?\n\n");

    while (1) {
        char command[50];
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "living_room_lights_on") == 0) {
            if (living_room_lights == 0) {
                living_room_lights_on();
                living_room_lights = 1;
            } else {
                printf("Living room lights are already on\n");
            }
        } else if (strcmp(command, "living_room_lights_off") == 0) {
            if (living_room_lights == 1) {
                living_room_lights_off();
                living_room_lights = 0;
            } else {
                printf("Living room lights are already off\n");
            }
        } else if (strcmp(command, "living_room_ac_on") == 0) {
            if (living_room_ac == 0) {
                living_room_ac_on();
                living_room_ac = 1;
            } else {
                printf("Living room A/C is already on\n");
            }
        } else if (strcmp(command, "living_room_ac_off") == 0) {
            if (living_room_ac == 1) {
                living_room_ac_off();
                living_room_ac = 0;
            } else {
                printf("Living room A/C is already off\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Please try again\n");
        }
    }

    return 0;
}