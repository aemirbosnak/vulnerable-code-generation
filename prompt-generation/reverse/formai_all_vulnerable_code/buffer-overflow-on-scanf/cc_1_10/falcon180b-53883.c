//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0;
    int choice, guess;
    char play_again;

    srand(time(0));

    do {
        printf("Welcome to the Guessing Game!\n\n");
        printf("You will have to guess a number between 1 and 100.\n");
        printf("The computer will tell you if your guess is too high or too low.\n");
        printf("Try to guess the number in as few turns as possible.\n");
        printf("Good luck!\n\n");

        int secret_number = rand() % 100 + 1;

        int turns = 0;

        while (player_score < 10 && computer_score < 10) {
            printf("Turn %d\n", ++turns);
            printf("Computer's score: %d\n", computer_score);
            printf("Your score: %d\n\n", player_score);

            printf("Guess a number: ");
            scanf("%d", &guess);

            if (guess == secret_number) {
                printf("Congratulations! You guessed the number in %d turns.\n", turns);
                player_score += 10;
            } else if (guess < secret_number) {
                printf("Too low. Guess again: ");
            } else {
                printf("Too high. Guess again: ");
            }
        }

        if (player_score == 10) {
            printf("\nYou win! The computer could not guess the number in 10 turns.\n");
        } else {
            printf("\nYou lose! The computer guessed the number in %d turns.\n", turns);
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}