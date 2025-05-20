//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int health;
} Player;

typedef struct {
    char* name;
    int damage;
    int health;
} Enemy;

void printIntro() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark and shadowy room.\n");
    printf("You have no idea how you got here, but you know you must find your way out.\n\n");
}

int getPlayerChoice() {
    int choice;
    printf("Choose your path:\n");
    printf("1. Go left\n");
    printf("2. Go right\n");
    printf("3. Go straight\n");
    scanf("%d", &choice);
    return choice;
}

void battle(Player* player, Enemy* enemy) {
    while (enemy->health > 0 && player->health > 0) {
        printf("Your health: %d\n", player->health);
        printf("%s's health: %d\n\n", enemy->name, enemy->health);

        int attackChoice;
        printf("Choose your attack:\n");
        printf("1. Quick attack\n");
        printf("2. Strong attack\n");
        scanf("%d", &attackChoice);

        int playerDamage;
        if (attackChoice == 1) {
            playerDamage = rand() % 10 + 1;
        } else {
            playerDamage = rand() % 20 + 1;
        }

        enemy->health -= playerDamage;
        printf("You attack %s for %d damage\n\n", enemy->name, playerDamage);

        if (enemy->health > 0) {
            int enemyDamage = rand() % enemy->damage + 1;
            player->health -= enemyDamage;
            printf("%s attacks you for %d damage\n\n", enemy->name, enemyDamage);
        }
    }

    if (player->health > 0) {
        printf("%s defeated %s!\n\n", player->name, enemy->name);
    } else {
        printf("%s was defeated by %s :(\n\n", player->name, enemy->name);
    }
}

int main() {
    srand(time(NULL));

    // set up player
    Player player;
    player.name = "Hero";
    player.health = 50;

    // print intro
    printIntro();

    // first choice
    int choice = getPlayerChoice();
    if (choice == 1) {
        printf("You find a sword! You feel stronger already.\n\n");
        player.health += 20;
    } else if (choice == 2) {
        printf("You find a potion! You feel invigorated.\n\n");
        player.health += 30;
    } else {
        printf("You walk past a creepy statue and feel a chill run down your spine.\n\n");
    }

    // set up enemy
    Enemy enemy;
    enemy.name = "Shadow";
    enemy.health = 40;
    enemy.damage = 10;

    // battle time!
    printf("You encounter a %s!\n\n", enemy.name);
    battle(&player, &enemy);

    // print results
    if (player.health > 0) {
        printf("You made it out alive! Congratulations, %s!\n", player.name);
    } else {
        printf("You have been defeated :(\n");
    }

    return 0;
}