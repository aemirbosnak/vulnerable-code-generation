//Falcon-180B DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerScore = 0, computerScore = 0;
    char choice;

    do {
        system("clear");
        printf("\n");
        printf("Player Score: %d\n", playerScore);
        printf("Computer Score: %d\n", computerScore);
        printf("\n");
        printf("Choose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("You chose Rock.\n");
                if(rand() % 2 == 0) {
                    printf("It's a tie!\n");
                } else if(rand() % 2 == 1) {
                    printf("You win!\n");
                    playerScore++;
                } else {
                    printf("You lose!\n");
                    computerScore++;
                }
                break;
            case '2':
                printf("You chose Paper.\n");
                if(rand() % 2 == 0) {
                    printf("It's a tie!\n");
                } else if(rand() % 2 == 1) {
                    printf("You win!\n");
                    playerScore++;
                } else {
                    printf("You lose!\n");
                    computerScore++;
                }
                break;
            case '3':
                printf("You chose Scissors.\n");
                if(rand() % 2 == 0) {
                    printf("It's a tie!\n");
                } else if(rand() % 2 == 1) {
                    printf("You win!\n");
                    playerScore++;
                } else {
                    printf("You lose!\n");
                    computerScore++;
                }
                break;
            default:
                printf("Invalid input.\n");
        }

        if(playerScore == 5 || computerScore == 5) {
            printf("\n");
            printf("Game Over!\n");
            printf("Player Score: %d\n", playerScore);
            printf("Computer Score: %d\n", computerScore);
            if(playerScore == 5) {
                printf("You win!\n");
            } else {
                printf("You lose!\n");
            }
            break;
        }
    } while(1);

    return 0;
}