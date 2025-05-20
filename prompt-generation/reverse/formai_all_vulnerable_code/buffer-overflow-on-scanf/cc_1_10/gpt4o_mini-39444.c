//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_ITEMS 3

typedef struct {
    char *description;
    char *item;
    int hasGhost; // 1 if there's a ghost in the room, 0 otherwise
} Room;

Room rooms[MAX_ROOMS];

void initializeRooms() {
    rooms[0] = (Room){"You are in a dark foyer. An eerie wind chills you to the bone.", "Old Key", 1};
    rooms[1] = (Room){"You step into the library. Shadows flicker across the walls.", "Mysterious Book", 0};
    rooms[2] = (Room){"You enter the kitchen. A rotten smell fills the air.", "Rusty Knife", 1};
    rooms[3] = (Room){"You find yourself in a dusty old bedroom. Ghostly whispers echo.", "Faded Photo", 1};
    rooms[4] = (Room){"You walk into a dimly lit cellar. You hear soft laughter.", NULL, 0};
}

void displayRoom(int currentRoom) {
    printf("%s\n", rooms[currentRoom].description);
    if (rooms[currentRoom].item != NULL) {
        printf("You see a %s here.\n", rooms[currentRoom].item);
    }
    if (rooms[currentRoom].hasGhost) {
        printf("A ghost appears! It looks angry...\n");
    }
}

int main() {
    int currentRoom = 0;
    int itemsCollected[MAX_ITEMS] = {0, 0, 0}; // 0: Old Key, 1: Mysterious Book, 2: Rusty Knife
    char command[20];
    int itemChoice;

    initializeRooms();

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Type 'exit' to leave the haunted house at any time.\n");

    while (1) {
        displayRoom(currentRoom);
        
        printf("What do you want to do? (explore/take/quit): ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("You have exited the haunted house. Goodbye!\n");
            break;
        }
        
        if (strcmp(command, "explore") == 0) {
            // Randomly move to another room
            currentRoom = rand() % MAX_ROOMS;
        } else if (strcmp(command, "take") == 0) {
            if (rooms[currentRoom].item != NULL) {
                if (currentRoom == 0 && !itemsCollected[0]) {
                    printf("You took the Old Key!\n");
                    itemsCollected[0] = 1;
                } else if (currentRoom == 1 && !itemsCollected[1]) {
                    printf("You took the Mysterious Book!\n");
                    itemsCollected[1] = 1;
                } else if (currentRoom == 2 && !itemsCollected[2]) {
                    printf("You took the Rusty Knife!\n");
                    itemsCollected[2] = 1;
                } else {
                    printf("You've already taken this item or nothing is here!\n");
                }
            } else {
                printf("There's nothing to take here.\n");
            }
        } else {
            printf("Invalid command. Try again.\n");
        }

        // Check for ghost encounter
        if (rooms[currentRoom].hasGhost) {
            printf("You've encountered a ghost!\n");
            if (itemsCollected[0]) {
                printf("You use the Old Key to escape the ghost!\n");
                rooms[currentRoom].hasGhost = 0; // Encounter resolved
            } else {
                printf("You have no way to defend yourself against the ghost! Game over.\n");
                break;
            }
        }
    }

    return 0;
}