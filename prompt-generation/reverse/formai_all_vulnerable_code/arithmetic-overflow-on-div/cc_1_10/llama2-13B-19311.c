//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, square, cube, difference, remainder;
    char operation;

    printf("Welcome to the Magic Arithmetic Machine!\n");

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the operation
    if (operation == '+') {
        sum = num1 + num2;
    } else if (operation == '-') {
        difference = num1 - num2;
    } else if (operation == '*') {
        product = num1 * num2;
    } else if (operation == '/') {
        remainder = num1 / num2;
        if (num2 == 0) {
            printf("Error: division by zero!\n");
            return 1;
        }
    } else {
        printf("Invalid operation. Please try again.\n");
        return 1;
    }

    // Calculate the square and cube of the numbers
    square = num1 * num1;
    cube = num1 * num1 * num1;

    // Print the results
    printf("The result of %d %c %d is %d\n", num1, operation, num2, sum);
    printf("The square of %d is %d\n", num1, square);
    printf("The cube of %d is %d\n", num1, cube);

    // Check if the result is magical
    if (sum == MAGIC_NUMBER) {
        printf("Congratulations! You have found the magical result %d\n", sum);
    } else {
        printf("Unfortunately, the result is not magical. Better luck next time!\n");
    }

    return 0;
}