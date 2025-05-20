//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number
int getRandomNumber(int min, int max){
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main(){
    int playerScore = 0, computerScore = 0, maxScore = 10;
    printf("Welcome to the C Terminal Based Game\n");

    while (playerScore < maxScore && computerScore < maxScore){
        // Player's turn
        printf("\nPlayer's turn:");
        int playerGuess;
        printf("\nGuess the number between 1-10: ");
        scanf("%d", &playerGuess);
        if (playerGuess < 1 || playerGuess > 10){
            printf("\nInvalid input! Guess should be between 1-10.");
            continue;
        }
        int computerNumber = getRandomNumber(1, 10);
        printf("\nThe computer's number was %d", computerNumber);
        if (playerGuess == computerNumber){
            printf("\nCongratulations! You guessed correctly.");
            playerScore++;
        } else {
            printf("\nSorry, you guessed incorrectly.");
        }

        if (playerScore == maxScore || computerScore == maxScore){
            break;
        }

        // Computer's turn
        printf("\n\nComputer's turn:");
        int computerGuess = getRandomNumber(1, 10);
        printf("\nThe computer guessed %d", computerGuess);
        int playerNumber;
        printf("\nPlease enter your number: ");
        scanf("%d", &playerNumber);
        if (playerNumber < 1 || playerNumber > 10){
            printf("\nInvalid input! Guess should be between 1-10.");
            continue;
        }
        if (playerNumber == computerGuess){
            printf("\nSorry, the computer guessed correctly.");
            computerScore++;
        } else {
            printf("\nCongratulations, the computer guessed incorrectly.");
        }
    }

    // Print the results
    printf("\n\nResults:");
    printf("\nPlayer score: %d", playerScore);
    printf("\nComputer score: %d", computerScore);
    if (playerScore > computerScore){
        printf("\nCongratulations! You have won the game.");
    } else if (computerScore > playerScore){
        printf("\nBetter luck next time! The computer has won the game.");
    } else {
        printf("\nThe game is a tie!");
    }
    return 0;
}