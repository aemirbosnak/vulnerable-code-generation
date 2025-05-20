//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// Function to print binary representation of a number
void printBinary(unsigned int num) {
    int i;
    for (i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    unsigned int num1, num2, result;
    char operation;

    // Get user input for two numbers and an operation
    printf("Enter two numbers and an operation (+, -, *, /, &, |, ^, <<, >>): ");
    scanf("%u %c %u", &num1, &operation, &num2);

    // Perform the operation and print the result
    switch (operation) {
        case '+':
            result = num1 + num2;
            printf("Result: %u\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %u\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %u\n", result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                result = num1 / num2;
                printf("Result: %u\n", result);
            }
            break;
        case '&':
            result = num1 & num2;
            printf("Result: %u (binary: ", result);
            printBinary(result);
            printf(")\n");
            break;
        case '|':
            result = num1 | num2;
            printf("Result: %u (binary: ", result);
            printBinary(result);
            printf(")\n");
            break;
        case '^':
            result = num1 ^ num2;
            printf("Result: %u (binary: ", result);
            printBinary(result);
            printf(")\n");
            break;
        case '<':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                result = num1 << num2;
                printf("Result: %u (binary: ", result);
                printBinary(result);
                printf(")\n");
            }
            break;
        case '>':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                result = num1 >> num2;
                printf("Result: %u (binary: ", result);
                printBinary(result);
                printf(")\n");
            }
            break;
        default:
            printf("Error: Invalid operation\n");
    }

    return 0;
}