//FormAI DATASET v1.0 Category: Educational ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int generateRandomNum(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int main() {
    int secretNum = generateRandomNum(1, 100);
    int attemptsLeft = 10;
    int guess, i;
    char name[20];

    printf("Welcome to the Guessing Game!\n");
    printf("What is your name? ");
    scanf("%s", name);

    printf("\nHello %s, I am thinking of a number between 1 and 100. You have 10 attempts to guess it.\n", name);

    while (attemptsLeft > 0) {
        printf("\nAttempts left: %d\n", attemptsLeft);
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Invalid input. Please enter a number between 1 and 100.\n");
            continue;
        }

        if (guess > secretNum) {
            printf("Too high! Try again.\n");
        } else if (guess < secretNum) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations %s! You guessed the secret number in %d attempt", name, 10 - attemptsLeft + 1);
            if (attemptsLeft == 1) {
                printf(". You are truly a master of this game!");
            } else {
                printf("s. Nice job!");
            }
            break;
        }
        attemptsLeft--;
    }

    if (attemptsLeft == 0) {
        printf("\nSorry %s, you have used all your attempts. The secret number was %d. Better luck next time!\n", name, secretNum);
    }
    return 0;
}