//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM 100
#define MAX_OPERATIONS 5

// Function to perform mathematical operations
void do_math(int num1, int num2, char operation) {
    int result;

    switch (operation) {
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
            printf("Invalid operation\n");
            return;
    }

    printf("Result: %d\n", result);
}

int main() {
    int num1, num2, operations;
    char operation[MAX_OPERATIONS];

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the mathematical operations from the user
    printf("Enter the mathematical operations (separated by commas): ");
    scanf("%s", operation);

    // Perform the mathematical operations
    do_math(num1, num2, operation[0]);

    return 0;
}