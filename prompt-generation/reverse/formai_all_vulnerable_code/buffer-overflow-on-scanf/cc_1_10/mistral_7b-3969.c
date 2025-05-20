//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MY_SECRET 7
#define NUM_TRIES 5
#define MY_NAME "The Mysterious One"

int main() {
    srand(time(NULL));

    printf("\n\t\t**** Welcome to %s's Table Game ****\n\n", MY_NAME);
    printf("\t\tI've got a secret number between 0 and 10.\n");
    printf("\t\tCan you guess it?\n\n");

    int guess, secret = MY_SECRET;
    int tries = 0;

    while (tries < NUM_TRIES) {
        printf("\t\tYour turn %d. Enter your guess: ", tries + 1);
        scanf("%d", &guess);

        if (guess < secret)
            printf("\t\tToo low! Try again.\n");
        else if (guess > secret)
            printf("\t\tToo high! Try again.\n");
        else {
            printf("\t\tCongratulations! You've guessed the number %d correctly.\n", secret);
            break;
        }

        tries++;

        // Add some unexpected twists
        if (tries == NUM_TRIES - 1) {
            secret = rand() % 11;
            printf("\t\tI've changed the number. Try again.\n");
        } else if (guess == secret) {
            printf("\t\tWow! You've guessed the number %d correctly in %d tries.\n", secret, tries + 1);
            printf("\t\tBut wait! There's more...\n");
            printf("\t\tI've got another secret number between 0 and 10. Can you guess it?\n");
            secret = rand() % 11;
            tries = 0;
        }
    }

    if (tries == NUM_TRIES) {
        printf("\t\tSorry, you couldn't guess the number %d in %d tries.\n", secret, NUM_TRIES);
        printf("\t\tBetter luck next time!\n");
    }

    return 0;
}