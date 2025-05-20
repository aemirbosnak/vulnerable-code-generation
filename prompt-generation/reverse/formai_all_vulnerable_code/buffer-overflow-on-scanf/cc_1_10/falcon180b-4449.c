//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the structure of a haunted house room
typedef struct {
    char name[50];
    char description[200];
    int hasGhost;
    int hasTreasure;
} Room;

// Define the haunted house
Room hauntedHouse[MAX_ROOMS];

// Function to generate a random haunted house
void generateHauntedHouse() {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        hauntedHouse[i].hasGhost = rand() % 2;
        hauntedHouse[i].hasTreasure = rand() % 2;
        sprintf(hauntedHouse[i].name, "Room %d", i + 1);
        sprintf(hauntedHouse[i].description, "You are in room %s. It is %s and %s.", hauntedHouse[i].name, hauntedHouse[i].hasGhost? "haunted" : "not haunted", hauntedHouse[i].hasTreasure? "contains treasure" : "does not contain treasure");
    }
}

// Function to display a room
void displayRoom(int roomNumber) {
    printf("\n%s\n%s", hauntedHouse[roomNumber].name, hauntedHouse[roomNumber].description);
}

// Function to move between rooms
void move(int fromRoom, int toRoom) {
    printf("\nYou move from room %s to room %s.\n", hauntedHouse[fromRoom].name, hauntedHouse[toRoom].name);
    if (hauntedHouse[toRoom].hasGhost) {
        printf("A ghost appears and scares you!\n");
    } else if (hauntedHouse[toRoom].hasTreasure) {
        printf("You find a treasure chest and open it.\n");
        int treasureAmount = rand() % 100;
        printf("Inside the chest, you find %d gold coins!\n", treasureAmount);
    } else {
        printf("Nothing interesting happens.\n");
    }
}

int main() {
    srand(time(NULL));
    generateHauntedHouse();

    // Main game loop
    int currentRoom = 0;
    while (1) {
        printf("\nYou are in room %s.\n", hauntedHouse[currentRoom].name);
        printf("What do you want to do? ");
        char choice;
        scanf("%c", &choice);

        switch (choice) {
        case'm':
            // Move to another room
            printf("Which room do you want to move to? ");
            int destinationRoom;
            scanf("%d", &destinationRoom);
            move(currentRoom, destinationRoom);
            currentRoom = destinationRoom;
            break;

        case 'q':
            // Quit the game
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}