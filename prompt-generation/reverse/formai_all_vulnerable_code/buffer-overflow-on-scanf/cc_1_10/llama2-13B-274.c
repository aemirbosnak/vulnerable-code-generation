//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char op;

    // Initialize variables
    num1 = 5;
    num2 = 10;
    sum = 0;
    op = '+';

    // Get the first operator from the user
    printf("Enter the first operator (+, -, *, /): ");
    scanf("%c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == '*') {
        sum = num1 * num2;
    } else if (op == '/') {
        sum = num1 / num2;
    }

    // Print the result
    printf("Result: %d\n", sum);

    // Get the second operator from the user
    printf("Enter the second operator (+, -, *, /): ");
    scanf("%c", &op);

    // Perform the operation again
    if (op == '+') {
        sum = sum + num2;
    } else if (op == '-') {
        sum = sum - num2;
    } else if (op == '*') {
        sum = sum * num2;
    } else if (op == '/') {
        sum = sum / num2;
    }

    // Print the final result
    printf("Final result: %d\n", sum);

    // Add some magic to the program
    if (sum == MAGIC_NUMBER) {
        printf("Congratulations! You have found the secret magic number %d!\n", MAGIC_NUMBER);
    }

    return 0;
}