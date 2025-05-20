//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    printf("Welcome to the Text-Based Adventure Game!\n");

    int playerHealth = 100;
    int enemyHealth = 50;

    while(playerHealth > 0 && enemyHealth > 0) {
        printf("You have %d health left.\n", playerHealth);
        printf("The enemy has %d health left.\n", enemyHealth);
        printf("What would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Rest\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                playerHealth -= 10;
                enemyHealth -= rand() % 6 + 1;
                printf("You attacked the enemy and dealt %d damage!\n", rand() % 6 + 1);
                printf("You lost 10 health.\n");
                break;
            case 2:
                playerHealth -= 5;
                enemyHealth -= rand() % 4 + 1;
                printf("You defended yourself and dealt %d damage!\n", rand() % 4 + 1);
                printf("You lost 5 health.\n");
                break;
            case 3:
                printf("You rested and regained 10 health.\n");
                playerHealth += 10;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    if(playerHealth <= 0) {
        printf("You lost the game.\n");
    } else {
        printf("You won the game!\n");
    }

    return 0;
}