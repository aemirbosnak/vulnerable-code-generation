//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int health;
    int mana;
} Player;

void startGame();
void showStatus(Player player);
void forest(Player *player);
void cave(Player *player);
void castle(Player *player);
void invalidChoice();

int main() {
    startGame();
    return 0;
}

void startGame() {
    Player player;
    player.health = 100;
    player.mana = 50;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("What is your name, brave adventurer? ");
    fgets(player.name, sizeof(player.name), stdin);
    player.name[strcspn(player.name, "\n")] = 0; // Remove newline character

    printf("Hello %s! You find yourself at a crossroads.\n", player.name);
    printf("You can go to the forest, cave, or castle.\n");

    while (player.health > 0) {
        printf("\nWhere do you want to go? (forest/cave/castle): ");
        
        char choice[MAX_LENGTH];
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = 0; // Remove newline character

        if (strcmp(choice, "forest") == 0) {
            forest(&player);
        } else if (strcmp(choice, "cave") == 0) {
            cave(&player);
        } else if (strcmp(choice, "castle") == 0) {
            castle(&player);
        } else {
            invalidChoice();
        }

        showStatus(player);

        if (player.health <= 0) {
            printf("You have died. Game Over. \n");
        }
    }
}

void showStatus(Player player) {
    printf("\n---- Status ----\n");
    printf("Health: %d\n", player.health);
    printf("Mana: %d\n", player.mana);
    printf("---------------\n");
}

void forest(Player *player) {
    printf("You enter the forest. The trees are dense, and you hear mysterious sounds.\n");
    printf("Suddenly, a wild boar attacks!\n");

    int damage = rand() % 30;
    player->health -= damage;

    printf("The boar deals %d damage to you!\n", damage);
}

void cave(Player *player) {
    printf("You walk into the cave. It's dark and damp, and you hear water dripping.\n");
    printf("You find a glowing crystal!\n");

    if (player->mana < 100) {
        player->mana += 20;
        printf("You absorb its magical energy! You gain 20 mana.\n");
    } else {
        printf("Your mana is full. You cannot absorb more energy.\n");
    }
}

void castle(Player *player) {
    printf("You approach a grand castle with tall towers.\n");
    printf("A guard stops you and demands to challenge you!\n");

    int action;
    printf("Choose your action: 1. Fight  2. Use Magic  3. Flee\n");
    scanf("%d", &action);

    switch (action) {
        case 1:
            printf("You choose to fight!\n");
            int fightDamage = rand() % 40;
            player->health -= fightDamage;
            printf("You take %d damage from the guard!\n", fightDamage);
            break;
        case 2:
            if (player->mana >= 10) {
                player->mana -= 10;
                printf("You cast a spell and dodge the guard's attack!\n");
            } else {
                printf("Not enough mana to cast a spell!\n");
                player->health -= rand() % 30; // You take some damage
            }
            break;
        case 3:
            printf("You chose to flee! You manage to get away safely.\n");
            break;
        default:
            printf("Invalid action. The guard attacks you while you hesitate.\n");
            player->health -= rand() % 20;
            break;
    }
}

void invalidChoice() {
    printf("That's not a valid choice. Please choose again.\n");
}