//Falcon-180B DATASET v1.0 Category: Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0, computerScore = 0;
    int choice, guess;
    char playAgain = 'y';

    srand(time(NULL));

    while (playAgain == 'y' || playAgain == 'Y') {
        printf("Welcome to the Number Guessing Game!\n");
        printf("I am thinking of a number between 1 and 100.\n");
        printf("Can you guess what it is?\n");

        choice = rand() % 100 + 1;
        printf("The number is %d.\n", choice);

        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess == choice) {
            printf("Congratulations! You guessed the number correctly.\n");
            playerScore++;
        } else if (guess < choice) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }

        computerScore = rand() % 100 + 1;
        printf("The computer's guess is %d.\n", computerScore);

        if (computerScore == choice) {
            printf("The computer guessed the number correctly.\n");
            computerScore++;
        } else if (computerScore < choice) {
            printf("The computer's guess is too low.\n");
        } else {
            printf("The computer's guess is too high.\n");
        }

        if (playerScore >= 5 || computerScore >= 5) {
            printf("The game is over. You win with a score of %d to %d.\n", playerScore, computerScore);
            playAgain = 'n';
        } else {
            printf("Do you want to play again? (y/n) ");
            scanf(" %c", &playAgain);
        }
    }

    return 0;
}