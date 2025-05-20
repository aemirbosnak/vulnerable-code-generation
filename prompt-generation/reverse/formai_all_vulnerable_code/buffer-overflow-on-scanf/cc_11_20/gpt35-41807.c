//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int playerChoice, computerChoice, playerScore = 0, computerScore = 0, tieScore = 0;

    printf("Welcome to the C Table Game!\n");

    srand(time(NULL)); // initialize random seed

    while(1) { // game loop

        printf("\nChoose your move:\n1. Rock\n2. Paper\n3. Scissors\n4. Exit\n");

        scanf("%d", &playerChoice);

        if(playerChoice == 4) {
            printf("\nFinal Scores:\nPlayer: %d\nComputer: %d\nTie: %d\n", playerScore, computerScore, tieScore);
            break; // exit game loop
        }

        computerChoice = (rand() % 3) + 1; // computer generates a random move

        printf("You chose ");

        switch(playerChoice) {
            case 1:
                printf("Rock.\n");
                break;
            case 2:
                printf("Paper.\n");
                break;
            case 3:
                printf("Scissors.\n");
                break;
            default:
                printf("Invalid Choice.\n");
                continue; // restart game loop
        }

        printf("The computer chose ");

        switch(computerChoice) {
            case 1:
                printf("Rock.\n");
                break;
            case 2:
                printf("Paper.\n");
                break;
            case 3:
                printf("Scissors.\n");
                break;
        }

        if(playerChoice == computerChoice) {
            printf("It's a tie!\n");
            tieScore++;
        }

        else if(playerChoice == 1 && computerChoice == 3 || playerChoice == 2 && computerChoice == 1 || playerChoice == 3 && computerChoice == 2) {
            printf("You win!\n");
            playerScore++;
        }

        else {
            printf("You lose!\n");
            computerScore++;
        }

    }

    return 0;

}