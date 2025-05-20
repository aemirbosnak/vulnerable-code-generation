//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator;
    char repeat;

    // Initialize random seed
    srand(time(NULL));

    // Loop until user wants to quit
    do {
        // Generate random numbers
        num1 = rand() % 100;
        num2 = rand() % 100;

        // Generate random operator
        operator = rand() % 4;

        // Perform arithmetic operation
        switch (operator) {
            case 0: // Addition
                printf("Enter the result of %d + %d: ", num1, num2);
                break;
            case 1: // Subtraction
                printf("Enter the result of %d - %d: ", num1, num2);
                break;
            case 2: // Multiplication
                printf("Enter the result of %d * %d: ", num1, num2);
                break;
            case 3: // Division
                printf("Enter the result of %d / %d: ", num1, num2);
                break;
        }

        // Get user input
        scanf("%d", &num1);

        // Check if answer is correct
        if (num1 == (num2 + operator)) {
            printf("Correct!\n");
        } else {
            printf("Incorrect, the correct answer is %d.\n", num2 + operator);
        }

        // Ask user if they want to continue
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}