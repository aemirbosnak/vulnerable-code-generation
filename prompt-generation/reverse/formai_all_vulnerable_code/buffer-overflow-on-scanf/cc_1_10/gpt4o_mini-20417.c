//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_TREASURES 5

typedef struct {
    int id;
    char description[100];
    int hasTreasure;
    int hasMonster;
} Room;

typedef struct {
    int id;
    char name[20];
    int value;
} Treasure;

Room dungeon[MAX_ROOMS];
Treasure treasures[MAX_TREASURES];
int currentRoom;
int treasuresCollected = 0;
int gameOver = 0;

void initializeDungeon() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        dungeon[i].id = i;
        sprintf(dungeon[i].description, "Room %d: A dimly lit chamber.", i);
        dungeon[i].hasTreasure = rand() % 2; // Randomly assign treasures
        dungeon[i].hasMonster = rand() % 2; // Randomly assign monsters
    }
}

void initializeTreasures() {
    for (int i = 0; i < MAX_TREASURES; i++) {
        treasures[i].id = i;
        sprintf(treasures[i].name, "Treasure %d", i + 1);
        treasures[i].value = (i + 1) * 10; // Value increases with ID
    }
}

void displayRoom() {
    printf("\nYou are in %s\n", dungeon[currentRoom].description);
    if (dungeon[currentRoom].hasTreasure) {
        printf("You see a treasure here!\n");
    }
    if (dungeon[currentRoom].hasMonster) {
        printf("There is a monster lurking here!\n");
    }
}

void collectTreasure() {
    if (dungeon[currentRoom].hasTreasure) {
        printf("You have collected %s!\n", treasures[treasuresCollected].name);
        treasuresCollected++;
        dungeon[currentRoom].hasTreasure = 0; // Treasure collected
    } else {
        printf("There is no treasure here!\n");
    }
}

void encounterMonster() {
    if (dungeon[currentRoom].hasMonster) {
        printf("You have encountered a monster! Game over!\n");
        gameOver = 1; // Set game over condition
    }
}

void changeRoom() {
    currentRoom = rand() % MAX_ROOMS; // Move to a random room
    printf("You move to another room...\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    initializeDungeon();
    initializeTreasures();
    
    currentRoom = 0; // Start in the first room

    printf("Welcome to the Dungeon Escape!\n");
    
    while (!gameOver) {
        displayRoom();
        
        char choice[10];
        printf("What would you like to do? (collect, move, exit): ");
        scanf("%s", choice);
        
        if (strcmp(choice, "collect") == 0) {
            collectTreasure();
        } else if (strcmp(choice, "move") == 0) {
            encounterMonster();
            if (!gameOver)
                changeRoom();
        } else if (strcmp(choice, "exit") == 0) {
            printf("You have chosen to exit the dungeon!\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
        
        if (treasuresCollected >= MAX_TREASURES) {
            printf("Congratulations! You have collected all treasures!\n");
            break;
        }
    }

    if (gameOver) {
        printf("You have perished in the dungeon...\n");
    } else {
        printf("Thank you for playing!\n");
    }

    return 0;
}