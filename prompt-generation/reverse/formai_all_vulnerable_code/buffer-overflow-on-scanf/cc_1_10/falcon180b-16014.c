//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define GHOSTS 3
#define TREASURES 5
#define MAX_ROOM_SIZE 50

typedef struct {
    char name[MAX_ROOM_SIZE];
    int hasTreasure;
    int hasGhost;
} Room;

typedef struct {
    char name[MAX_ROOM_SIZE];
    int isAlive;
} Ghost;

Room rooms[ROOMS];
Ghost ghosts[GHOSTS];

void generateRooms() {
    for (int i = 0; i < ROOMS; i++) {
        sprintf(rooms[i].name, "Room %d", i + 1);
        rooms[i].hasTreasure = rand() % 2;
        rooms[i].hasGhost = rand() % 2;
    }
}

void generateGhosts() {
    for (int i = 0; i < GHOSTS; i++) {
        sprintf(ghosts[i].name, "Ghost %d", i + 1);
        ghosts[i].isAlive = 1;
    }
}

void printRoom(Room room) {
    printf("You are in %s.\n", room.name);
    if (room.hasTreasure) {
        printf("You found a treasure!\n");
    } else if (room.hasGhost) {
        printf("You encountered a ghost!\n");
        for (int i = 0; i < GHOSTS; i++) {
            if (ghosts[i].isAlive && strcmp(ghosts[i].name, "Ghost 1") == 0) {
                printf("It's Ghost 1!\n");
                ghosts[i].isAlive = 0;
                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    generateRooms();
    generateGhosts();

    int roomIndex = 0;
    while (1) {
        printf("Which room do you want to go to? ");
        scanf("%d", &roomIndex);
        if (roomIndex < 1 || roomIndex > ROOMS) {
            printf("Invalid room number.\n");
        } else {
            printRoom(rooms[roomIndex - 1]);
        }
    }

    return 0;
}