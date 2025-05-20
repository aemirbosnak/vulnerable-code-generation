//MISTRAL-7B DATASET v1.0 Category: Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100

void generate_random_number(int *number) {
    *number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

void print_menu() {
    printf("**************************************************\n");
    printf("* Welcome to Number Guessing Game!                *\n");
    printf("* I have a secret number between 1 and 100.        *\n");
    printf("* Try to guess it!                                *\n");
    printf("* If you guess wrong, I'll tell you if it's higher *\n");
    printf("* or lower than your guess.                       *\n");
    printf("* Good luck!                                     *\n");
    printf("**************************************************\n");
}

int main() {
    int number, guess;
    int is_guessed = 0;

    srand(time(NULL));

    print_menu();

    generate_random_number(&number);

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < number) {
            printf("Your guess is too low. Try again.\n");
        } else if (guess > number) {
            printf("Your guess is too high. Try again.\n");
        }
    } while (guess != number && !is_guessed);

    if (guess == number && !is_guessed) {
        printf("Congratulations! You guessed the number correctly.\n");
        is_guessed = 1;
    }

    return 0;
}