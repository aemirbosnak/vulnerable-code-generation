//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator;
    char operation;
    int result;

    // Initialize random seed
    srand(time(NULL));

    // Generate random numbers
    num1 = rand() % 100;
    num2 = rand() % 100;

    // Generate random operator
    switch (rand() % 4) {
        case 0:
            operation = '+';
            break;
        case 1:
            operation = '-';
            break;
        case 2:
            operation = '*';
            break;
        case 3:
            operation = '/';
            break;
    }

    // Get user input for operator
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    // Perform arithmetic operation
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator\n");
            return 1;
    }

    // Print result
    printf("Result: %d\n", result);

    return 0;
}