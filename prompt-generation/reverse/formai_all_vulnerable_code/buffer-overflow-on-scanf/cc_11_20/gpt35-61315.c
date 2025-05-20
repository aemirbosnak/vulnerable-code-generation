//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Setup
    srand(time(NULL));
    int nums[10];
    int num1, num2, attempts = 0;

    // Generate random numbers and populate array
    for (int i = 0; i < 10; i++) {
        nums[i] = rand() % 100 + 1; // Random number between 1-100 
    }

    // Prompt user for input and validate
    printf("Enter two distinct numbers between 1-10:\n");
    while (1) {
        scanf("%d %d", &num1, &num2);
        if ((num1 < 1 || num1 > 10) || (num2 < 1 || num2 > 10) || (num1 == num2)) {
            printf("Invalid input. Enter two distinct numbers between 1-10:\n");
        } else {
            break;
        }
    }

    // Compute sum and average of numbers in array between user input indices
    int sum = 0, count = 0;
    for (int i = 0; i < 10; i++) {
        if ((i >= num1 - 1 && i <= num2 - 1) || (i >= num2 - 1 && i <= num1 - 1)) {
            sum += nums[i];
            count++;
        }
    }
    float avg = (float) sum / count;

    // Prompt user for guess
    printf("Guess the average of the numbers between %d and %d:\n", num1, num2);
    float guess;
    while (1) {
        scanf("%f", &guess);
        if (guess == avg) {
            printf("Congratulations! You guessed the correct average in %d attempt(s).\n", attempts);
            break;
        } else {
            if (attempts == 2) {
                printf("Sorry, you have run out of attempts. The correct average is %.2f.\n", avg);
                break;
            } else if (guess > avg) {
                printf("Your guess is too high. Please try again:\n");
            } else {
                printf("Your guess is too low. Please try again:\n");
            }
            attempts++;
        }
    }

    return 0;
}