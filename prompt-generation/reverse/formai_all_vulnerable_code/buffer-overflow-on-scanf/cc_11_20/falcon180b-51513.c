//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char name[20];
    int health = 100;
    int money = 1000;
    int level = 1;
    int xp = 0;
    int enemyhealth = 50;
    int enemyattack = 10;
    int playerenemy = 0;

    srand(time(NULL));

    printf("Welcome to the Space Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    while(1) {
        system("clear");
        printf("Health: %d\n", health);
        printf("Money: %d\n", money);
        printf("Level: %d\n", level);
        printf("XP: %d\n", xp);

        printf("\nWhat would you like to do?\n");
        printf("1. Attack Enemy\n");
        printf("2. Buy Health Potion\n");
        printf("3. Buy Weapon\n");
        printf("4. Save Game\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                playerenemy = 1;
                while(playerenemy == 1) {
                    enemyhealth -= 10;
                    if(enemyhealth <= 0) {
                        printf("\nYou defeated the enemy! You gained 10 XP.\n");
                        xp += 10;
                        playerenemy = 0;
                    }
                    else {
                        printf("\nThe enemy attacks you for %d damage!\n", enemyattack);
                        health -= enemyattack;
                        if(health <= 0) {
                            printf("\nYou died. Game Over.\n");
                            return 0;
                        }
                    }
                }
                break;
            case 2:
                if(money >= 50) {
                    printf("\nYou bought a health potion. You now have %d health.\n", health + 25);
                    health += 25;
                    money -= 50;
                }
                else {
                    printf("\nYou don't have enough money.\n");
                }
                break;
            case 3:
                if(money >= 100) {
                    printf("\nYou bought a weapon. Your attack power is now 10.\n");
                    money -= 100;
                }
                else {
                    printf("\nYou don't have enough money.\n");
                }
                break;
            case 4:
                printf("\nGame saved.\n");
                break;
            case 5:
                printf("\nThanks for playing! See you next time.\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}