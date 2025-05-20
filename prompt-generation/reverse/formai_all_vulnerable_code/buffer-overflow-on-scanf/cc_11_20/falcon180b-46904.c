//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int health = 100;
    int money = 100;
    int level = 1;
    int experience = 0;
    int enemyHealth = 50;
    int enemyDamage = 10;
    int playerDamage = 20;
    int gold = 50;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a level %d adventurer with %d health and %d gold.\n", level, health, gold);

    while(1) {
        system("clear");
        printf("What would you like to do?\n");
        printf("1. Attack enemy\n");
        printf("2. Rest\n");
        printf("3. Buy item\n");
        printf("4. Sell item\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(health <= 0) {
                    printf("You are too injured to fight.\n");
                } else if(money < 10) {
                    printf("You do not have enough money to buy a weapon.\n");
                } else {
                    enemyHealth -= playerDamage;
                    if(enemyHealth <= 0) {
                        printf("You have defeated the enemy!\n");
                        experience += 10;
                    } else {
                        printf("The enemy has %d health left.\n", enemyHealth);
                    }
                    health -= enemyDamage;
                    if(health <= 0) {
                        printf("You have been defeated by the enemy.\n");
                        return 0;
                    } else {
                        printf("You have %d health left.\n", health);
                    }
                }
                break;
            case 2:
                printf("You rest for a while and regain 10 health.\n");
                health += 10;
                break;
            case 3:
                if(money < 50) {
                    printf("You do not have enough money to buy the item.\n");
                } else {
                    printf("You buy the item and increase your damage by 5!\n");
                    playerDamage += 5;
                    money -= 50;
                }
                break;
            case 4:
                if(level == 1 && money >= 50) {
                    printf("You sell the item and gain 25 gold.\n");
                    money += 25;
                } else {
                    printf("You cannot sell this item.\n");
                }
                break;
            case 5:
                printf("Thank you for playing!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}