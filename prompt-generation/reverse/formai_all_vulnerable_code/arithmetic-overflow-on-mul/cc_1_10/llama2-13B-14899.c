//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MOD 1000003

// Function to perform arithmetic operations
void do_arithmetic(int num1, int num2, int op) {
    int result;

    switch (op) {
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
            result = num1 / num2;
            break;
        default:
            result = -1;
            break;
    }

    printf("Result: %d\n", result);
}

int main() {
    int num1, num2, op;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the arithmetic operator from the user
    printf("Enter the arithmetic operator (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the arithmetic operation
    do_arithmetic(num1, num2, op);

    return 0;
}