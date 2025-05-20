//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Set up random number generator
    srand(time(NULL));

    // Declare and initialize variables
    int playerScore = 0;
    int computerScore = 0;
    int roundNum = 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("In each round, you and the computer will guess a number between 1 and 10.\n");
    printf("If you guess correctly, you get 2 points. If the computer does, it gets 2 points.\n");
    printf("The game will continue until one player reaches 10 points.\n\n");

    // Start game loop
    while (playerScore < 10 && computerScore < 10){
        // Print round number and player scores
        printf("Round %d\n", roundNum);
        printf("Your score: %d\n", playerScore);
        printf("Computer score: %d\n", computerScore);

        // Get player guess
        int playerGuess;
        printf("Guess a number between 1 and 10: ");
        scanf("%d", &playerGuess);

        // Generate computer guess
        int computerGuess = (rand() % 10) + 1;
        printf("Computer's guess: %d\n", computerGuess);

        // Determine winner of round
        if (playerGuess == computerGuess){
            printf("You both guessed %d. It's a tie!\n\n", playerGuess);
        }
        else if (abs(playerGuess - computerGuess) == 1){
            if (playerGuess > computerGuess){
                printf("You win! You guessed %d and the computer guessed %d.\n\n", playerGuess, computerGuess);
                playerScore += 2;
            }
            else{
                printf("The computer wins! You guessed %d and it guessed %d.\n\n", playerGuess, computerGuess);
                computerScore += 2;
            }
        }
        else{
            if (playerGuess > computerGuess){
                printf("The computer wins! You guessed %d and it guessed %d.\n\n", playerGuess, computerGuess);
                computerScore += 2;
            }
            else{
                printf("You win! You guessed %d and the computer guessed %d.\n\n", playerGuess, computerGuess);
                playerScore += 2;
            }
        }

        // Increment round number
        roundNum++;
    }

    // Determine winner of game and print final scores
    printf("Final scores:\n");
    printf("Your score: %d\n", playerScore);
    printf("Computer score: %d\n", computerScore);
    if (playerScore > computerScore){
        printf("Congratulations, you win!\n");
    }
    else{
        printf("Sorry, the computer wins. Better luck next time!\n");
    }

    return 0;
}