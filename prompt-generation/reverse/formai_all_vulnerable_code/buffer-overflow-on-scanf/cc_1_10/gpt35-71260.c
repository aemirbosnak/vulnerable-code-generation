//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int health = 100;
int strength = 10;
int gold = 0;

void showStats() {
    printf("Health: %d\n", health);
    printf("Strength: %d\n", strength);
    printf("Gold: %d\n", gold);
}

void gameOver() {
    printf("Game over!\n\n");
    printf("Thank you for playing this adventure game.\n\n");
    exit(0);
}

void fight() {
    int enemyHealth = rand() % 50 + 30;
    int enemyStrength = rand() % 5 + 5;
    printf("A wild monster appears!\n");
    while (health > 0 && enemyHealth > 0) {
        int damage = rand() % strength + 1;
        enemyHealth -= damage;
        printf("You deal %d damage to the monster.\n", damage);
        if (enemyHealth <= 0) break;
        damage = rand() % enemyStrength + 1;
        health -= damage;
        printf("The monster deals %d damage to you.\n", damage);
        showStats();
    }
    if (enemyHealth <= 0) {
        printf("You have defeated the monster!\n");
        int gain = rand() % 20 + 10;
        gold += gain;
        printf("You earn %d gold.\n", gain);
    } else {
        printf("You have been defeated by the monster.\n");
        gameOver();
    }
}

void shop() {
    printf("Welcome to the shop.\n");
    printf("You have %d gold.\n", gold);
    printf("What would you like to buy?\n");
    while (1) {
        printf("1. Health potion (30 gold)\n");
        printf("2. Strength potion (50 gold)\n");
        printf("3. Exit shop\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            if (gold < 30) {
                printf("You don't have enough gold.\n");
            } else {
                gold -= 30;
                health += 20;
                if (health > 100) health = 100;
                printf("You have %d health.\n", health);
                printf("You have %d gold left.\n", gold);
            }
        } else if (choice == 2) {
            if (gold < 50) {
                printf("You don't have enough gold.\n");
            } else {
                gold -= 50;
                strength += 5;
                printf("You have %d strength.\n", strength);
                printf("You have %d gold left.\n", gold);
            }
        } else if (choice == 3) {
            printf("Thank you for visiting the shop.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
}

int main() {
    srand(time(0));
    printf("Welcome to the Adventure Game!\n");
    printf("You are a brave adventurer, seeking treasure and battling monsters.\n");
    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Fight a monster\n");
        printf("2. Visit the shop\n");
        printf("3. Quit game\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            fight();
        } else if (choice == 2) {
            shop();
        } else if (choice == 3) {
            printf("Thank you for playing this adventure game.\n");
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }
        if (health <= 0) {
            printf("You died.\n");
            gameOver();
        }
    }
    return 0;
}