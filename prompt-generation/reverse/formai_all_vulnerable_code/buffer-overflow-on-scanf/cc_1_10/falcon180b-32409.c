//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_ROOMS 5
#define NUM_LIGHTS 3

typedef struct {
    char name[20];
    bool lights[NUM_LIGHTS];
} Room;

Room rooms[NUM_ROOMS] = {
    {"Living Room", {true, true, true}},
    {"Kitchen", {true, false, true}},
    {"Bedroom", {false, true, false}},
    {"Bathroom", {true, false, false}},
    {"Hallway", {true, false, false}}
};

void turnOnLight(int roomNum, int lightNum) {
    printf("Turning on light %d in room %s\n", lightNum + 1, rooms[roomNum].name);
}

void turnOffLight(int roomNum, int lightNum) {
    printf("Turning off light %d in room %s\n", lightNum + 1, rooms[roomNum].name);
}

void toggleLight(int roomNum, int lightNum) {
    if (rooms[roomNum].lights[lightNum]) {
        turnOffLight(roomNum, lightNum);
    } else {
        turnOnLight(roomNum, lightNum);
    }
}

int main() {
    int roomNum, lightNum;
    char command[20];

    printf("Welcome to the Smart Home Light Control System!\n");
    printf("Please enter a command in the format: roomNum lightNum action\n");
    printf("Where roomNum is the number of the room (1-5), lightNum is the number of the light (1-3), and action is either 'on', 'off', or 'toggle'.\n");

    while (true) {
        scanf("%d %d %s", &roomNum, &lightNum, command);

        if (roomNum < 1 || roomNum > NUM_ROOMS || lightNum < 1 || lightNum > NUM_LIGHTS) {
            printf("Invalid room or light number.\n");
        } else if (strcmp(command, "on") == 0) {
            turnOnLight(roomNum - 1, lightNum - 1);
        } else if (strcmp(command, "off") == 0) {
            turnOffLight(roomNum - 1, lightNum - 1);
        } else if (strcmp(command, "toggle") == 0) {
            toggleLight(roomNum - 1, lightNum - 1);
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}