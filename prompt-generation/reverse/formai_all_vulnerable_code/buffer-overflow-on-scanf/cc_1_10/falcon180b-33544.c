//Falcon-180B DATASET v1.0 Category: Game ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int score = 0;
    int lives = 5;
    char name[50];

    printf("Welcome to the surrealist game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    while(lives > 0) {
        printf("\n%s, you have %d lives left.\n", name, lives);
        printf("Choose your path:\n1. The Forest of Mirrors\n2. The Desert of Illusions\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou find yourself in the Forest of Mirrors, a place where nothing is as it seems.\n");
                printf("Do you:\n1. Continue forward\n2. Turn back\n");
                scanf("%d", &choice);

                if(choice == 1) {
                    printf("\nYou continue forward and suddenly come across a giant mirror.\n");
                    printf("Do you:\n1. Look into the mirror\n2. Walk away\n");
                    scanf("%d", &choice);

                    if(choice == 1) {
                        printf("\nYou look into the mirror and see a distorted version of yourself.\n");
                        score += 10;
                    } else {
                        printf("\nYou walk away, feeling uneasy about what you might have seen.\n");
                    }
                } else {
                    printf("\nYou turn back, feeling a sense of relief.\n");
                }
                break;

            case 2:
                printf("\nYou find yourself in the Desert of Illusions, a place where reality is blurred.\n");
                printf("Do you:\n1. Continue forward\n2. Turn back\n");
                scanf("%d", &choice);

                if(choice == 1) {
                    printf("\nYou continue forward and suddenly come across a mirage of an oasis.\n");
                    printf("Do you:\n1. Approach the oasis\n2. Walk away\n");
                    scanf("%d", &choice);

                    if(choice == 1) {
                        printf("\nYou approach the oasis and it disappears before your eyes.\n");
                        score += 20;
                    } else {
                        printf("\nYou walk away, knowing that the oasis was just an illusion.\n");
                    }
                } else {
                    printf("\nYou turn back, feeling a sense of disappointment.\n");
                }
                break;

            default:
                printf("\nInvalid choice. You lose a life.\n");
                lives--;
        }
    }

    if(score == 0) {
        printf("\n%s, you have lost the game. Better luck next time!\n", name);
    } else {
        printf("\n%s, you have won the game with a score of %d!\n", name, score);
    }

    return 0;
}