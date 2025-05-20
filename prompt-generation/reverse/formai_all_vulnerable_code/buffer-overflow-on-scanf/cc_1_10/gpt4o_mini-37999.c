//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_ENEMIES 3
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int attack;
} Character;

typedef struct {
    char description[100];
    Character enemy;
    int hasTreasure;
} Room;

Room dungeon[MAX_ROOMS];
int currentRoom;
Character player;

void setupDungeon() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        snprintf(dungeon[i].description, sizeof(dungeon[i].description), "You are in room %d. The atmosphere is eerie.", i + 1);
        dungeon[i].hasTreasure = rand() % 2; // Randomly place treasure
        if (rand() % 2) {
            snprintf(dungeon[i].enemy.name, sizeof(dungeon[i].enemy.name), "Goblin %d", i + 1);
            dungeon[i].enemy.health = 20 + rand() % 30;
            dungeon[i].enemy.attack = 5 + rand() % 5;
        } else {
            dungeon[i].enemy.health = 0; // No enemy here
        }
    }
}

void showStatus() {
    printf("\n%s\nHealth: %d\n", player.name, player.health);
}

void displayRoom() {
    printf("\n%s\n", dungeon[currentRoom].description);
    if (dungeon[currentRoom].hasTreasure) {
        printf("You found treasure in this room!\n");
    }
    if (dungeon[currentRoom].enemy.health > 0) {
        printf("A wild %s appears with %d health!\n", dungeon[currentRoom].enemy.name, dungeon[currentRoom].enemy.health);
    }
}

void battle(Character *enemy) {
    while (player.health > 0 && enemy->health > 0) {
        enemy->health -= player.attack;
        printf("You attacked %s. It now has %d health.\n", enemy->name, enemy->health);
        if (enemy->health <= 0) {
            printf("You defeated %s!\n", enemy->name);
            return;
        }
        player.health -= enemy->attack;
        printf("%s attacked you. You now have %d health.\n", enemy->name, player.health);
    }
    if (player.health <= 0) {
        printf("You have been defeated!\n");
        exit(0);
    }
}

void enterRoom() {
    displayRoom();
    if (dungeon[currentRoom].enemy.health > 0) {
        char choice;
        printf("Do you want to fight (f) or flee (l)? ");
        scanf(" %c", &choice);
        if (choice == 'f') {
            battle(&dungeon[currentRoom].enemy);
        } else {
            printf("You flee the room!\n");
            return;
        }
    }
    if (dungeon[currentRoom].hasTreasure) {
        printf("You collect the treasure!\n");
        dungeon[currentRoom].hasTreasure = 0; // Remove treasure after collecting
    }
    printf("What would you like to do next? (n: next room, p: previous room, q: quit)\n");
}

void enterNextRoom() {
    if (currentRoom < MAX_ROOMS - 1) {
        currentRoom++;
    } else {
        printf("You are at the last room of the dungeon.\n");
    }
    enterRoom();
}

void enterPreviousRoom() {
    if (currentRoom > 0) {
        currentRoom--;
    } else {
        printf("You are at the first room of the dungeon.\n");
    }
    enterRoom();
}

int main() {
    srand(time(0));

    printf("Welcome to Mystery Dungeon!\n");
    printf("Enter your character name: ");
    scanf("%s", player.name);
    player.health = 100;
    player.attack = 10;

    setupDungeon();
    currentRoom = 0;

    showStatus();
    enterRoom();

    char command;
    while (1) {
        scanf(" %c", &command);
        switch (command) {
            case 'n':
                enterNextRoom();
                break;
            case 'p':
                enterPreviousRoom();
                break;
            case 'q':
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid command. Use n (next), p (previous), or q (quit).\n");
                break;
        }
        showStatus();
    }
    return 0;
}