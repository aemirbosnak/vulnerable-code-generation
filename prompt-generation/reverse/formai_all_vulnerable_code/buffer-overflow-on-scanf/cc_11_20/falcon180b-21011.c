//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_LIGHTS_PER_ROOM 5

// Structure for a room
typedef struct {
    char name[20];
    int numLights;
    int lightStatus[MAX_LIGHTS_PER_ROOM];
} Room;

int main() {
    // Initialize rooms
    Room rooms[MAX_ROOMS];
    int numRooms = 0;

    // Add a room
    char roomName[20];
    printf("Enter room name: ");
    scanf("%s", roomName);
    strcpy(rooms[numRooms].name, roomName);
    rooms[numRooms].numLights = 0;
    numRooms++;

    // Add lights to the room
    int roomIndex;
    printf("Enter room index: ");
    scanf("%d", &roomIndex);
    if (roomIndex >= 0 && roomIndex < numRooms) {
        int lightIndex;
        printf("Enter light index: ");
        scanf("%d", &lightIndex);
        if (lightIndex >= 0 && lightIndex < MAX_LIGHTS_PER_ROOM) {
            rooms[roomIndex].numLights++;
            rooms[roomIndex].lightStatus[lightIndex] = 0;
        } else {
            printf("Invalid light index.\n");
        }
    } else {
        printf("Invalid room index.\n");
    }

    // Turn lights on/off
    int roomIndex2;
    printf("Enter room index: ");
    scanf("%d", &roomIndex2);
    if (roomIndex2 >= 0 && roomIndex2 < numRooms) {
        int lightIndex2;
        printf("Enter light index: ");
        scanf("%d", &lightIndex2);
        if (lightIndex2 >= 0 && lightIndex2 < rooms[roomIndex2].numLights) {
            int status;
            printf("Enter status (0=off, 1=on): ");
            scanf("%d", &status);
            rooms[roomIndex2].lightStatus[lightIndex2] = status;
        } else {
            printf("Invalid light index.\n");
        }
    } else {
        printf("Invalid room index.\n");
    }

    // Print room status
    printf("Room status:\n");
    for (int i = 0; i < numRooms; i++) {
        printf("Room %s:\n", rooms[i].name);
        for (int j = 0; j < rooms[i].numLights; j++) {
            printf("Light %d: %s\n", j+1, rooms[i].lightStatus[j]? "on" : "off");
        }
    }

    return 0;
}