//FormAI DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Declare variables
    int guess, number_of_guesses = 0;
    int max_guesses = 6;
    int random_number;
    char play_again = 'y';
    srand(time(0));

    while (play_again == 'y') {
        // Generate a random number between 1 and 100
        random_number = rand() % 100 + 1;

        printf("Welcome to the GUESSING GAME!\n");
        printf("I've picked a number between 1 and 100, try to guess it!\n");

        while (guess != random_number && number_of_guesses < max_guesses) {
            printf("Guess the number: ");
            scanf("%d", &guess);

            if (guess > random_number) {
                printf("Ha ha! Too high! Try again!\n");
            }
            else if (guess < random_number) {
                printf("Eh, too low! Try again!\n");
            }
            else {
                printf("Yay! You did it! You guessed the number in %d tries!\n", number_of_guesses);
                break;
            }

            number_of_guesses++;
        }

        if (number_of_guesses >= max_guesses) {
            printf("Oh no! You used up all your guesses! The number was %d. Better luck next time!\n", random_number);
        }

        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &play_again);

        if (play_again != 'y' && play_again != 'n') {
            printf("Oops, that was an invalid response. I'll assume you don't want to play again. Bye bye!\n");
            play_again = 'n';
        }

        number_of_guesses = 0;
    }

    printf("Thanks for playing the GUESSING GAME! Come back soon!\n");
    return 0;
}