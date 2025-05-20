//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10
#define MIN_NUMBER 1
#define MAX_NUMBER 100

void clear_screen() {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int number, guess, tries = 0;
    srand(time(NULL));

    number = random_number(MIN_NUMBER, MAX_NUMBER);

    clear_screen();
    printf("Welcome to Number Guessing Game!\n");
    printf("I have selected a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
    printf("Try to guess it within %d attempts.\n\n", MAX_TRIES);

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        } else {
            clear_screen();
            printf("Congratulations! You guessed the number in %d attempts.\n", tries);
            break;
        }

        clear_screen();
    } while (tries < MAX_TRIES);

    if (tries == MAX_TRIES) {
        clear_screen();
        printf("Sorry, you couldn't guess the number within %d attempts.\n", MAX_TRIES);
        printf("The number was %d.\n", number);
    }

    return 0;
}