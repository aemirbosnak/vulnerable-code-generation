//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, difference, quotient, remainder;
    char op;

    printf("Welcome to the Arithmetic Playground!\n");

    do {
        printf("Enter two numbers: ");
        scanf("%d%c", &num1, &op);

        if (op == '+') {
            printf("Addition: ");
            sum = num1 + getRandomNumber();
            printf("%d + %d = %d\n", num1, getRandomNumber(), sum);
        } else if (op == '-') {
            printf("Subtraction: ");
            difference = num1 - getRandomNumber();
            printf("%d - %d = %d\n", num1, getRandomNumber(), difference);
        } else if (op == '*') {
            printf("Multiplication: ");
            product = num1 * getRandomNumber();
            printf("%d x %d = %d\n", num1, getRandomNumber(), product);
        } else if (op == '/') {
            printf("Division: ");
            quotient = num1 / getRandomNumber();
            remainder = num1 % getRandomNumber();
            printf("%d / %d = %d remainder %d\n", num1, getRandomNumber(), quotient, remainder);
        } else if (op == '^') {
            printf("Exponentiation: ");
            int pow = getRandomNumber();
            int result = pow * pow;
            printf("%d^%d = %d\n", num1, pow, result);
        } else {
            printf("Invalid operator. Try again.\n");
        }
    } while (1);

    return 0;
}

int getRandomNumber() {
    int num = (rand() % 100) + 1;
    return num;
}