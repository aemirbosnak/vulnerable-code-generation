//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayWelcome();
void chooseAction();
void exploreRoom();
void fightMonster();
void findTreasure();
int getRandomNumber(int min, int max);
int health = 100;
int treasureCount = 0;

int main() {
    displayWelcome();
    while (health > 0) {
        chooseAction();
        if (health <= 0) {
            printf("You have fallen in battle. Game over.\n");
            break;
        }
    }
    return 0;
}

void displayWelcome() {
    printf("=========================================\n");
    printf("        WELCOME TO THE DUNGEON        \n");
    printf("=========================================\n");
    printf("You find yourself standing at the entrance of a dark dungeon...\n");
    printf("Your goal is to explore, defeat monsters, and find valuable treasures.\n");
    printf("Beware, dangers lurk around every corner!\n");
    printf("You have %d health points.\n", health);
    printf("=========================================\n");
}

void chooseAction() {
    int choice;
    printf("Choose your action:\n");
    printf("1. Explore a room\n");
    printf("2. Check your status\n");
    printf("3. Use a healing potion\n");
    printf("4. Exit the dungeon\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            exploreRoom();
            break;
        case 2:
            printf("Health: %d\n", health);
            printf("Treasure Count: %d\n", treasureCount);
            break;
        case 3:
            if (health < 100) {
                health = 100;
                printf("You have used a healing potion and restored your health to 100!\n");
            } else {
                printf("You are already at full health!\n");
            }
            break;
        case 4:
            printf("You have chosen to leave the dungeon. Farewell!\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }
}

void exploreRoom() {
    int encounter = getRandomNumber(0, 1); // 0 = treasure, 1 = monster

    if (encounter == 0) {
        findTreasure();
    } else {
        fightMonster();
    }
}

void fightMonster() {
    printf("You have encountered a fearsome monster!\n");
    int monsterHealth = getRandomNumber(20, 50); // random monster health
    printf("Monster's health: %d\n", monsterHealth);
    
    while (monsterHealth > 0 && health > 0) {
        monsterHealth -= getRandomNumber(10, 30);
        health -= getRandomNumber(5, 20);
        printf("You attack the monster! Monster's health: %d\n", monsterHealth);
        printf("You have been attacked! Your health: %d\n", health);
    }
    
    if (health > 0) {
        printf("You have slain the monster!\n");
    } else {
        printf("You have been killed by the monster...\n");
    }
}

void findTreasure() {
    int treasureFound = getRandomNumber(1, 10);
    treasureCount += treasureFound;
    printf("You have found %d treasures!\n", treasureFound);
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}