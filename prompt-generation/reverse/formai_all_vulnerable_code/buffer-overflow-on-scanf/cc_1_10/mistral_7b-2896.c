//MISTRAL-7B DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess;

    // Initialize RNG and print surprise message
    srand(time(NULL));
    printf("\n***** SURPRISE! *****\n");
    printf("I'm thinking of a number between 1 and 10...\n");

    secretNumber = rand() % 10 + 1;

    // Game loop
    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        if (guess > secretNumber)
            printf("Too high! Try again.\n");
        else if (guess < secretNumber)
            printf("Too low! Try again.\n");
        else {
            printf("\n***** MIND BLOWN! *****\n");
            printf("You guessed it right! The number was %d.\n", secretNumber);

            // Print a surprising fact about the number
            switch (secretNumber) {
                case 1:
                    printf("Did you know that 1 is the smallest prime number?\n");
                    break;
                case 2:
                    printf("Did you know that 2 is the only even prime number?\n");
                    break;
                case 3:
                    printf("Did you know that 3 is the smallest odd prime number?\n");
                    break;
                case 5:
                    printf("Did you know that 5 is the smallest prime number that can be expressed as the sum of two cubes?\n");
                    break;
                case 7:
                    printf("Did you know that 7 is the only prime number that has an odd number of prime factors?\n");
                    break;
                default:
                    printf("Did you know that %d is a prime number?\n", secretNumber);
            }

            break;
        }
    } while (guess != secretNumber);

    return 0;
}