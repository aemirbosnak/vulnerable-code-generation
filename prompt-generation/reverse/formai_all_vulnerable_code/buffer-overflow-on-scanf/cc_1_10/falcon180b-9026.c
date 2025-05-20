//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10
#define MAX_ATTEMPTS 5

int generateRandomNumber(int min, int max);
int playGame(int number, int attempts);

int main() {
    srand(time(NULL));

    int userNumber;
    printf("Enter a number between 1 and 100: ");
    scanf("%d", &userNumber);

    printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        int randomNumber = generateRandomNumber(1, 100);
        attempts++;
        int result = playGame(randomNumber, attempts);
        if (result == 1) {
            printf("Congratulations, you guessed the number in %d attempts!\n", attempts);
            break;
        } else if (result == -1) {
            printf("Sorry, you're out of attempts. The number was %d.\n", randomNumber);
            break;
        }
    }

    return 0;
}

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int playGame(int number, int attempts) {
    printf("Guess a number between 1 and %d: ", number);
    int userGuess;
    scanf("%d", &userGuess);

    if (userGuess == number) {
        return 1;
    } else if (userGuess < number) {
        printf("Too low. Try again.\n");
    } else {
        printf("Too high. Try again.\n");
    }

    return 0;
}