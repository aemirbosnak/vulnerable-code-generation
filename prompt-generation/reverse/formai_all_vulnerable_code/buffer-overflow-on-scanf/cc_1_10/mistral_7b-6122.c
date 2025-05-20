//MISTRAL-7B DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100

void print_menu() {
    printf("\n*****************************************\n");
    printf("* Welcome to the Number Guessing Game!      *\n");
    printf("*****************************************\n");
    printf("* The computer will randomly select a number *\n");
    printf("* between %d and %d.                       *\n", MIN_NUMBER, MAX_NUMBER);
    printf("* Your goal is to guess the number.         *\n");
    printf("* You have 10 chances to guess.             *\n");
    printf("* Good luck!                               *\n");
}

int generate_random_number() {
    return rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

int main() {
    int number_to_guess, guess, attempts = 0;
    srand(time(NULL));

    print_menu();

    number_to_guess = generate_random_number();

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else if (guess > number_to_guess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        }
    } while (attempts < 10);

    if (attempts == 10) {
        printf("Sorry, you did not guess the number within the given attempts.\n");
        printf("The number was %d.\n", number_to_guess);
    }

    return 0;
}