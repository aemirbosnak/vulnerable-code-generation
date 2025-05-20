//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

void math_madness(int num1, int num2, int op) {
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
        case '^':
            result = num1 ^ num2;
            break;
        default:
            result = num1 + num2; // just in case
            break;
    }
    printf("Result of %d %c %d = %d\n", num1, op, num2, result);
}

int main() {
    srand(time(NULL));
    int num1, num2, op;

    do {
        printf("Enter a number: ");
        scanf("%d", &num1);
        printf("Enter another number: ");
        scanf("%d", &num2);
        printf("Enter an operation (+, -, *, /, % or ^): ");
        scanf(" %c", &op);

        math_madness(num1, num2, op);
    } while (1);

    return 0;
}