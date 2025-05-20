//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_GHOSTS 3
#define MAX_TREASURES 5

typedef struct {
    char *description;
    int hasTreasure;
    int hasGhost;
} Room;

typedef struct {
    Room rooms[MAX_ROOMS];
    int currentRoom;
    int treasuresCollected;
} HauntedHouse;

void initializeHouse(HauntedHouse *house) {
    house->currentRoom = 0;
    house->treasuresCollected = 0;
    
    house->rooms[0].description = "You are in the spooky entrance. Shadows dance on the walls.";
    house->rooms[0].hasTreasure = rand() % 2;
    house->rooms[0].hasGhost = rand() % 2;

    house->rooms[1].description = "You are in the dusty library. Old books are scattered everywhere.";
    house->rooms[1].hasTreasure = rand() % 2;
    house->rooms[1].hasGhost = rand() % 2;

    house->rooms[2].description = "You are in the eerie dining hall. A chilling breeze flows through.";
    house->rooms[2].hasTreasure = rand() % 2;
    house->rooms[2].hasGhost = rand() % 2;

    house->rooms[3].description = "You are in the dark basement. Strange noises echo around.";
    house->rooms[3].hasTreasure = rand() % 2;
    house->rooms[3].hasGhost = rand() % 2;

    house->rooms[4].description = "You are in an abandoned attic. Cobwebs blanket everything.";
    house->rooms[4].hasTreasure = rand() % 2;
    house->rooms[4].hasGhost = rand() % 2;
}

void displayCurrentRoom(HauntedHouse *house) {
    printf("%s\n", house->rooms[house->currentRoom].description);
    if (house->rooms[house->currentRoom].hasTreasure) {
        printf("You found a treasure!\n");
    }
    if (house->rooms[house->currentRoom].hasGhost) {
        printf("A ghost appears! You are scared!\n");
    }
}

void moveToRoom(HauntedHouse *house, int roomNumber) {
    if (roomNumber >= 0 && roomNumber < MAX_ROOMS) {
        house->currentRoom = roomNumber;
        displayCurrentRoom(house);
        if (house->rooms[house->currentRoom].hasTreasure) {
            house->treasuresCollected++;
            house->rooms[house->currentRoom].hasTreasure = 0;  // Treasure collected
        }
    } else {
        printf("Invalid room choice!\n");
    }
}

void displayMenu() {
    printf("Choose your action:\n");
    printf("0 - Move to Room 1\n");
    printf("1 - Move to Room 2\n");
    printf("2 - Move to Room 3\n");
    printf("3 - Move to Room 4\n");
    printf("4 - Move to Room 5\n");
    printf("5 - Collect treasures and flee\n");
    printf("Enter your choice: ");
}

int main() {
    srand(time(NULL));
    HauntedHouse house;
    initializeHouse(&house);
    displayCurrentRoom(&house);

    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        
        if (choice >= 0 && choice < 5) {
            moveToRoom(&house, choice);
        } else if (choice == 5) {
            printf("You collected %d treasures. You successfully fled the haunted house!\n", house.treasuresCollected);
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}