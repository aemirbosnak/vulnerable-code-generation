//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define GHOST_ROOM 9

// Structure for each room
typedef struct {
    char name[20];
    int hasGhost;
    int hasTreasure;
} Room;

void initRooms(Room rooms[]) {
    for (int i = 0; i < ROOMS; i++) {
        rooms[i].hasGhost = 0;
        rooms[i].hasTreasure = 0;
    }
}

void placeGhost(Room rooms[]) {
    int ghostRoom = rand() % ROOMS;
    while (ghostRoom == 0 || ghostRoom == 1 || ghostRoom == 2) {
        ghostRoom = rand() % ROOMS;
    }
    rooms[ghostRoom].hasGhost = 1;
}

void placeTreasure(Room rooms[]) {
    int treasureRoom = rand() % ROOMS;
    while (treasureRoom == 0 || treasureRoom == 1 || treasureRoom == 2) {
        treasureRoom = rand() % ROOMS;
    }
    rooms[treasureRoom].hasTreasure = 1;
}

void printRoom(Room room) {
    printf("You are in the %s.\n", room.name);
    if (room.hasGhost) {
        printf("You see a ghost!\n");
    } else if (room.hasTreasure) {
        printf("You found a treasure!\n");
    }
}

int main() {
    srand(time(NULL));
    Room rooms[ROOMS];
    initRooms(rooms);
    placeGhost(rooms);
    placeTreasure(rooms);

    int playerRoom = 0;
    while (1) {
        printf("You are in room %d.\n", playerRoom);
        int choice;
        printf("Where do you want to go? ");
        scanf("%d", &choice);
        if (choice == 0) {
            printRoom(rooms[playerRoom]);
        } else if (choice == 1) {
            playerRoom--;
            if (playerRoom < 0) {
                playerRoom = ROOMS - 1;
            }
        } else if (choice == 2) {
            playerRoom++;
            if (playerRoom >= ROOMS) {
                playerRoom = 0;
            }
        }
    }
    return 0;
}