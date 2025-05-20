//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int num1, num2, operation;
    int result = 0;

    printf("Welcome to the Math Problem Generator!\n\n");

    // Generate two random numbers and an operation
    num1 = randomNumber(1, 100);
    num2 = randomNumber(1, 100);
    operation = randomNumber(1, 4);

    // Perform the operation and display the result
    switch (operation) {
        case 1: // Addition
            result = num1 + num2;
            printf("Solve for: %d + %d = ", num1, num2);
            break;
        case 2: // Subtraction
            result = num1 - num2;
            printf("Solve for: %d - %d = ", num1, num2);
            break;
        case 3: // Multiplication
            result = num1 * num2;
            printf("Solve for: %d * %d = ", num1, num2);
            break;
        case 4: // Division
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                return 1;
            }
            result = num1 / num2;
            printf("Solve for: %d / %d = ", num1, num2);
            break;
    }

    // Get the user's answer and compare it to the correct result
    int userAnswer;
    printf("Your answer: ");
    scanf("%d", &userAnswer);

    if (userAnswer == result) {
        printf("Correct! Great job!\n");
    } else {
        printf("Incorrect. The correct answer is: %d\n", result);
    }

    return 0;
}