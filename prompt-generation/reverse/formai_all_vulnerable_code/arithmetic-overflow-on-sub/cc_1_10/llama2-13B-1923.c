//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MIN_VALUE -1000
#define MAX_VALUE 1000

int main() {
    int num1, num2, sum, product, quotient, remainder;
    char op1, op2;
    char str1[MAX_STRING_LENGTH], str2[MAX_STRING_LENGTH];

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op1);

    // Get the second operand from the user
    printf("Enter the second operand: ");
    scanf(" %c", &op2);

    // Perform the operation
    if (op1 == '+') {
        sum = num1 + num2;
    } else if (op1 == '-') {
        sum = num1 - num2;
    } else if (op1 == '*') {
        product = num1 * num2;
    } else if (op1 == '/') {
        quotient = num1 / num2;
        remainder = num1 % num2;
    }

    // Print the result
    printf("Result: %d\n", sum);

    // Print the remainder
    if (op2 == '/') {
        printf("Remainder: %d\n", remainder);
    }

    // Print the product
    if (op1 == '*') {
        printf("Product: %d\n", product);
    }

    // Print the quotient
    if (op1 == '/') {
        printf("Quotient: %d\n", quotient);
    }

    return 0;
}