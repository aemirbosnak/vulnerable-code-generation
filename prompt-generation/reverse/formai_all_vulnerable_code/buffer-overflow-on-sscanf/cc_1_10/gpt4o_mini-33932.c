//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_LIGHTS 5
#define MAX_NAME_LENGTH 30

typedef enum {
    OFF,
    ON
} LightState;

typedef struct {
    char name[MAX_NAME_LENGTH];
    LightState state;
} Light;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Light lights[MAX_LIGHTS];
    int light_count;
} Room;

typedef struct {
    Room rooms[MAX_ROOMS];
    int room_count;
} SmartHome;

void initializeSmartHome(SmartHome *home) {
    home->room_count = 0;
}

void addRoom(SmartHome *home, const char *roomName) {
    if (home->room_count >= MAX_ROOMS) {
        printf("Maximum room limit reached\n");
        return;
    }
    strcpy(home->rooms[home->room_count].name, roomName);
    home->rooms[home->room_count].light_count = 0;
    home->room_count++;
}

void addLightToRoom(SmartHome *home, const char *roomName, const char *lightName) {
    for (int i = 0; i < home->room_count; i++) {
        if (strcmp(home->rooms[i].name, roomName) == 0) {
            if (home->rooms[i].light_count >= MAX_LIGHTS) {
                printf("Maximum light limit in room '%s' reached\n", roomName);
                return;
            }
            Light *newLight = &home->rooms[i].lights[home->rooms[i].light_count];
            strcpy(newLight->name, lightName);
            newLight->state = OFF;
            home->rooms[i].light_count++;
            return;
        }
    }
    printf("Room '%s' not found\n", roomName);
}

void toggleLight(SmartHome *home, const char *roomName, const char *lightName) {
    for (int i = 0; i < home->room_count; i++) {
        if (strcmp(home->rooms[i].name, roomName) == 0) {
            for (int j = 0; j < home->rooms[i].light_count; j++) {
                if (strcmp(home->rooms[i].lights[j].name, lightName) == 0) {
                    home->rooms[i].lights[j].state = 
                        (home->rooms[i].lights[j].state == OFF) ? ON : OFF;
                    printf("Light '%s' in room '%s' is now %s\n", 
                           lightName, roomName, 
                           home->rooms[i].lights[j].state == ON ? "ON" : "OFF");
                    return;
                }
            }
            printf("Light '%s' not found in room '%s'\n", lightName, roomName);
            return;
        }
    }
    printf("Room '%s' not found\n", roomName);
}

void showLights(SmartHome *home, const char *roomName) {
    for (int i = 0; i < home->room_count; i++) {
        if (strcmp(home->rooms[i].name, roomName) == 0) {
            printf("Lights in room '%s':\n", roomName);
            for (int j = 0; j < home->rooms[i].light_count; j++) {
                printf("  - %s: %s\n", home->rooms[i].lights[j].name,
                       home->rooms[i].lights[j].state == ON ? "ON" : "OFF");
            }
            return;
        }
    }
    printf("Room '%s' not found\n", roomName);
}

void commandLineInterface(SmartHome *home) {
    char command[100];
    char room[MAX_NAME_LENGTH];
    char light[MAX_NAME_LENGTH];

    while (1) {
        printf("Enter command (or 'exit' to quit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        if (strcmp(command, "exit") == 0) {
            break;
        }

        sscanf(command, "%s %s %s", command, room, light);

        if (strcmp(command, "add_room") == 0) {
            addRoom(home, room);
        } else if (strcmp(command, "add_light") == 0) {
            addLightToRoom(home, room, light);
        } else if (strcmp(command, "toggle") == 0) {
            toggleLight(home, room, light);
        } else if (strcmp(command, "show") == 0) {
            showLights(home, room);
        } else {
            printf("Unknown command\n");
        }
    }
}

int main() {
    SmartHome myHome;
    initializeSmartHome(&myHome);
    commandLineInterface(&myHome);
    return 0;
}