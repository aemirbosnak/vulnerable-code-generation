//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100000
#define MIN_NUM -100000

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    diff = 0;
    mult = 0;
    div = 0;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        diff = num1 - num2;
    } else if (op == '*') {
        mult = num1 * num2;
    } else if (op == '/') {
        div = num1 / num2;
    }

    // Print the results
    printf("Result of %d %c %d = %d\n", num1, op, num2, sum);
    printf("Result of %d %c %d = %d\n", num1, op, num2, diff);
    printf("Result of %d %c %d = %d\n", num1, op, num2, mult);
    printf("Result of %d %c %d = %d\n", num1, op, num2, div);

    // Check if the results are within the valid range
    if (sum < MIN_NUM || sum > MAX_NUM) {
        printf("Invalid result for addition: %d\n", sum);
    }
    if (diff < MIN_NUM || diff > MAX_NUM) {
        printf("Invalid result for subtraction: %d\n", diff);
    }
    if (mult < MIN_NUM || mult > MAX_NUM) {
        printf("Invalid result for multiplication: %d\n", mult);
    }
    if (div < MIN_NUM || div > MAX_NUM) {
        printf("Invalid result for division: %d\n", div);
    }

    return 0;
}