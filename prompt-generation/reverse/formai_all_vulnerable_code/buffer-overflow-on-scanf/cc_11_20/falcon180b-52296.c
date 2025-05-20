//Falcon-180B DATASET v1.0 Category: Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerScore = 0;
    int computerScore = 0;
    int choice;
    int computerChoice;
    char playAgain;

    do {
        printf("Welcome to Rock Paper Scissors!\n");
        printf("Please choose your move: \n1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You chose Rock.\n");
                computerChoice = rand() % 3;
                if(computerChoice == 0) {
                    printf("Computer chose Rock.\n");
                    computerScore++;
                } else if(computerChoice == 1) {
                    printf("Computer chose Paper.\n");
                    playerScore++;
                } else {
                    printf("Computer chose Scissors.\n");
                }
                break;
            case 2:
                printf("You chose Paper.\n");
                computerChoice = rand() % 3;
                if(computerChoice == 0) {
                    printf("Computer chose Rock.\n");
                    playerScore++;
                } else if(computerChoice == 1) {
                    printf("Computer chose Paper.\n");
                } else {
                    printf("Computer chose Scissors.\n");
                    computerScore++;
                }
                break;
            case 3:
                printf("You chose Scissors.\n");
                computerChoice = rand() % 3;
                if(computerChoice == 0) {
                    printf("Computer chose Rock.\n");
                    computerScore++;
                } else if(computerChoice == 1) {
                    printf("Computer chose Paper.\n");
                    playerScore++;
                } else {
                    printf("Computer chose Scissors.\n");
                }
                break;
            default:
                printf("Invalid move.\n");
        }

        printf("\nScore: You - %d, Computer - %d\n", playerScore, computerScore);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while(playAgain == 'y' || playAgain == 'Y');

    return 0;
}