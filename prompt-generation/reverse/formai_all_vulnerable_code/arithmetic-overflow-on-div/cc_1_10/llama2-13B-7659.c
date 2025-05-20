//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

void math_exercise(int num1, int num2, int op) {
    int result;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '%':
            result = num1 % num2;
            break;
        default:
            result = MAGIC_NUMBER;
            break;
    }

    printf("Result: %d\n", result);
}

int main() {
    int num1, num2, op;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the operation (+, -, *, /, or %): ");
    scanf(" %c", &op);

    math_exercise(num1, num2, op);

    return 0;
}