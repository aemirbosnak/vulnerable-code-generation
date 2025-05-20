//FormAI DATASET v1.0 Category: Smart home light control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms and lights
#define MAX_ROOMS 10
#define MAX_LIGHTS 5

// Define the maximum length of the room and light names
#define MAX_NAME_LENGTH 20

// Define a global array to store the light states
int lightState[MAX_ROOMS][MAX_LIGHTS];

// Define a function to turn on a light
void turnOnLight(int roomNum, int lightNum) {
    lightState[roomNum][lightNum] = 1;
    printf("Light %d in room %d turned on\n", lightNum + 1, roomNum + 1);
}

// Define a function to turn off a light
void turnOffLight(int roomNum, int lightNum) {
    lightState[roomNum][lightNum] = 0;
    printf("Light %d in room %d turned off\n", lightNum + 1, roomNum + 1);
}

int main() {
    // Define variables for user input
    char input[100];
    char command[20];
    char roomName[MAX_NAME_LENGTH];
    char lightName[MAX_NAME_LENGTH];

    // Define variables for room and light indexes
    int roomIndex;
    int lightIndex;

    // Set all lights to off initially
    memset(lightState, 0, sizeof(lightState));

    // Define an array of room names and a count of rooms
    char roomNames[MAX_ROOMS][MAX_NAME_LENGTH] = {"Living Room", "Kitchen", "Bedroom", "Bathroom", "Office"};
    int numRooms = 5;

    // Define an array of light names and a count of lights per room
    char lightNames[MAX_LIGHTS][MAX_NAME_LENGTH] = {"Ceiling", "Lamp", "Floor Lamp", "Desk Lamp", "Night Light"};
    int numLights = 5;

    printf("Welcome to Smart Home Light Control\n");

    // Loop to accept user commands
    while (1) {
        printf("Enter a command (e.g. 'turn on living room ceiling'):\n");
        fgets(input, sizeof(input), stdin);

        // Parse the command
        sscanf(input, "%s %s %s %s", command, roomName, lightName);

        // Look up the room index
        for (int i = 0; i < numRooms; i++) {
            if (strcmp(roomNames[i], roomName) == 0) {
                roomIndex = i;
                break;
            }
        }

        // Look up the light index
        for (int i = 0; i < numLights; i++) {
            if (strcmp(lightNames[i], lightName) == 0) {
                lightIndex = i;
                break;
            }
        }

        // Execute the command
        if (strcmp(command, "turn") == 0) {
            // Turn on or off the light
            sscanf(input, "%*s %*s %*s %s", command);
            if (strcmp(command, "on") == 0) {
                turnOnLight(roomIndex, lightIndex);
            } else if (strcmp(command, "off") == 0) {
                turnOffLight(roomIndex, lightIndex);
            } else {
                printf("Invalid command\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            // Exit the program
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}