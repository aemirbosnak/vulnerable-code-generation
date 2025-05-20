//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerHealth = 100;
    int enemyHealth = 50;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are in a dark forest, surrounded by trees.\n");
    printf("There is a path leading north and another leading east.\n");
    printf("Which way do you want to go? (n/e) ");

    char choice;
    scanf("%c", &choice);

    switch(choice) {
        case 'n':
            printf("You walk along the path to the north.\n");
            printf("Suddenly, an enemy appears!\n");
            while(enemyHealth > 0 && playerHealth > 0) {
                printf("What do you want to do? (a)ttack or (d)efend? ");
                char action;
                scanf("%c", &action);

                if(action == 'a') {
                    printf("You attack the enemy and deal 10 damage!\n");
                    enemyHealth -= 10;
                } else if(action == 'd') {
                    printf("You defend yourself and take 5 damage.\n");
                    playerHealth -= 5;
                } else {
                    printf("Invalid action.\n");
                }
            }

            if(playerHealth <= 0) {
                printf("You have been defeated by the enemy.\n");
                return 0;
            } else {
                printf("You have defeated the enemy.\n");
            }
            break;

        case 'e':
            printf("You walk along the path to the east.\n");
            printf("You find a treasure chest!\n");
            printf("Do you want to open it? (y/n) ");
            char openChest;
            scanf("%c", &openChest);

            if(openChest == 'y') {
                printf("You open the chest and find 50 gold coins!\n");
            } else {
                printf("You decide not to open the chest.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
            return 0;
    }

    return 0;
}