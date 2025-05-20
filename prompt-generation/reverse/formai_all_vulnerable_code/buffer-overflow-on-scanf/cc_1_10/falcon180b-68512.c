//Falcon-180B DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void playGame(int playerScore, int computerScore);
int getRandomNumber(int min, int max);

int main() {
    int playerScore = 0;
    int computerScore = 0;
    int choice;
    char playAgain = 'y';

    srand(time(NULL));

    while (playAgain == 'y' || playAgain == 'Y') {
        printf("Welcome to the Shocking Game!\n");
        printf("You will be shocked by the computer.\n");
        printf("Try to avoid being shocked by pressing 1, 2 or 3.\n");
        printf("Press any key to start...\n");
        getchar();

        int numShocks = getRandomNumber(1, 3);
        for (int i = 0; i < numShocks; i++) {
            int shockResult = getRandomNumber(1, 3);
            if (shockResult == 1) {
                printf("You got shocked! Lose one point.\n");
                computerScore++;
            } else if (shockResult == 2) {
                printf("You avoided the shock.\n");
            } else {
                printf("The shock missed you.\n");
            }
        }

        playGame(playerScore, computerScore);

        printf("Do you want to play again? (y/n): ");
        scanf("%c", &playAgain);
    }

    return 0;
}

void playGame(int playerScore, int computerScore) {
    if (playerScore > computerScore) {
        printf("You win the game!\n");
    } else if (computerScore > playerScore) {
        printf("You lose the game.\n");
    } else {
        printf("It's a tie.\n");
    }
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}