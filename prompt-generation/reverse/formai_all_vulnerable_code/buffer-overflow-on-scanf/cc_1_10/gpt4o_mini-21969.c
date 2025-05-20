//GPT-4o-mini DATASET v1.0 Category: Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_ROOMS 5
#define MAX_ITEMS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int strength;
} Character;

typedef struct {
    char description[100];
    int hasMonster;
    int treasure;
} Room;

void initializeCharacter(Character *player) {
    printf("Enter your character's name: ");
    fgets(player->name, MAX_NAME_LENGTH, stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove newline
    player->health = 100;
    player->strength = 10;
    printf("Welcome %s! Your journey begins...\n\n", player->name);
}

void initializeRooms(Room *rooms) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        sprintf(rooms[i].description, "Room %d: A dark, eerie chamber.", i + 1);
        rooms[i].hasMonster = rand() % 2;  // Randomly assign a monster
        rooms[i].treasure = (rand() % 10) + 1; // Random treasure value
    }
}

void displayRoom(Room room) {
    printf("%s\n", room.description);
    if (room.hasMonster) {
        printf("A monster lurks here!\n");
    } else {
        printf("It's quiet... maybe too quiet.\n");
    }
    if (room.treasure > 0) {
        printf("You see some treasure worth %d coins!\n", room.treasure);
    }
}

void encounterMonster(Character *player) {
    int monsterStrength = rand() % 15 + 1; // Random strength for monster
    printf("A monster appears! It has a strength of %d.\n", monsterStrength);
    while (player->health > 0 && monsterStrength > 0) {
        printf("You attack the monster!\n");
        monsterStrength -= player->strength;
        printf("Monster is now at %d strength!\n", monsterStrength);

        if (monsterStrength > 0) {
            player->health -= (rand() % 10 + 1); // Monster attacks back
            printf("The monster attacks you! You have %d health remaining.\n", player->health);
        }
    }
    if (player->health <= 0) {
        printf("You have been defeated by the monster. Game Over.\n");
        exit(0);
    } else {
        printf("You defeated the monster!\n");
    }
}

void collectTreasure(Character *player, int treasure) {
    printf("You collect %d coins!\n", treasure);
}

int main() {
    srand(time(NULL));

    Character player;
    Room rooms[MAX_ROOMS];
    initializeCharacter(&player);
    initializeRooms(rooms);

    int choice;
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("You enter %s\n", rooms[i].description);
        displayRoom(rooms[i]);

        if (rooms[i].hasMonster) {
            encounterMonster(&player);
        }

        if (rooms[i].treasure > 0) {
            collectTreasure(&player, rooms[i].treasure);
            rooms[i].treasure = 0; // Treasure can only be collected once
        }

        printf("\nDo you want to go to the next room? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        if (choice == 0) {
            printf("You decided to leave the dungeon. Final health: %d\n", player.health);
            break;
        }
    }

    printf("Thank you for playing, %s!\n", player.name);
    return 0;
}