//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER 1000
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, diff, mult, div;
    char operation[5];
    char magic[5];

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    diff = 0;
    mult = 0;
    div = 0;

    // Read the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Read the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Read the operation
    printf("Enter the operation (+, -, *, /): ");
    scanf("%s", operation);

    // Read the magic number
    printf("Enter the magic number (42): ");
    scanf("%d", &magic[0]);

    // Perform the operation
    if (strcmp(operation, "+") == 0) {
        sum = num1 + num2;
    } else if (strcmp(operation, "-") == 0) {
        diff = num1 - num2;
    } else if (strcmp(operation, "*") == 0) {
        mult = num1 * num2;
    } else if (strcmp(operation, "/") == 0) {
        div = num1 / num2;
    }

    // Print the result
    printf("Result: %d\n", sum);

    // Print the magic message
    printf("Magic number: %d\n", magic[0]);

    return 0;
}