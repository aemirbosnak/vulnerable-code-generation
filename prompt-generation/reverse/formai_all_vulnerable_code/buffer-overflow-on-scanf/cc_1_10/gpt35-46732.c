//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clearScreen() {
    system("clear||cls");
}

void pauseForEnter() {
    printf("\nPress enter to continue...");
    getchar();
}

void printPlayerStats(int health, int level, int damage) {
    printf("\nHealth: %d\nLevel: %d\nDamage: %d\n", health, level, damage);
}

void fightSequence(int *health, int *level, int *damage, int enemyHealth, int enemyDamage) {
    int enemyAttackChance, playerAttackChance;
    while (*health > 0 && enemyHealth > 0) {
        clearScreen();
        printf("Enemy Health: %d\n\n1. Attack\n2. Defend\n", enemyHealth);
        printf("\nYour Health: %d\n\nPlease enter your choice: ", *health);
        scanf("%d", &playerAttackChance);
        if (playerAttackChance == 1) {
            printf("\nYou attack the enemy for %d damage!\n", *damage);
            enemyHealth -= *damage;
            pauseForEnter();
            if (enemyHealth <= 0) {
                clearScreen();
                printf("You have defeated the enemy!\n");
                *level += 1;
                *health += 5;
                *damage += 2;
                printPlayerStats(*health, *level, *damage);
                pauseForEnter();
                break;
            }
        } else {
            printf("\nYou brace for incoming damage.\n");
            pauseForEnter();
        }
        enemyAttackChance = rand() % 2;
        if (enemyAttackChance == 0) {
            printf("\nThe enemy attacks you for %d damage.\n", enemyDamage);
            *health -= enemyDamage;
            pauseForEnter();
            if (*health <= 0) {
                clearScreen();
                printf("You have died.\n");
                exit(0);
            }
        } else {
            printf("\nThe enemy braces for incoming damage.\n");
            pauseForEnter();
        }
    }
}

int main() {
    srand(time(NULL)); // seeding the random number generator
    clearScreen();
    char name[50];
    printf("Welcome adventurer! What is your name? ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0; // removing the newline character from name
    printf("\nHello %s, let's begin your adventure!\n", name);
    int health = 20, level = 1, damage = 5, choice;
    while (health > 0) {
        clearScreen();
        printf("1. Fight\n2. Exit\n\n");
        printPlayerStats(health, level, damage);
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int enemyHealth = rand() % 15 + 5;
            int enemyDamage = rand() % 4 + 1;
            printf("\nYou encounter an enemy with %d health and %d damage.\n", enemyHealth, enemyDamage);
            pauseForEnter();
            fightSequence(&health, &level, &damage, enemyHealth, enemyDamage);
        } else {
            clearScreen();
            printf("Thank you for playing!\n");
            exit(0);
        }
    }
    return 0;
}