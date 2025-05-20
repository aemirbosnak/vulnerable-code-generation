//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, quotient, remainder;
    char op;

    printf("Welcome to the Scalable Arithmetic Adventure!\n");

    do {
        printf("Enter two numbers and an operation (+, -, *, /): ");
        scanf("%d%c%d", &num1, &op, &num2);

        if (op == '+') {
            sum = num1 + num2;
        } else if (op == '-') {
            sum = num1 - num2;
        } else if (op == '*') {
            product = num1 * num2;
        } else if (op == '/') {
            quotient = num1 / num2;
            remainder = num1 % num2;
        }

        printf("The result of %d %c %d is %d\n", num1, op, num2, sum);

    } while (op != 'q');

    return 0;
}

// utility functions
int is_magic(int num) {
    return num == MAGIC_NUMBER;
}

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

void print_magic(int num) {
    if (is_magic(num)) {
        printf("Oh my, you found the magic number %d!\n", num);
    }
}