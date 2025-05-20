//FormAI DATASET v1.0 Category: Random ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_guesses = 0;
    int guess;
    int correct_num = 0;
    int max_num;
    char play_again = 'y';

    srand(time(NULL)); // seed random generator with current time

    printf("Welcome to the guessing game! Please enter the maximum number you would like to guess (must be greater than 1): ");
    scanf("%d", &max_num);

    while (max_num < 2) { // keep prompting user until valid number is entered
        printf("Invalid input. Please enter a number greater than 1: ");
        scanf("%d", &max_num);
    }

    while (play_again == 'y') { // outer game loop
        num_guesses = 0;
        correct_num = rand() % max_num + 1; // generate random number to guess
        printf("I'm thinking of a number between 1 and %d...can you guess it? ", max_num);

        do { // inner guessing loop
            scanf("%d", &guess);
            num_guesses++;

            if (guess < correct_num) {
                printf("Sorry, that guess is too low. Try again: ");
            } else if (guess > correct_num) {
                printf("Sorry, that guess is too high. Try again: ");
            }
        } while (guess != correct_num);

        printf("Congratulations, you guessed correctly in %d attempts!\n", num_guesses);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again); // note the space before %c to consume any whitespace left in stdin

        while (play_again != 'y' && play_again != 'n') { // keep prompting user until valid input is entered
            printf("Invalid input. Please enter 'y' or 'n': ");
            scanf(" %c", &play_again);
        }
    }

    printf("Goodbye! Thanks for playing.\n");

    return 0;
}