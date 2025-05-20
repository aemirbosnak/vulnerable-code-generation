//GPT-4o-mini DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 50
#define MAX_ITEMS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int x;
    int y;
    char *description;
} Room;

typedef struct {
    char name[MAX_NAME_LENGTH];
} Item;

Room rooms[MAX_ROOMS];
Item items[MAX_ITEMS] = {{"Poison"}, {"Love Letter"}, {"Dagger"}, {"Secret Message"}, {"Ring"}};

void generateRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        sprintf(rooms[i].name, "Room %d", i + 1);
        rooms[i].x = rand() % 10;
        rooms[i].y = rand() % 10;
        rooms[i].description = (i % 2 == 0) ? "A dimly lit room with an air of mystery." : "A bright room filled with flickering shadows.";
    }
}

void printRoom(Room *room) {
    printf("You enter %s at (%d, %d).\n", room->name, room->x, room->y);
    printf("%s\n", room->description);
}

void searchForItem() {
    int foundItemIndex = rand() % MAX_ITEMS;
    printf("You found a %s!\n", items[foundItemIndex].name);
}

void duel() {
    printf("A masked rival appears! A duel ensues...\n");
    int outcome = rand() % 2;
    if (outcome == 0) {
        printf("You bravely defeat your rival!\n");
    } else {
        printf("You are struck down, love will persevere in the afterlife!\n");
    }
}

void romeoAndJulietAdventure() {
    int currentRoom = 0;
    char command[20];

    printf("Welcome to the tragic love story of Romeo and Juliet!\n");

    while (1) {
        printRoom(&rooms[currentRoom]);
        printf("What will you do? (search/duel/exit): ");
        scanf("%s", command);

        if (strcmp(command, "search") == 0) {
            searchForItem();
        } else if (strcmp(command, "duel") == 0) {
            duel();
        } else if (strcmp(command, "exit") == 0) {
            printf("You have chosen to leave the story of love and tragedy.\n");
            break;
        } else {
            printf("Command not recognized. Choose wisely, you might meet fate!\n");
        }

        currentRoom = (currentRoom + 1) % MAX_ROOMS;  // Move to the next room
    }
}

int main() {
    srand(time(NULL));
    generateRooms();
    romeoAndJulietAdventure();
    return 0;
}