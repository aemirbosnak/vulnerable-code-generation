//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 100

void generateNumber() {
    int secretNumber;
    srand(time(NULL));
    secretNumber = rand() % (MAX - MIN + 1) + MIN;
    printf("The secret number is: %d\n", secretNumber);
}

int main() {
    int guess, numberOfGuesses = 0;
    int isGuessed = 0;

    printf("*** WELCOME TO THE NUMBER GUESSING GAME ***\n");
    printf("I have a secret number between 1 and 100. Can you guess it?\n");

    generateNumber();

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        numberOfGuesses++;

        if (guess < 0 || guess > MAX) {
            printf("Invalid guess! Please enter a number between 1 and 100.\n");
        } else {
            if (guess == getSecretNumber()) {
                isGuessed = 1;
                printf("Congratulations! You guessed the number correctly in %d attempts.\n", numberOfGuesses);
            } else {
                if (guess < getSecretNumber()) {
                    printf("Your guess is too low! Try again.\n");
                } else {
                    printf("Your guess is too high! Try again.\n");
                }
            }
        }
    } while (!isGuessed);

    return 0;
}

int getSecretNumber() {
    static int secretNumber;
    return secretNumber;
}