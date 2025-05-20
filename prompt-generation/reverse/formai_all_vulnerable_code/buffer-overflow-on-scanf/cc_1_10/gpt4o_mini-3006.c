//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ROOMS 10
#define MAX_DESC_LENGTH 256

typedef struct {
    char description[MAX_DESC_LENGTH];
    bool hasMonster;
    bool isVisited;
} Room;

void initializeRooms(Room rooms[]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        snprintf(rooms[i].description, MAX_DESC_LENGTH, "Room %d: A dark and creepy space.", i + 1);
        rooms[i].hasMonster = (rand() % 4) == 0; // 25% chance of having a monster
        rooms[i].isVisited = false;
    }
}

void displayRoom(const Room* room) {
    printf("%s\n", room->description);
    if (room->hasMonster) {
        printf("Oh no! There is a monster here!\n");
    }
}

bool enterRoom(Room* room) {
    if (room->isVisited) {
        printf("You've already been here.\n");
        return true; // Already visited, can still enter
    }
    room->isVisited = true;
    displayRoom(room);
    return room->hasMonster; // Return true if a monster is present
}

void displayMenu() {
    printf("1. Enter a room\n");
    printf("2. Exit the haunted house\n");
}

int main() {
    srand(time(NULL)); // Seed for random monster placement
    Room rooms[MAX_ROOMS];
    initializeRooms(rooms);

    int choice;
    int currentRoomIndex = 0;
    bool gameOver = false;

    printf("Welcome to the Haunted House Simulator!\n");

    while (!gameOver) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (currentRoomIndex >= MAX_ROOMS) {
                    printf("You've explored all rooms!\n");
                    break;
                }
                gameOver = enterRoom(&rooms[currentRoomIndex]);
                if (gameOver) {
                    printf("Oh no! You were caught by the monster!\n");
                } else {
                    printf("You safely explored Room %d.\n", currentRoomIndex + 1);
                }
                currentRoomIndex++;
                break;
            case 2:
                printf("Exiting the haunted house. Thanks for playing!\n");
                gameOver = true;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}