//Falcon-180B DATASET v1.0 Category: Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerScore = 0;
    int computerScore = 0;
    char choice;

    do {
        printf("\nWelcome to Rock Paper Scissors!\n");
        printf("Player score: %d\n", playerScore);
        printf("Computer score: %d\n", computerScore);
        printf("Enter your choice (r/p/s): ");
        scanf(" %c", &choice);

        switch(choice) {
            case 'r':
                printf("You chose rock.\n");
                if(rand() % 2 == 0) {
                    printf("Computer chose scissors.\n");
                    computerScore++;
                } else {
                    printf("Computer chose paper.\n");
                    playerScore++;
                }
                break;
            case 'p':
                printf("You chose paper.\n");
                if(rand() % 2 == 0) {
                    printf("Computer chose rock.\n");
                    computerScore++;
                } else {
                    printf("Computer chose scissors.\n");
                    playerScore++;
                }
                break;
            case's':
                printf("You chose scissors.\n");
                if(rand() % 2 == 0) {
                    printf("Computer chose paper.\n");
                    computerScore++;
                } else {
                    printf("Computer chose rock.\n");
                    playerScore++;
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(playerScore < 5 || computerScore < 5);

    if(playerScore == computerScore) {
        printf("\nTie game! Final score: %d - %d\n", playerScore, computerScore);
    } else if(playerScore > computerScore) {
        printf("\nYou win! Final score: %d - %d\n", playerScore, computerScore);
    } else {
        printf("\nComputer wins! Final score: %d - %d\n", playerScore, computerScore);
    }

    return 0;
}