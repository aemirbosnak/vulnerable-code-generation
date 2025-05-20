//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int num1, num2;
    char operation;

    // Take input from user
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operation (+, -, *, /, ^, &, |, <<, >>): ");
    scanf(" %c", &operation);

    // Perform the operation
    switch (operation) {
        case '+':
            printf("The sum is: %d\n", num1 + num2);
            break;
        case '-':
            printf("The difference is: %d\n", num1 - num2);
            break;
        case '*':
            printf("The product is: %d\n", num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error! Division by zero.\n");
            } else {
                printf("The quotient is: %d\n", num1 / num2);
            }
            break;
        case '^':
            printf("The bitwise XOR is: %d\n", num1 ^ num2);
            break;
        case '&':
            printf("The bitwise AND is: %d\n", num1 & num2);
            break;
        case '|':
            printf("The bitwise OR is: %d\n", num1 | num2);
            break;
        case '<':
            printf("The left shift is: %d\n", num1 << num2);
            break;
        case '>':
            printf("The right shift is: %d\n", num1 >> num2);
            break;
        default:
            printf("Invalid operation!\n");
    }

    return 0;
}