//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int playerHealth = 100;
    int enemyHealth = 50;

    srand(time(0));

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave warrior on a quest to defeat the evil dragon.\n");
    printf("Choose your path wisely.\n");

    int randomEnemy = rand() % 2;

    if(randomEnemy == 0) {
        printf("\nYou encounter a fierce ogre!\n");
    } else {
        printf("\nYou encounter a sly goblin!\n");
    }

    while(playerHealth > 0 && enemyHealth > 0) {
        printf("\nWhat will you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Run\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nYou swing your sword at the enemy.\n");
            enemyHealth -= 10;
        } else if(choice == 2) {
            printf("\nYou raise your shield to defend yourself.\n");
            playerHealth -= 5;
        } else if(choice == 3) {
            printf("\nYou turn and run away as fast as you can.\n");
            break;
        } else {
            printf("\nInvalid choice. Try again.\n");
        }
    }

    if(playerHealth <= 0) {
        printf("\nYou have been defeated by the enemy.\n");
    } else {
        printf("\nYou have defeated the enemy!\n");
    }

    return 0;
}