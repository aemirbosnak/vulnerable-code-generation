//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    srand(time(NULL));
    int num1, num2, sum;
    char operation;

    printf("Welcome to the Innovative Arithmetic Adventure!\n");

    // Initialize variables
    num1 = rand() % 100;
    num2 = rand() % 100;
    operation = '+';

    // Display the numbers and operation
    printf("Your adventure begins with the numbers %d and %d, and the operation %c.\n", num1, num2, operation);

    // Start the adventure
    while (operation != 'S' && operation != 'E') {
        // Perform the operation
        switch (operation) {
            case '+':
                sum = num1 + num2;
                break;
            case '-':
                sum = num1 - num2;
                break;
            case '*':
                sum = num1 * num2;
                break;
            case '/':
                sum = num1 / num2;
                break;
            default:
                printf("Invalid operation! Try again.\n");
                operation = '+';
                break;
        }

        // Display the result
        printf("Your result is %d.\n", sum);

        // Ask the user for the next operation
        printf("Would you like to add, subtract, multiply, or divide? (type 'S' for subtract, 'E' for exit): ");
        scanf(" %c", &operation);
    }

    // Exit the adventure
    printf("Thank you for playing the Innovative Arithmetic Adventure! The magic number was %d.\n", MAGIC_NUMBER);
    return 0;
}