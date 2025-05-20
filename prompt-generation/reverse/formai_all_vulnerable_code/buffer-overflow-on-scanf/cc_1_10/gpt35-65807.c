//FormAI DATASET v1.0 Category: Random ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, guess, userGuessCount = 0;
    int upperLimit, lowerLimit;

    printf("Welcome to the random number guessing game!\n");
    printf("Enter the upper limit of the range: ");
    scanf("%d", &upperLimit);
    printf("Enter the lower limit of the range: ");
    scanf("%d", &lowerLimit);

    srand(time(0));
    num1 = (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit;
    num2 = (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit;

    printf("I have generated two random numbers between %d and %d. Can you guess what they are?\n", lowerLimit, upperLimit);

    do {
        printf("Guess the first number: ");
        scanf("%d", &guess);
        userGuessCount++;

        if (guess == num1) {
            printf("Correct! You guessed the first number %d in %d attempts.\n", num1, userGuessCount);
        } else if (guess > num1) {
            printf("Your guess is too high. Try again.\n");
        } else {
            printf("Your guess is too low. Try again.\n");
        }
    } while(guess != num1);

    userGuessCount = 0;

    do {
        printf("Guess the second number: ");
        scanf("%d", &guess);
        userGuessCount++;

        if (guess == num2) {
            printf("Correct! You guessed the second number %d in %d attempts.\n", num2, userGuessCount);
        } else if (guess > num2) {
            printf("Your guess is too high. Try again.\n");
        } else {
            printf("Your guess is too low. Try again.\n");
        }
    } while(guess != num2);

    printf("Congratualations! You guessed both numbers correctly in a total of %d attempts!\n", userGuessCount);
    return 0;
}