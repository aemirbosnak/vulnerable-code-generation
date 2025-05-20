//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void printMessage(int health, int gold) {
    printf("Health: %d\n", health);
    printf("Gold:   %d\n", gold);
}

int main(void) {
    srand(time(NULL));
    int health = 100;
    int gold = 0;
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You wake up in a medieval-themed spaceship.\n");
    printf("Your mission is to find the treasure on the planet Nebula.\n");
    while (health > 0) {
        printMessage(health, gold);
        printf("Select an action:\n");
        printf("1. Land on Nebula\n");
        printf("2. Attack the spaceship of enemy aliens\n");
        printf("3. Trade gold for health\n");
        int selection;
        scanf("%d", &selection);
        switch (selection) {
            case 1:
                printf("You land on Nebula and begin your search for the treasure.\n");
                int treasureFound = getRandom(0, 1);
                if (treasureFound) {
                    printf("Congratulations! You found the treasure and win the game!\n");
                    return 0;
                } else {
                    printf("Uh oh! The treasure is not here. You lose 20 health points.\n");
                    health -= 20;
                }
                break;
            case 2:
                printf("You encounter enemy aliens and engage in battle!\n");
                int enemyHealth = getRandom(50, 100);
                while (enemyHealth > 0 && health > 0) {
                    int damage = getRandom(10, 30);
                    printf("You deal %d damage to the enemy aliens.\n", damage);
                    enemyHealth -= damage;
                    if (enemyHealth <= 0) {
                        printf("You defeated the aliens and gain 10 gold!\n");
                        gold += 10;
                        break;
                    }
                    damage = getRandom(20, 40);
                    printf("The aliens attack and deal %d damage to you.\n", damage);
                    health -= damage;
                    if (health <= 0) {
                        printf("You have been defeated by the aliens. Game Over.\n");
                        return 0;
                    }
                }
                break;
            case 3:
                printf("You trade 10 gold for 20 health points.\n");
                gold -= 10;
                health += 20;
                if (health > 100) {
                    health = 100;
                }
                break;
            default:
                printf("Invalid selection. Try again.\n");
                break;
        }
    }
    return 0;
}