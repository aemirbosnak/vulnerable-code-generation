//Falcon-180B DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int i, randomNum, num, guess;
    char choice;

    srand(time(NULL));

    printf("Welcome to the Guessing Game!\n");
    printf("I am thinking of a number between 1 and %d.\n", MAX_SIZE);

    randomNum = rand() % MAX_SIZE + 1;

    printf("Can you guess my number? (y/n)\n");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("Great! Let's play!\n");

        for (i = 0; i < MAX_SIZE; i++) {
            arr[i] = 0;
        }

        printf("You have %d guesses left.\n", MAX_SIZE);

        while (1) {
            printf("Guess a number: ");
            scanf("%d", &num);

            if (num == randomNum) {
                printf("Congratulations! You guessed my number in %d guesses.\n", MAX_SIZE - i);
                break;
            } else if (num < 1 || num > MAX_SIZE) {
                printf("Invalid input. Please try again.\n");
            } else if (arr[num - 1] == 1) {
                printf("You already guessed %d. Guess again.\n", num);
            } else {
                if (i == MAX_SIZE - 1) {
                    printf("Sorry, you ran out of guesses. The number was %d.\n", randomNum);
                    break;
                } else {
                    arr[num - 1] = 1;
                    i++;
                }
            }
        }
    } else {
        printf("Okay, maybe next time.\n");
    }

    return 0;
}