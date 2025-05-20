//Falcon-180B DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerScore = 0;
    int computerScore = 0;
    int choice;
    int computerChoice;

    printf("Welcome to the Rock-Paper-Scissors game!\n\n");

    while(1) {
        printf("Your score: %d\n", playerScore);
        printf("Computer score: %d\n\n", computerScore);

        printf("Choose one:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &choice);

        computerChoice = rand() % 3;

        if(choice == computerChoice) {
            printf("It's a tie!\n");
        } else if((choice == 1 && computerChoice == 2) ||
                   (choice == 2 && computerChoice == 1) ||
                   (choice == 3 && computerChoice == 0) ||
                   (choice == 0 && computerChoice == 3)) {
            printf("You win!\n");
            playerScore++;
        } else {
            printf("You lose.\n");
            computerScore++;
        }

        printf("\nDo you want to play again? (y/n): ");
        char playAgain;
        scanf(" %c", &playAgain);

        if(playAgain!= 'y') {
            break;
        }
    }

    if(playerScore > computerScore) {
        printf("Congratulations! You won the game with a score of %d to %d.\n", playerScore, computerScore);
    } else if(computerScore > playerScore) {
        printf("Sorry, you lost the game with a score of %d to %d.\n", playerScore, computerScore);
    } else {
        printf("It's a tie game with a score of %d to %d.\n", playerScore, computerScore);
    }

    return 0;
}