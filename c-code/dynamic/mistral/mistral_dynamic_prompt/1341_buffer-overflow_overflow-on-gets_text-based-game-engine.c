#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Game constants
#define MAX_NAME_LENGTH 20
#define MAX_ROOM_DESC_LENGTH 80
#define MAX_NUM_ROOMS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_ROOM_DESC_LENGTH];
} Room;

Room rooms[MAX_NUM_ROOMS];
int currentRoom = 0;

void initRooms() {
    strcpy(rooms[0].name, "Lobby");
    strcpy(rooms[0].description, "Welcome to our text-based adventure game. You are currently in the Lobby.");

    strcpy(rooms[1].name, "Secret Chamber");
    strcpy(rooms[1].description, "A secret chamber filled with treasures. But beware, a dragon guards the treasure.");

    // ... add more rooms as needed
}

void printRoomDescription() {
    printf("%s\n", rooms[currentRoom].description);
}

void getRoomName() {
    char roomName[MAX_NAME_LENGTH];
    printf("Enter the name of the room you want to visit: ");
    gets(roomName); // Potential buffer overflow vulnerability here

    for (int i = 0; i < MAX_NUM_ROOMS; ++i) {
        if (strcmp(roomName, rooms[i].name) == 0) {
            currentRoom = i;
            break;
        }
    }

    printRoomDescription();
}

int main() {
    initRooms();
    getRoomName();

    return 0;
}
