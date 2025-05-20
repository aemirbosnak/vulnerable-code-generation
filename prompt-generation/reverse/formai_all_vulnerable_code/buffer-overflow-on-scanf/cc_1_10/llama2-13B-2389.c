//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MOD 1000003

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;

    // Initialize variables
    num1 = 42;
    num2 = 21;
    sum = 0;
    diff = 0;
    mult = 1;
    div = 1;

    // Get operator from user
    printf("Enter an arithmetic operator (+, -, *, /): ");
    scanf("%c", &op);

    // Perform arithmetic operations
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        diff = num1 - num2;
    } else if (op == '*') {
        mult = num1 * num2;
    } else if (op == '/') {
        div = num1 / num2;
    }

    // Modular arithmetic
    if (mod(sum, MOD) != 0) {
        sum = (sum + MOD) % MOD;
    }
    if (mod(diff, MOD) != 0) {
        diff = (diff + MOD) % MOD;
    }
    if (mod(mult, MOD) != 0) {
        mult = (mult + MOD) % MOD;
    }
    if (mod(div, MOD) != 0) {
        div = (div + MOD) % MOD;
    }

    // Print results
    printf("Result of %d + %d = %d\n", num1, num2, sum);
    printf("Result of %d - %d = %d\n", num1, num2, diff);
    printf("Result of %d * %d = %d\n", num1, num2, mult);
    printf("Result of %d / %d = %d\n", num1, num2, div);

    return 0;
}

// Modular functions
int mod(int x, int n) {
    return x % n;
}