//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 1000000
#define MAGIC_NUMBER 42

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
    fgets(operation, 10, stdin);
    operation[9] = '\0'; // Truncate the input string

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
            printf("Invalid operation. Please try again.\n");
            return 1;
    }

    // Print the results
    printf("Result of %c %d and %d: %d\n", operation[0], num1, num2, sum);

    // Generate a random magic number
    srand(time(NULL));
    int magic = MAGIC_NUMBER + (rand() % 100) - 50;

    // Check if the result is equal to the magic number
    if (sum == magic) {
        printf("Congratulations! You have found the magic number %d!", magic);
    } else {
        printf("Too bad, the result is not the magic number. Try again!\n");
    }

    return 0;
}