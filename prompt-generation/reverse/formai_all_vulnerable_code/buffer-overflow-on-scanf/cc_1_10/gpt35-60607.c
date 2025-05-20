//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playerHealth = 100;
int enemyHealth = 100;
int enemyDamage = 25;
int playerDamage;
int potions = 3;

int generateRandomNumber(int max) {
    srand(time(NULL));
    return rand() % max + 1;
}

void attack() {
    playerDamage = generateRandomNumber(30);
    printf("You attack the enemy and deal %d damage.\n", playerDamage);
    enemyHealth -= playerDamage;
}

void defend() {
    printf("You defend yourself from enemy's attack.\n");
}

void drinkPotion() {
    if (potions > 0) {
        printf("You drink a potion and regain 30 health.\n");
        playerHealth += 30;
        potions--;
    } else {
        printf("You don't have any potions left!\n");
    }
}

void enemyAttack() {
    printf("The enemy attacks you and deals %d damage.\n", enemyDamage);
    playerHealth -= enemyDamage;
}

void gameOver() {
    printf("Game Over! You have been defeated by the enemy.\n");
}

int main() {
    printf("Welcome to the Adventure Game!\n");

    while (playerHealth > 0 && enemyHealth > 0) {
        printf("Your current health is %d.\n", playerHealth);
        printf("The enemy's current health is %d.\n", enemyHealth);
        printf("What do you want to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Drink Potion\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                attack();
                break;
            case 2:
                defend();
                break;
            case 3:
                drinkPotion();
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }

        if (enemyHealth > 0) {
            enemyAttack();
        }

        if (playerHealth <= 0) {
            gameOver();
            break;
        }
    }

    if (enemyHealth <= 0) {
        printf("Congratulations! You have defeated the enemy.\n");
    }

    printf("Thanks for playing the Adventure Game!\n");

    return 0;
}