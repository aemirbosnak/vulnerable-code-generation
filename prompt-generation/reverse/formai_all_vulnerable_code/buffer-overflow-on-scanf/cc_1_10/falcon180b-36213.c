//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerHP = rand() % 101 + 50;
    int enemyHP = rand() % 101 + 50;

    printf("In a post-apocalyptic world, you find yourself face to face with an enemy.\n");
    printf("You have %d health points and the enemy has %d health points.\n", playerHP, enemyHP);

    while (playerHP > 0 && enemyHP > 0) {
        printf("What will you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Use item\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You attack the enemy with all your might!\n");
                enemyHP -= rand() % 21 + 5;
                if (enemyHP <= 0) {
                    printf("You have defeated the enemy!\n");
                    break;
                }
                printf("The enemy retaliates and reduces your health points by %d.\n", rand() % 21 + 5);
                playerHP -= rand() % 21 + 5;
                break;
            case 2:
                printf("You defend yourself against the enemy's attack.\n");
                if (rand() % 2 == 0) {
                    printf("You successfully defend yourself and reduce the damage taken by half.\n");
                    playerHP -= rand() % 21 + 5;
                } else {
                    printf("You fail to defend yourself and take full damage.\n");
                    playerHP -= rand() % 21 + 5;
                }
                printf("The enemy reduces your health points by %d.\n", rand() % 21 + 5);
                break;
            case 3:
                printf("You use an item to heal yourself.\n");
                playerHP += rand() % 21 + 5;
                printf("You feel rejuvenated and ready to continue the fight!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    if (playerHP > 0) {
        printf("You have survived the encounter with the enemy.\n");
    } else {
        printf("You have been defeated by the enemy.\n");
    }

    return 0;
}