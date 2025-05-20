//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_welcome() {
    printf("Welcome to the Happy Number Guessing Game!\n");
    printf("Try to guess the number I've selected between 1 and 100.\n");
    printf("Type '0' to give up and quit the game.\n");
    printf("Good luck and have fun!\n\n");
}

void get_user_input(int *guess) {
    printf("Please enter your guess: ");
    scanf("%d", guess);
}

void give_feedback(int guess, int secret_number) {
    if (guess < secret_number) {
        printf("Too low! Try again.\n");
    } else if (guess > secret_number) {
        printf("Too high! Try again.\n");
    } else {
        printf("Hooray! You've guessed the right number!\n");
    }
}

int main() {
    int secret_number, guess;
    char play_again;

    // Seed for random number generation
    srand(time(NULL));

    print_welcome();

    do {
        secret_number = rand() % 100 + 1;  // Random number between 1 and 100
        printf("I've picked a number between 1 and 100. Let's start!\n");

        do {
            get_user_input(&guess);

            if (guess == 0) {
                printf("You've chosen to quit. The secret number was %d. Better luck next time!\n", secret_number);
                break;
            }

            give_feedback(guess, secret_number);
        } while (guess != secret_number);

        if (guess == secret_number) {
            printf("Congratulations! Would you like to play again? (Y/N): ");
            scanf(" %c", &play_again);
        } else {
            play_again = 'N'; // Ends the game if they quit
        }

    } while (play_again == 'Y' || play_again == 'y');

    printf("Thank you for playing the Happy Number Guessing Game! Have a wonderful day!\n");

    return 0;
}