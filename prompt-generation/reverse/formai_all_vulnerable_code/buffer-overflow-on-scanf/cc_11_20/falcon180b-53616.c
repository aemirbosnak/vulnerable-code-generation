//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int score = 0;
    int lives = 3;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You have %d lives.\n", lives);

    while(lives > 0) {
        printf("What would you like to do?\n");
        printf("1. Explore the forest\n");
        printf("2. Enter the cave\n");
        printf("3. Attack the dragon\n");
        printf("4. Quit\n");
        printf("> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You enter the forest and start exploring.\n");
                printf("Do you want to continue exploring? (y/n)\n");
                char cont;
                scanf(" %c", &cont);
                if(cont == 'y' || cont == 'Y') {
                    printf("You find a treasure chest and gain 10 points!\n");
                    score += 10;
                } else {
                    printf("You decide to leave the forest.\n");
                }
                break;
            case 2:
                printf("You enter the cave and start exploring.\n");
                printf("Do you want to continue exploring? (y/n)\n");
                char cont2;
                scanf(" %c", &cont2);
                if(cont2 == 'y' || cont2 == 'Y') {
                    printf("You find a magical artifact and gain 20 points!\n");
                    score += 20;
                } else {
                    printf("You decide to leave the cave.\n");
                }
                break;
            case 3:
                printf("You attack the dragon with all your might!\n");
                int damage = rand() % 10 + 1;
                printf("You deal %d damage to the dragon.\n", damage);
                if(damage >= 5) {
                    printf("You defeat the dragon and gain 50 points!\n");
                    score += 50;
                } else {
                    printf("The dragon retaliates and you lose a life.\n");
                    lives--;
                }
                break;
            case 4:
                printf("Thanks for playing!\n");
                printf("Your final score is %d.\n", score);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    printf("Game over. Your final score is %d.\n", score);
    return 0;
}