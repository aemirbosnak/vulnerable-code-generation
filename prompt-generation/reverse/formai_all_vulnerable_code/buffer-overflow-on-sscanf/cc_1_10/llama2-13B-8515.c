//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100000
#define MIN_NUM 1

int main() {
    int num1, num2, sum, diff, mult, div, mod;
    char op;
    char input[100];

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    diff = 0;
    mult = 0;
    div = 0;
    mod = 0;
    op = '+';

    // Get input from user
    printf("Enter the first number: ");
    fgets(input, 100, stdin);
    sscanf(input, "%d", &num1);

    printf("Enter the second number: ");
    fgets(input, 100, stdin);
    sscanf(input, "%d", &num2);

    // Perform arithmetic operations
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        diff = num1 - num2;
    } else if (op == '*') {
        mult = num1 * num2;
    } else if (op == '/') {
        div = num1 / num2;
    } else if (op == '^') {
        mod = num1 % num2;
    }

    // Print results
    printf("Result: %d\n", sum);
    printf("Diff: %d\n", diff);
    printf("Mult: %d\n", mult);
    printf("Div: %d\n", div);
    printf("Mod: %d\n", mod);

    return 0;
}