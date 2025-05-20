//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerHealth = 100;
    int enemyHealth = 50;

    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You are a brave warrior on a quest to defeat the evil dragon.\n");
    printf("The dragon has %d health points.\n", enemyHealth);
    printf("You have %d health points.\n\n", playerHealth);

    int choice;
    while(playerHealth > 0 && enemyHealth > 0) {
        printf("What would you like to do?\n");
        printf("1. Attack\n2. Defend\n3. Heal\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You attack the dragon with your sword.\n");
                enemyHealth -= 10;
                if(enemyHealth <= 0) {
                    printf("Congratulations! You have defeated the dragon!\n");
                    break;
                }
                else {
                    printf("The dragon counterattacks and deals 10 damage to you.\n");
                    playerHealth -= 10;
                }
                break;
            case 2:
                printf("You defend yourself with your shield.\n");
                playerHealth -= 5;
                printf("The dragon attacks and deals 5 damage to you.\n");
                enemyHealth -= 5;
                break;
            case 3:
                printf("You use a healing potion to restore 10 health points.\n");
                playerHealth += 10;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    if(playerHealth <= 0) {
        printf("Game Over. You have been defeated by the dragon.\n");
    }

    return 0;
}