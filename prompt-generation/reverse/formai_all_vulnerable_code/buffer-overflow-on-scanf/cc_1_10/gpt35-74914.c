//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int health = 100, coins = 0, maxHealth = 100, level = 1;

void clear() {
    system("@cls||clear");
}

void wait(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

void gameOver() {
    clear();
    printf("===================================\n");
    printf("             GAME OVER\n");
    printf("===================================\n");
    printf("You ran out of health and lost the game!\n");
    printf("You reached level %d and collected %d coins.\n", level, coins);
    wait(3);
    exit(0);
}

void levelUp() {
    level++;
    maxHealth += 50;
    health = maxHealth;
    coins += 100;
    clear();
    printf("===================================\n");
    printf("             LEVEL UP!\n");
    printf("===================================\n");
    printf("You are now on level %d!\n", level);
    printf("You gained 50 max health and 100 coins!\n");
    wait(3);
}

void enemyEncounter() {
    int enemyHealth = 50, enemyAttack = 5;
    clear();
    printf("===================================\n");
    printf("         ENEMY ENCOUNTERED\n");
    printf("===================================\n");
    printf("An enemy has appeared! Prepare for battle!\n");

    while (enemyHealth > 0 && health > 0) {
        printf("\nYour health: %d\n", health);
        printf("Enemy health: %d\n\n", enemyHealth);
        printf("What do you want to do?\n");
        printf("1. Attack\n");
        printf("2. Heal\n");
        printf("3. Run\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Attack
                enemyHealth -= (rand() % 10 + 5);
                printf("\nYou dealt %d damage to the enemy!\n", (rand() % 10 + 5));
                wait(2);
                health -= enemyAttack;
                printf("The enemy attacks and deals %d damage to you!\n", enemyAttack);
                wait(2);
                break;
            case 2: // Heal
                if (health < maxHealth) {
                    int healAmount = (rand() % 20 + 10);
                    health += healAmount;
                    printf("\nYou healed yourself for %d health!\n", healAmount);
                    wait(2);
                    health -= enemyAttack;
                    printf("The enemy attacks and deals %d damage to you!\n", enemyAttack);
                    wait(2);
                } else {
                    printf("\nYour health is already at maximum!\n");
                    wait(2);
                }
                break;
            case 3: // Run
                clear();
                printf("You manage to escape from the enemy!\n");
                wait(2);
                return;
            default:
                printf("\nInvalid choice!\n");
                wait(2);
                break;
        }
    }

    if (health <= 0) {
        gameOver();
    }

    clear();
    printf("===================================\n");
    printf("         ENEMY DEFEATED\n");
    printf("===================================\n");
    printf("You defeated the enemy and gained 50 coins!\n");
    coins += 50;
    wait(3);
}

void shop() {
    clear();
    printf("===================================\n");
    printf("             THE SHOP\n");
    printf("===================================\n");
    printf("1. Increase max health (+50) - 100 coins\n");
    printf("2. Heal to full health - 50 coins\n");
    printf("3. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if (coins >= 100) {
                coins -= 100;
                maxHealth += 50;
                health = maxHealth;
                printf("\nYou increased your max health to %d!\n", maxHealth);
                wait(2);
            } else {
                printf("\nYou do not have enough coins!\n");
                wait(2);
            }
            break;
        case 2:
            if (coins >= 50) {
                coins -= 50;
                health = maxHealth;
                printf("\nYou healed to full health!\n");
                wait(2);
            } else {
                printf("\nYou do not have enough coins!\n");
                wait(2);
            }
            break;
        case 3:
            return;
        default:
            printf("\nInvalid choice!\n");
            wait(2);
            break;
    }
    shop();
}

void playGame() {
    clear();
    printf("===================================\n");
    printf("            RETRO ADVENTURE\n");
    printf("===================================\n");
    printf("You are on level %d with %d health and %d coins.\n", level, health, coins);
    printf("What do you want to do?\n");
    printf("1. Explore\n");
    printf("2. Visit the shop\n");
    printf("3. Quit\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Explore
            if (rand() % 2 == 0) {
                enemyEncounter();
            } else {
                printf("\nYou explore and find nothing of interest.\n");
                wait(2);
            }
            break;
        case 2: // Visit the shop
            shop();
            break;
        case 3: // Quit
            printf("\nGoodbye!\n");
            exit(0);
        default:
            printf("\nInvalid choice!\n");
            wait(2);
            break;
    }

    if (coins >= 200) {
        levelUp();
    }
    playGame();
}

int main() {
    srand(time(NULL));
    playGame();
    return 0;
}