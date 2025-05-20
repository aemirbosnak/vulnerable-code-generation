//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int arr[SIZE];
    int sum = 0;
    int i, j, k;
    int num, guess;
    int tries = 0;

    srand(time(NULL)); // Initialize random seed with current time

    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100; // Fill array with random numbers between 0 and 99
        sum += arr[i]; // Calculate the sum of all elements in the array
    }

    printf("The sum of all elements in the array is: %d\n", sum);

    printf("Can you guess the sum of all elements in the array? (y/n): ");
    scanf(" %c", &num);

    if (num == 'y' || num == 'Y') {
        do {
            printf("Enter your guess: ");
            scanf("%d", &guess);

            if (guess < sum) {
                printf("Too low. Guess again.\n");
            } else if (guess > sum) {
                printf("Too high. Guess again.\n");
            }

            tries++;

            if (tries == 10) {
                printf("You ran out of tries. The correct answer was: %d\n", sum);
                exit(0);
            }

        } while (guess!= sum);

        printf("Congratulations! You guessed the correct sum in %d tries.\n", tries);
    } else {
        printf("Thanks for playing!\n");
    }

    return 0;
}