//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Light states
#define OFF 0
#define ON  1

// Room names
char *rooms[] = {
    "Living Room",
    "Kitchen",
    "Bedroom",
    "Bathroom"
};

// Light states for each room
int lightStates[sizeof(rooms) / sizeof(char *)];

// Function to turn on a light
void turnOnLight(char *room) {
    for (int i = 0; i < sizeof(rooms) / sizeof(char *); i++) {
        if (strcmp(room, rooms[i]) == 0) {
            lightStates[i] = ON;
            printf("Light in %s turned on.\n", room);
            return;
        }
    }

    printf("Invalid room name.\n");
}

// Function to turn off a light
void turnOffLight(char *room) {
    for (int i = 0; i < sizeof(rooms) / sizeof(char *); i++) {
        if (strcmp(room, rooms[i]) == 0) {
            lightStates[i] = OFF;
            printf("Light in %s turned off.\n", room);
            return;
        }
    }

    printf("Invalid room name.\n");
}

// Function to get the state of a light
int getLightState(char *room) {
    for (int i = 0; i < sizeof(rooms) / sizeof(char *); i++) {
        if (strcmp(room, rooms[i]) == 0) {
            return lightStates[i];
        }
    }

    printf("Invalid room name.\n");
    return -1;
}

// Main function
int main() {
    // Initialize light states
    for (int i = 0; i < sizeof(rooms) / sizeof(char *); i++) {
        lightStates[i] = OFF;
    }

    // Command loop
    while (1) {
        char command[100];
        char room[100];

        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "on") == 0) {
            scanf("%s", room);
            turnOnLight(room);
        } else if (strcmp(command, "off") == 0) {
            scanf("%s", room);
            turnOffLight(room);
        } else if (strcmp(command, "status") == 0) {
            scanf("%s", room);
            int state = getLightState(room);
            if (state == ON) {
                printf("Light in %s is on.\n", room);
            } else if (state == OFF) {
                printf("Light in %s is off.\n", room);
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}