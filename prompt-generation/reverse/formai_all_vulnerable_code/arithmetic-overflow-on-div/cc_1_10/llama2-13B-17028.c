//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 1000
#define MIN_NUM -1000

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    char operation[10];

    printf("Welcome to the Arithmetic Playground! Please enter two numbers and an operation (+, -, x, /, or %).\n");

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, x, /, or %): ");
    scanf(" %c", &operation[0]);

    // Perform the operation
    switch (operation[0]) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            difference = num1 - num2;
            break;
        case '*':
            product = num1 * num2;
            break;
        case '/':
            quotient = num1 / num2;
            remainder = num1 % num2;
            break;
        case '%':
            remainder = num1 % num2;
            quotient = num1 / num2;
            break;
        default:
            printf("Invalid operation! Please try again.");
            return 1;
    }

    // Print the results
    printf("The result of %d %c %d is: %d\n", num1, operation[0], num2, sum);

    // Check if the result is within the valid range
    if (sum < MIN_NUM || sum > MAX_NUM) {
        printf("The result is out of range! Please try again.");
        return 1;
    }

    // Print the remainder
    if (operation[0] == '/') {
        printf("The remainder is: %d\n", remainder);
    }

    return 0;
}