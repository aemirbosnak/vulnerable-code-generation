//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, difference, quotient, remainder;
    char operation[5];

    // Ask the user for the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Ask the user for the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Ask the user for the operation
    printf("Enter the operation (+, -, x, /): ");
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
        default:
            printf("Invalid operation\n");
            return 1;
    }

    // Print the result
    printf("Result: %d\n", sum);

    // Generate a magic number
    int magic = (num1 + num2 + MAGIC_NUMBER) % 10;

    // Print the magic number
    printf("Magic number: %d\n", magic);

    // Check if the result is a magic number
    if (magic == MAGIC_NUMBER) {
        printf("Congratulations! You have found the magic number!\n");
    } else {
        printf("Bummer! The result is not a magic number.\n");
    }

    return 0;
}