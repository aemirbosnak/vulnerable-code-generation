//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, difference, quotient, remainder;
    char operation[5];

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    product = 0;
    difference = 0;
    quotient = 0;
    remainder = 0;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf("%s", operation);

    // Perform the operation
    if (strcmp(operation, "+") == 0) {
        sum = num1 + num2;
    } else if (strcmp(operation, "-") == 0) {
        difference = num1 - num2;
    } else if (strcmp(operation, "*") == 0) {
        product = num1 * num2;
    } else if (strcmp(operation, "/") == 0) {
        quotient = num1 / num2;
        remainder = num1 % num2;
    }

    // Print the results
    printf("Result of %d %s %d: %d\n", num1, operation, num2, sum);
    printf("Result of %d %s %d: %d\n", num1, operation, num2, product);
    printf("Result of %d %s %d: %d\n", num1, operation, num2, difference);
    printf("Result of %d %s %d: %d\n", num1, operation, num2, quotient);
    printf("Result of %d %s %d: %d\n", num1, operation, num2, remainder);

    // Print some magic numbers
    printf("Magic number: %d\n", MAGIC_NUMBER);
    printf("Magic number squared: %d\n", MAGIC_NUMBER * MAGIC_NUMBER);

    return 0;
}