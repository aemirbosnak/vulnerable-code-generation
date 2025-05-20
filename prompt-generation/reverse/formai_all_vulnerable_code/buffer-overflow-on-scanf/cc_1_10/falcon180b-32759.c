//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int score = 0;
    int lives = 3;

    srand(time(NULL));

    printf("Welcome to the Space Adventure!\n");

    while(lives > 0) {
        printf("You have %d lives left.\n", lives);
        printf("What would you like to do?\n");
        printf("1. Explore a planet\n2. Engage in space battle\n3. Repair your ship\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You have landed on a planet.\n");
                printf("Do you want to explore further? (y/n)\n");
                char explore;
                scanf(" %c", &explore);

                if(explore == 'y' || explore == 'Y') {
                    printf("You found a treasure! Your score is now %d.\n", score + 10);
                }
                else {
                    printf("You didn't find anything.\n");
                }
                break;

            case 2:
                printf("You are engaged in a space battle!\n");
                int enemyHealth = rand() % 101;
                int playerAttack = rand() % 101;

                if(playerAttack > enemyHealth) {
                    printf("You won the battle! Your score is now %d.\n", score + 20);
                }
                else {
                    printf("You lost the battle. You lost a life.\n");
                    lives--;
                }
                break;

            case 3:
                printf("You are repairing your ship...\n");
                int repairSuccess = rand() % 2;

                if(repairSuccess == 0) {
                    printf("Your ship is now fully repaired!\n");
                }
                else {
                    printf("You failed to repair your ship.\n");
                }
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}