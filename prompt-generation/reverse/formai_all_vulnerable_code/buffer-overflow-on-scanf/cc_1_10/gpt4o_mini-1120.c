//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int hasItem;
} Room;

void initializeRooms(Room rooms[], int size) {
    for (int i = 0; i < size; i++) {
        rooms[i].hasItem = 0; // No item at the start
    }

    // Define rooms
    snprintf(rooms[0].name, MAX_NAME_LENGTH, "The Entrance");
    snprintf(rooms[0].description, MAX_DESCRIPTION_LENGTH, "You stand in front of a creaky old door...");

    snprintf(rooms[1].name, MAX_NAME_LENGTH, "The Living Room");
    snprintf(rooms[1].description, MAX_DESCRIPTION_LENGTH, "The room is dimly lit, with cobwebs in the corners...");
    rooms[1].hasItem = 1; // An item is present

    snprintf(rooms[2].name, MAX_NAME_LENGTH, "The Kitchen");
    snprintf(rooms[2].description, MAX_DESCRIPTION_LENGTH, "The smell of rotten food fills the air...");
    
    snprintf(rooms[3].name, MAX_NAME_LENGTH, "The Bedroom");
    snprintf(rooms[3].description, MAX_DESCRIPTION_LENGTH, "A bed is covered in dust, and a shadow flits past...");

    snprintf(rooms[4].name, MAX_NAME_LENGTH, "The Basement");
    snprintf(rooms[4].description, MAX_DESCRIPTION_LENGTH, "You hear whispers coming from below...");
}

void printRoom(Room room) {
    printf("You are in: %s\n", room.name);
    printf("%s\n", room.description);
}

int main() {
    Room rooms[5];
    int currentRoom = 0; // Start in the Entrance
    char input[10];
    int totalRooms = sizeof(rooms) / sizeof(rooms[0]);
    int hasFoundItem = 0;

    srand(time(NULL)); // Seed random number generator

    initializeRooms(rooms, totalRooms);

    while (1) {
        printRoom(rooms[currentRoom]);

        if (rooms[currentRoom].hasItem && !hasFoundItem) {
            printf("You find a spooky artifact!\n");
            hasFoundItem = 1; // Mark item as found
        }

        printf("What would you like to do? (go [room], exit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            printf("You have decided to leave the haunted house. Good riddance!\n");
            break;
        } else if (strcmp(input, "go") == 0) {
            char roomName[20];
            scanf("%s", roomName);

            if (strcmp(roomName, "Entrance") == 0) {
                currentRoom = 0;
            } else if (strcmp(roomName, "Living") == 0) {
                currentRoom = 1;
            } else if (strcmp(roomName, "Kitchen") == 0) {
                currentRoom = 2;
            } else if (strcmp(roomName, "Bedroom") == 0) {
                currentRoom = 3;
            } else if (strcmp(roomName, "Basement") == 0) {
                currentRoom = 4;
            } else {
                printf("That's not a valid room!\n");
                continue;
            }
        } else {
            printf("Invalid command! Try again.\n");
        }

        // Random spooky encounter
        if (rand() % 5 == 0) {
            printf("A ghost appears and scares you! You lose your mind!\n");
            break;
        }
    }

    printf("Game over! You survived the haunted house with %s.\n", hasFoundItem ? "the artifact" : "empty hands");
    return 0;
}