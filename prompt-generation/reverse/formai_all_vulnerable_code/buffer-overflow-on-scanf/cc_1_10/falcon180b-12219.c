//Falcon-180B DATASET v1.0 Category: Educational ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, sum = 0;
    int count = 0;
    int max_count = 0;
    int min_count = 100; // Set a high number to start
    int num_guesses;

    srand(time(0)); // Seed the random number generator with the current time
    num1 = rand() % 100 + 1; // Generate a random number between 1 and 100
    num2 = rand() % 100 + 1;

    printf("Guess the sum of two numbers between 1 and 100.\n");
    printf("Number 1: %d\n", num1);
    printf("Number 2: %d\n", num2);

    while (count < 10) { // Allow the user 10 guesses
        printf("Enter your guess: ");
        scanf("%d", &num_guesses);
        sum = num1 + num2;

        if (num_guesses == sum) {
            printf("Congratulations! You guessed the correct sum in %d tries.\n", count + 1);
            break;
        } else if (num_guesses < sum) {
            printf("Too low. Guess again.\n");
        } else {
            printf("Too high. Guess again.\n");
        }

        count++;

        if (count == 1) {
            max_count = count;
            min_count = count;
        } else if (count > max_count) {
            max_count = count;
        } else if (count < min_count) {
            min_count = count;
        }
    }

    if (count == 10) {
        printf("Sorry, you ran out of guesses. The correct sum was %d.\n", sum);
    }

    return 0;
}