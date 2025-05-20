//Falcon-180B DATASET v1.0 Category: Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //initialize variables
    int playerScore = 0, computerScore = 0;
    char choice;
    int randomNumber;

    //seed the random number generator
    srand(time(NULL));

    //game loop
    while(1) {
        //display the scores
        printf("\nPlayer Score: %d\n", playerScore);
        printf("Computer Score: %d\n\n", computerScore);

        //ask the player for their choice
        printf("Enter your choice (r/p/s): ");
        scanf("%c", &choice);

        //generate a random number between 1 and 6
        randomNumber = rand() % 6 + 1;

        //determine the winner of the round
        if(choice == 'r' && randomNumber % 2 == 0) {
            printf("You win this round!\n");
            playerScore++;
        } else if(choice == 'r' && randomNumber % 2 == 1) {
            printf("Computer wins this round.\n");
            computerScore++;
        } else if(choice == 'p') {
            if(randomNumber % 2 == 0) {
                printf("It's a tie!\n");
            } else {
                printf("Computer wins this round.\n");
                computerScore++;
            }
        } else if(choice =='s') {
            if(randomNumber % 2 == 0) {
                printf("You win this round!\n");
                playerScore++;
            } else {
                printf("Computer wins this round.\n");
                computerScore++;
            }
        } else {
            printf("Invalid input.\n");
        }

        //check for game over
        if(playerScore == 5 || computerScore == 5) {
            printf("\nGame over! Player score: %d\n", playerScore);
            printf("Computer score: %d\n", computerScore);
            break;
        }
    }

    return 0;
}