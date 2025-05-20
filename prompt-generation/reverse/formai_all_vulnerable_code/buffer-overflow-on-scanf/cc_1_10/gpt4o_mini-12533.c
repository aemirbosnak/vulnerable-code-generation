//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void intro() {
    printf("Welcome to the Land of Eldoria!\n");
    printf("In this mystical realm, you embark on a quest to save the kingdom.\n");
    printf("You are a brave knight, and your decisions will shape your destiny.\n");
    printf("\n");
    printf("Press Enter to begin your adventure...");
    getchar();
}

void encounterMonsters(int* health) {
    int monsterHealth = 20;
    printf("You have encountered a ferocious monster!\n");
    while (*health > 0 && monsterHealth > 0) {
        printf("Your health: %d, Monster's health: %d\n", *health, monsterHealth);
        printf("Choose your action:\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Run Away\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You attack the monster!\n");
            monsterHealth -= 10;
            printf("You dealt 10 damage!\n");
        } else if (choice == 2) {
            printf("You defend against the monster's attack!\n");
            printf("You take half damage.\n");
            *health -= 5; // Monster counterattacks
        } else if (choice == 3) {
            printf("You attempt to run away!\n");
            if (rand() % 2 == 0) {
                printf("You successfully escaped!\n");
                break;
            } else {
                printf("You failed to escape!\n");
                *health -= 5; // Monster attacks
            }
        } else {
            printf("Invalid choice! You lose your turn.\n");
        }
    }
}

void village() {
    int health = 30;
    printf("You arrive at a small village. The villagers need your help!\n");
    printf("Would you like to:\n");
    printf("1. Help the villagers\n");
    printf("2. Ignore them and leave\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You offer your assistance...\n");
        encounterMonsters(&health);
    } else {
        printf("You decide to leave the villagers and continue your journey...\n");
    }

    if (health <= 0) {
        printf("You have fallen in battle. Your adventure ends here.\n");
    } else {
        printf("You managed to survive with %d health remaining.\n", health);
        printf("You continue your journey...\n");
    }
}

void castle() {
    printf("You arrive at the grand Castle of Eldoria. You see a mysterious figure waiting for you...\n");
    printf("It's the King!\n");
    printf("King: 'Brave knight, we need your help to defeat a dark sorcerer.'\n");
    printf("Do you wish to:\n");
    printf("1. Accept the King's quest\n");
    printf("2. Decline and leave the castle\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You have accepted the King's quest!\n");
        printf("Prepare yourself for the ultimate battle!\n");
        int health = 30;
        encounterMonsters(&health);
    } else {
        printf("You have chosen not to accept the quest. Your adventures might be over...\n");
    }
}

int main() {
    srand(time(NULL));
    intro();

    printf("You find yourself at a crossroads.\n");
    printf("Do you wish to:\n");
    printf("1. Go to the village\n");
    printf("2. Go to the castle\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        village();
    } else if (choice == 2) {
        castle();
    } else {
        printf("Invalid choice. Your adventure ends before it begins.\n");
    }

    printf("Thank you for playing!\n");
    return 0;
}