//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to find the lost treasure.\n");
    printf("Choose your path wisely and good luck!\n");

    int health = 100;

    while(health > 0) {
        printf("\nYou are at a crossroads.\n");
        printf("1. Go left.\n");
        printf("2. Go right.\n");
        printf("3. Go forward.\n");
        printf("4. Go back.\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou went left and found a healing potion!\n");
                health += 50;
                break;
            case 2:
                printf("\nYou went right and found a treasure chest!\n");
                printf("You gained 100 gold!\n");
                break;
            case 3:
                printf("\nYou went forward and encountered a fierce dragon!\n");
                printf("Do you want to fight the dragon? (y/n)\n");
                char fight;
                scanf(" %c", &fight);
                if(fight == 'y' || fight == 'Y') {
                    int dragonHealth = rand() % 200 + 1;
                    while(dragonHealth > 0 && health > 0) {
                        printf("\nThe dragon attacks you!\n");
                        health -= rand() % 50 + 1;
                        printf("You attack the dragon!\n");
                        dragonHealth -= rand() % 50 + 1;
                    }
                    if(health <= 0) {
                        printf("\nYou have been defeated by the dragon.\n");
                        return 0;
                    } else {
                        printf("\nYou have defeated the dragon!\n");
                        health += 100;
                    }
                } else {
                    printf("\nYou decided not to fight the dragon and ran away.\n");
                }
                break;
            case 4:
                printf("\nYou went back and found a secret passage!\n");
                printf("You gained 50 gold!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }

    printf("\nCongratulations! You have completed the game with %d health points remaining.\n", health);
    return 0;
}