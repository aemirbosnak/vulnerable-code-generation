//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Player attributes
    int health = 100;
    int attack = 10;
    int defense = 5;
    int coins = 0;

    // Game state variables
    bool gameOver = false;
    int currentRoom = 1;

    // Game loop
    while (!gameOver) {
        printf("You are in room %d.\n", currentRoom);
        printf("What would you like to do?\n");
        printf("1. Look for treasure\n");
        printf("2. Fight monsters\n");
        printf("3. Move to a different room\n");
        printf("4. Quit game\n");

        int playerChoice;
        scanf("%d", &playerChoice);

        switch (playerChoice) {
            case 1:
                printf("You search for treasure...\n");
                int foundCoins = rand() % 20;
                printf("You found %d coins!\n", foundCoins);
                coins += foundCoins;
                break;

            case 2:
                printf("You encounter a monster!\n");
                int monsterHealth = 50;
                int monsterAttack = 15;
                int monsterDefense = 10;

                while (monsterHealth > 0) {
                    printf("You attack the monster...\n");
                    int damageDealt = attack - monsterDefense;
                    if (damageDealt < 0) {
                        damageDealt = 0;
                    }
                    printf("You deal %d damage to the monster!\n", damageDealt);
                    monsterHealth -= damageDealt;

                    if (monsterHealth <= 0) {
                        printf("You defeated the monster!\n");
                        int monsterCoins = rand() % 10;
                        printf("You found %d coins on the monster's body.\n", monsterCoins);
                        coins += monsterCoins;
                        break;
                    }

                    printf("The monster attacks you!\n");
                    int damageTaken = monsterAttack - defense;
                    if (damageTaken < 0) {
                        damageTaken = 0;
                    }
                    printf("You take %d damage from the monster!\n", damageTaken);
                    health -= damageTaken;

                    if (health <= 0) {
                        printf("Game over! You died.\n");
                        gameOver = true;
                        break;
                    }
                }

                break;

            case 3:
                printf("Which room do you want to move to? (1, 2, 3, 4)\n");
                int newRoom;
                scanf("%d", &newRoom);
                if (newRoom < 1 || newRoom > 4) {
                    printf("Invalid room number.\n");
                } else {
                    currentRoom = newRoom;
                }
                break;

            case 4:
                printf("Quitting game...\n");
                gameOver = true;
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Current stats:\n");
        printf("Health: %d\n", health);
        printf("Attack: %d\n", attack);
        printf("Defense: %d\n", defense);
        printf("Coins: %d\n", coins);
        printf("\n");
    }

    return 0;
}