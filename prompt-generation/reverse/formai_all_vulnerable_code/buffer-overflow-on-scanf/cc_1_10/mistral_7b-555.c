//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEED 13
#define MIN 1
#define MAX 100
#define TRIES 10

void srandinit() {
    unsigned long seed = SEED;
    unsigned long i;

    for (i = 0; i < 10; i++)
        seed = (seed * 1103515245 + 12345) % 2147483647;

    srand(seed);
}

int generate_random_number() {
    int number = MIN + (rand() % (MAX - MIN + 1));
    return number;
}

int main() {
    int number, guess, tries = TRIES;

    srandinit();
    number = generate_random_number();

    printf("Welcome to the Number Guessing Game!\n");
    printf("I've generated a random number between 1 and 100.\n");
    printf("You have %d tries to guess it.\n\n", TRIES);

    do {
        printf("Your guess: ");
        scanf("%d", &guess);

        if (guess == number) {
            printf("Congratulations! You guessed the number correctly.\n");
            break;
        }

        if (guess < number) {
            printf("Too Low! Try again.\n");
        } else {
            printf("Too High! Try again.\n");
        }

        tries--;
        printf("You have %d tries left.\n", tries);

    } while (tries > 0);

    if (tries == 0) {
        printf("Sorry, you didn't guess the number within %d tries.\n", TRIES);
        printf("The correct number was %d.\n", number);
    }

    return 0;
}