//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100
#define MIN_VALUE -100
#define MAX_VALUE 100

int main() {
    int num1, num2, sum, diff, mult, div, mod, pow;
    char op;

    printf("Welcome to Invasive Arithmetic! \n");

    // Initialize variables
    num1 = random() % MAX_VALUE + MIN_VALUE;
    num2 = random() % MAX_VALUE + MIN_VALUE;
    sum = 0;
    diff = 0;
    mult = 0;
    div = 0;
    mod = 0;
    pow = 0;

    // Get operator from user
    printf("Enter an arithmetic operator (+, -, *, /, %): ");
    scanf(" %c", &op);

    // Perform arithmetic operations
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
        case '%':
            mod = num1 % num2;
            break;
        case '^':
            pow = num1 ^ num2;
            break;
        default:
            printf("Invalid operator! \n");
            return 0;
    }

    // Print results
    printf("Result of %c %d %d: %d\n", op, num1, num2, sum);
    printf("Result of %c %d %d: %d\n", op, num1, num2, diff);
    printf("Result of %c %d %d: %d\n", op, num1, num2, mult);
    printf("Result of %c %d %d: %d\n", op, num1, num2, div);
    printf("Result of %c %d %d: %d\n", op, num1, num2, mod);
    printf("Result of %c %d %d: %d\n", op, num1, num2, pow);

    // Get another operator from user
    printf("Enter another operator (+, -, *, /, %): ");
    scanf(" %c", &op);

    // Perform another arithmetic operation
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
        case '%':
            mod = num1 % num2;
            break;
        case '^':
            pow = num1 ^ num2;
            break;
        default:
            printf("Invalid operator! \n");
            return 0;
    }

    // Print another result
    printf("Result of %c %d %d: %d\n", op, num1, num2, sum);

    return 0;
}