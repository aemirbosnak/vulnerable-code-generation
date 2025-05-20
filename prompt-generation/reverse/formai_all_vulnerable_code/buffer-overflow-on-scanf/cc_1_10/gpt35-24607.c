//FormAI DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>

int main() {
    // Welcome message
    printf("Welcome to the genius Bitwise Operations program!\n\n");

    // Variable declarations
    unsigned int num1, num2;
    char op;

    // Get user input
    printf("Enter the first integer: ");
    scanf("%u", &num1);
    printf("Enter the second integer: ");
    scanf("%u", &num2);
    printf("Enter the operation you want to perform (+, -, *, /, &, |, ^): ");
    scanf(" %c", &op);

    // Calculate bitwise operations based on user input
    switch (op) {
        case '+':
            printf("Result of bitwise OR operation: %u\n", num1 | num2);
            break;
        case '-':
            printf("Result of bitwise AND operation: %u\n", num1 & num2);
            break;
        case '*':
            printf("Result of bitwise XOR operation: %u\n", num1 ^ num2);
            break;
        case '/':
            printf("Result of left shift operation: %u\n", num1 << num2);
            break;
        case '&':
            printf("Result of right shift operation: %u\n", num1 >> num2);
            break;
        case '|':
            printf("Result of complement operation for integer 1: %u\n", ~num1);
            printf("Result of complement operation for integer 2: %u\n", ~num2);
            break;
        case '^':
            printf("Result of two's complement operation for integer 1: %u\n", ~(num1 - 1));
            printf("Result of two's complement operation for integer 2: %u\n", ~(num2 - 1));
            break;
        default:
            printf("Invalid operator! Please try again.\n");
            return 1;
    }

    // Closing message
    printf("\nThanks for using the genius Bitwise Operations program!");

    return 0;
}