//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define MONSTER_DAMAGE 20
#define TREASURE_FOUND 30
#define NUM_MONSTERS 3

typedef struct {
    char *name;
    int health;
} Player;

typedef struct {
    char *name;
    int damage;
} Monster;

void initializePlayer(Player *player) {
    player->name = "Hero";
    player->health = MAX_HEALTH;
}

void initializeMonsters(Monster monsters[]) {
    monsters[0].name = "Goblin";
    monsters[0].damage = MONSTER_DAMAGE;

    monsters[1].name = "Orc";
    monsters[1].damage = MONSTER_DAMAGE;

    monsters[2].name = "Dragon";
    monsters[2].damage = MONSTER_DAMAGE * 2; // Dragon is stronger
}

void printStatus(Player *player) {
    printf("\nPlayer: %s\nHealth: %d\n", player->name, player->health);
}

void encounterMonster(Player *player, Monster *monster) {
    printf("A wild %s appears!\n", monster->name);
    printf("It attacks you for %d damage!\n", monster->damage);
    player->health -= monster->damage;

    if (player->health > 0) {
        printf("You survived! Your health is now %d.\n", player->health);
    } else {
        printf("You have been defeated by the %s!\n", monster->name);
    }
}

void collectTreasure(Player *player) {
    printf("You found a treasure worth %d health!\n", TREASURE_FOUND);
    player->health += TREASURE_FOUND;
    if (player->health > MAX_HEALTH) {
        player->health = MAX_HEALTH; // Cap health
    }
    printf("Your health is now %d.\n", player->health);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Player player;
    initializePlayer(&player);

    Monster monsters[NUM_MONSTERS];
    initializeMonsters(monsters);

    int choice;
    while (player.health > 0) {
        printf("\n--- Dungeon Quest ---\n");
        printStatus(&player);
        printf("Choose an action:\n");
        printf("1. Explore the dungeon\n");
        printf("2. Collect treasure\n");
        printf("3. Check status\n");
        printf("4. Exit game\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int monster_index = rand() % NUM_MONSTERS;
                encounterMonster(&player, &monsters[monster_index]);
                break;
            }
            case 2: {
                collectTreasure(&player);
                break;
            }
            case 3: {
                printStatus(&player);
                break;
            }
            case 4: {
                printf("Exiting the game. Thanks for playing!\n");
                return 0;
            }
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    printf("Game over! You didn't make it out alive.\n");
    return 0;
}