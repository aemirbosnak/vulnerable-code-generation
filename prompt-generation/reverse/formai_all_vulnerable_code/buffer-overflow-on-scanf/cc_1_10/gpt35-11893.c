//FormAI DATASET v1.0 Category: Smart home light control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define constants for the maximum number of lights and the maximum number of rooms
#define MAX_LIGHTS 10
#define MAX_ROOMS 5

// define a structure for properties of a light
typedef struct {
    bool isOn;
    int brightness;
} Light;

// define a structure for properties of a room
typedef struct {
    char name[20];
    Light lights[MAX_LIGHTS];
    int numLights;
} Room;

// function to turn on/off a light
void controlLight(Light *light, bool isOn) {
    light->isOn = isOn;
    if (isOn) {
        light->brightness = 100;
    } else {
        light->brightness = 0;
    }
}

// function to adjust the brightness of a light
void changeBrightness(Light *light, int brightness) {
    light->brightness = brightness;
    if (brightness > 0) {
        light->isOn = true;
    } else {
        light->isOn = false;
    }
}

int main() {
    // declare variables
    Room rooms[MAX_ROOMS];
    int numRooms = 0;

    // ask for user input to add rooms
    char input[20];
    while (true) {
        printf("Enter room name (or 'done' to finish adding rooms): ");
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }
        Room newRoom;
        strcpy(newRoom.name, input);
        newRoom.numLights = 0;
        rooms[numRooms++] = newRoom;
    }

    // ask for user input to add lights to rooms
    for (int i = 0; i < numRooms; i++) {
        printf("Enter number of lights in %s: ", rooms[i].name);
        int numLights;
        scanf("%d", &numLights);
        rooms[i].numLights = numLights;
        for (int j = 0; j < numLights; j++) {
            Light newLight;
            newLight.isOn = false;
            newLight.brightness = 0;
            rooms[i].lights[j] = newLight;
        }
    }

    // control the lights
    while (true) {
        // print menu of available rooms and their lights
        printf("\nRooms:\n");
        for (int i = 0; i < numRooms; i++) {
            printf(" - %s: ", rooms[i].name);
            for (int j = 0; j < rooms[i].numLights; j++) {
                printf("[%d]", rooms[i].lights[j].brightness);
                if (rooms[i].lights[j].isOn) {
                    printf("on ");
                } else {
                    printf("off ");
                }
            }
            printf("\n");
        }

        // ask for user input to control lights
        int roomIndex, lightIndex, actionIndex, brightnessIndex;
        printf("Enter room number, light number, action (on/off), and brightness (0-100) separated by spaces: ");
        scanf("%d %d %d %d", &roomIndex, &lightIndex, &actionIndex, &brightnessIndex);

        // validate user input
        if (roomIndex < 1 || roomIndex > numRooms ||
            lightIndex < 1 || lightIndex > rooms[roomIndex-1].numLights ||
            actionIndex < 0 || actionIndex > 1 ||
            brightnessIndex < 0 || brightnessIndex > 100) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // control the light based on user input
        if (actionIndex == 0) { // turn off
            controlLight(&rooms[roomIndex-1].lights[lightIndex-1], false);
        } else { // turn on and adjust brightness
            controlLight(&rooms[roomIndex-1].lights[lightIndex-1], true);
            changeBrightness(&rooms[roomIndex-1].lights[lightIndex-1], brightnessIndex);
        }
    }

    return 0;
}