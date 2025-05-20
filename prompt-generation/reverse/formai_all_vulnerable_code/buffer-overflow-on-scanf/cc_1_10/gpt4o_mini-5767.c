//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 5
#define MAX_ROOMS 10

typedef struct {
    char name[20];
    int treasures;
    int health;
} Player;

typedef struct {
    char description[100];
    int treasures;
    int hasMonster;
} Room;

Room dungeon[MAX_ROOMS];
Player player;

void initializeGame() {
    strcpy(player.name, "Hero");
    player.treasures = 0;
    player.health = 100;

    for (int i = 0; i < MAX_ROOMS; i++) {
        sprintf(dungeon[i].description, "You are in room %d. It looks mysterious.", i+1);
        dungeon[i].treasures = rand() % 20; // Random treasures between 0-19
        dungeon[i].hasMonster = rand() % 2; // Randomly have a monster or not
    }
}

void displayStatus() {
    printf("Player: %s\n", player.name);
    printf("Treasures: %d\n", player.treasures);
    printf("Health: %d\n", player.health);
}

void exploreRoom(int roomIndex) {
    printf("%s\n", dungeon[roomIndex].description);

    if (dungeon[roomIndex].treasures > 0) {
        printf("You found %d treasures!\n", dungeon[roomIndex].treasures);
        player.treasures += dungeon[roomIndex].treasures;
        dungeon[roomIndex].treasures = 0; // Treasures collected
    } else {
        printf("No treasures in this room.\n");
    }

    if (dungeon[roomIndex].hasMonster) {
        printf("A monster appears!\n");
        int damage = rand() % 30 + 1; // Damage between 1-30
        printf("You took %d damage!\n", damage);
        player.health -= damage;

        if (player.health <= 0) {
            printf("You have been defeated!\n");
            exit(0);
        } else {
            printf("You managed to escape. Current health: %d\n", player.health);
        }
    }
}

void printInstructions() {
    printf("Commands: \n");
    printf("  'explore' - Explore the current room.\n");
    printf("  'status'  - View player status.\n");
    printf("  'exit'    - Exit the game.\n");
}

int main() {
    srand(time(NULL));
    char command[20];
    int currentRoom = 0;

    initializeGame();
    printInstructions();

    while (1) {
        printf("\nWhat do you want to do? ");
        scanf("%s", command);

        if (strcmp(command, "explore") == 0) {
            exploreRoom(currentRoom);
        } else if (strcmp(command, "status") == 0) {
            displayStatus();
        } else if (strcmp(command, "exit") == 0) {
            printf("Thanks for playing!\n");
            break;
        } else {
            printf("Unknown command. Try again.\n");
        }
    }

    return 0;
}