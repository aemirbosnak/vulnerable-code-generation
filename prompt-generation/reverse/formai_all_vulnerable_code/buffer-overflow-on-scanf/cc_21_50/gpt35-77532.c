//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int score = 0;
    char player;
    char computer;
    char decision;
    srand(time(NULL));
    
    printf("Welcome to Shape Shifting Game!\n");
    printf("Instructions:\nChoose one shape out of four: Rock (r), Paper (p), Scissors (s) and Lizard (l).\nRock beats Scissors and Lizard, Paper beats Rock and Lizard, Scissors beat Paper and Lizard, and Lizard beats Paper and Rock.\nIf both players choose the same, it's a tie!\nAre you ready?\n");

    while (1) {
        printf("\nWhat is your move? (r/p/s/l): ");
        scanf(" %c", &player);

        // to check if the player's input is valid
        while (player != 'r' && player != 'p' && player != 's' && player != 'l') {
            printf("\nInvalid move! Please choose again: ");
            scanf(" %c", &player);
        }

        // to generate computer's move
        switch (rand() % 4) {
            case 0:
                computer = 'r';
                printf("Computer chose Rock!\n");
                break;
            case 1:
                computer = 'p';
                printf("Computer chose Paper!\n");
                break;
            case 2:
                computer = 's';
                printf("Computer chose Scissors!\n");
                break;
            case 3:
                computer = 'l';
                printf("Computer chose Lizard!\n");
                break;
        }

        // to check who wins and update the score
        if (player == computer) {
            printf("It's a tie!\n");
        } else if ((player == 'r' && (computer == 's' || computer == 'l')) ||
                   (player == 'p' && (computer == 'r' || computer == 'l')) ||
                   (player == 's' && (computer == 'p' || computer == 'l')) ||
                   (player == 'l' && (computer == 'p' || computer == 'r'))) {
            printf("You won this round!\n");
            score++;
        } else {
            printf("Computer won this round!\n");
            score--;
        }

        printf("Score: %d\n", score);

        // to ask the player if they want to continue playing
        printf("Do you want to continue playing? (y/n): ");
        scanf(" %c", &decision);
        
        // to check if the player's decision is valid
        while (decision != 'y' && decision != 'n') {
            printf("Invalid input! Please enter y or n: ");
            scanf(" %c", &decision);
        }

        if (decision == 'n') {
            printf("Thanks for playing! Final score: %d\n", score);
            break;
        }
    }

    return 0;
}