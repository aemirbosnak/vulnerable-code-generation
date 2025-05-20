//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int num1, num2, operator, result;
    char choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize the numbers and operator
    num1 = generateRandomNumber(1, 100);
    num2 = generateRandomNumber(1, 100);
    operator = generateRandomNumber(1, 4);

    // Perform the arithmetic operation
    switch (operator) {
        case 1:
            result = num1 + num2;
            printf("The sum of %d and %d is %d.\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("The difference between %d and %d is %d.\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("The product of %d and %d is %d.\n", num1, num2, result);
            break;
        case 4:
            if (num2 == 0) {
                printf("Cannot divide by zero!\n");
            } else {
                result = num1 / num2;
                printf("The quotient of %d and %d is %d.\n", num1, num2, result);
            }
            break;
    }

    // Ask the user if they want to try again
    printf("Do you want to try again? (Y/N): ");
    scanf(" %c", &choice);

    // Repeat until the user chooses to quit
    while (choice == 'Y' || choice == 'y') {
        main();
    }

    return 0;
}