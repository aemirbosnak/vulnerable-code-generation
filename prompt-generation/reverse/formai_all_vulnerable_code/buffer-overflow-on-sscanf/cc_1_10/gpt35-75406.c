//FormAI DATASET v1.0 Category: Smart home light control ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROOMS 5 // maximum number of rooms
#define MAX_LIGHTS 10 // maximum number of lights per room
#define ON 1 // light on state
#define OFF 0 // light off state

// define room structure
struct Room {
    char name[20];
    int num_lights;
    int light_state[MAX_LIGHTS];
};

// initialize rooms
struct Room rooms[MAX_ROOMS] = {
    {"Living Room", 2, {OFF, OFF}},
    {"Dining Room", 1, {OFF}},
    {"Bedroom", 3, {OFF, OFF, OFF}},
    {"Bathroom", 1, {OFF}},
    {"Kitchen", 2, {OFF, OFF}}
};

// turn light on/off
void toggleLight(int room, int light) {
    if (rooms[room-1].light_state[light-1] == ON) {
        rooms[room-1].light_state[light-1] = OFF;
        printf("Light %d in %s turned off\n", light, rooms[room-1].name);
    } else {
        rooms[room-1].light_state[light-1] = ON;
        printf("Light %d in %s turned on\n", light, rooms[room-1].name);
    }
}

// print all lights in a given room
void printLights(int room) {
    printf("%s Lights:\n", rooms[room-1].name);
    for (int i = 0; i < rooms[room-1].num_lights; i++) {
        printf("Light %d is %s\n", i+1, rooms[room-1].light_state[i] ? "on" : "off");
    }
}

int main() {
    int room, light, choice;
    char buffer[20];
    
    printf("Welcome to Smart Home Light Control!\n");
    while (1) {
        printf("\nEnter room number (1-%d) or 0 to quit: ", MAX_ROOMS);
        fgets(buffer, 20, stdin);
        sscanf(buffer, "%d", &room);
        
        if (room == 0) {
            printf("Goodbye!\n");
            return 0;
        }
        if (room < 1 || room > MAX_ROOMS) {
            printf("Invalid room number!\n");
            continue;
        }
        while (1) {
            printf("\nEnter light number (1-%d) or 0 to go back: ", rooms[room-1].num_lights);
            fgets(buffer, 20, stdin);
            sscanf(buffer, "%d", &light);
            
            if (light == 0) {
                break;
            }
            if (light < 1 || light > rooms[room-1].num_lights) {
                printf("Invalid light number!\n");
                continue;
            }
            toggleLight(room, light);
        }
        // print all lights in the selected room
        printLights(room);
    }
    return 0;
}