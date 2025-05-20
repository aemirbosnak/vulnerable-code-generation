//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to the Intelligent Arithmetic Program!\n");

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == '*') {
        sum = num1 * num2;
    } else if (op == '/') {
        if (num2 == 0) {
            printf("Error: Division by zero!\n");
            return 1;
        }
        sum = num1 / num2;
    } else {
        printf("Invalid operation!\n");
        return 1;
    }

    // Print the result
    printf("The result of %d %c %d is %d\n", num1, op, num2, sum);

    // Get the user's input again
    printf("Would you like to perform another operation? (y/n): ");
    char input;
    scanf(" %c", &input);

    // Loop until the user says no
    while (input == 'y' || input == 'Y') {
        // Get the next number and operation
        printf("Enter the next number: ");
        scanf("%d", &num1);

        printf("Enter the next operation (+, -, *, /): ");
        scanf(" %c", &op);

        // Perform the operation
        if (op == '+') {
            sum = num1 + sum;
        } else if (op == '-') {
            sum = num1 - sum;
        } else if (op == '*') {
            sum = num1 * sum;
        } else if (op == '/') {
            if (sum == 0) {
                printf("Error: Division by zero!\n");
                return 1;
            }
            sum = num1 / sum;
        } else {
            printf("Invalid operation!\n");
            return 1;
        }

        // Print the result
        printf("The result of %d %c %d is %d\n", num1, op, sum, sum);

        // Get the user's input again
        printf("Would you like to perform another operation? (y/n): ");
        scanf(" %c", &input);
    }

    return 0;
}