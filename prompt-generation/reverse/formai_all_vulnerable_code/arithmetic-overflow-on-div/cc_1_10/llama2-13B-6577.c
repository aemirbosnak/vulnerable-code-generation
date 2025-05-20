//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 100000
#define MIN_NUMBER 1

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

    // Get operator from user
    printf("Enter an arithmetic operation (+, -, *, /): ");
    scanf("%c", &op);

    // Get two numbers from user
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    // Perform arithmetic operation
    switch (op) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            diff = num1 - num2;
            break;
        case '*':
            mult = num1 * num2;
            break;
        case '/':
            div = num1 / num2;
            break;
        default:
            printf("Invalid operator\n");
            return 1;
    }

    // Print results
    printf("Result of %d + %d = %d\n", num1, num2, sum);
    printf("Result of %d - %d = %d\n", num1, num2, diff);
    printf("Result of %d * %d = %d\n", num1, num2, mult);
    printf("Result of %d / %d = %d\n", num1, num2, div);

    // Check for errors
    if (sum > MAX_NUMBER || sum < MIN_NUMBER) {
        printf("Error: result exceeds maximum value\n");
        return 2;
    }
    if (diff < 0) {
        printf("Error: result is negative\n");
        return 3;
    }
    if (mult == 0) {
        printf("Error: result is zero\n");
        return 4;
    }
    if (div == 0) {
        printf("Error: result is zero\n");
        return 5;
    }

    // Print success message
    printf("Arithmetic operations completed successfully\n");

    return 0;
}