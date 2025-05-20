//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_NAME 20

typedef struct {
    char name[MAX_NAME];
    char description[100];
    int treasure;
    int monster;
} Room;

void initializeRooms(Room rooms[]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        sprintf(rooms[i].name, "Room %d", i + 1);
        sprintf(rooms[i].description, "You have entered the mysterious %s. Watch out for monsters!", rooms[i].name);
        rooms[i].treasure = rand() % 20;  // Random treasure between 0 to 19
        rooms[i].monster = rand() % 2;    // Randomly decides if there's a monster
    }
}

void displayRoom(Room *room) {
    printf("\n%s\n", room->name);
    printf("%s\n", room->description);
    printf("Treasure found: %d coins\n", room->treasure);
    if (room->monster) {
        printf("Beware! A monster lurks in this room!\n");
    } else {
        printf("This room is safe.\n");
    }
}

void interactWithMonster() {
    int action;
    printf("Choose your action:\n");
    printf("1. Fight the monster\n");
    printf("2. Run away\n");
    printf("What will you do? ");
    scanf("%d", &action);

    if (action == 1) {
        printf("You bravely fought the monster and emerged victorious!\n");
    } else {
        printf("You ran away swiftly! Phew...\n");
    }
}

int main() {
    Room rooms[MAX_ROOMS];
    srand(time(0));  // Seed the random number generator
    initializeRooms(rooms);

    int currentRoomIndex = 0;
    char command[20];

    printf("Welcome to Dungeon Explorer!\n");
    printf("Your goal is to explore the dungeon and collect treasures!\n");

    while (1) {
        displayRoom(&rooms[currentRoomIndex]);

        if (rooms[currentRoomIndex].monster) {
            interactWithMonster();
        }

        printf("What would you like to do next? (explore, exit): ");
        scanf("%s", command);

        if (strcmp(command, "explore") == 0) {
            currentRoomIndex = (currentRoomIndex + 1) % MAX_ROOMS;  // Move to the next room
        } else if (strcmp(command, "exit") == 0) {
            printf("Thanks for playing! You collected treasures and faced dangers!\n");
            break;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }

    printf("Game Over. See you next time!\n");
    return 0;
}