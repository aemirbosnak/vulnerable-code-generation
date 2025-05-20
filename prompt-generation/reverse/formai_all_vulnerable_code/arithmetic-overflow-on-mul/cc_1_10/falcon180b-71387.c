//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 1000

int main() {
    int num1, num2, result;
    char operation;
    bool isError = false;

    printf("Welcome to the Funny Math Calculator!\n");
    printf("Please enter two numbers separated by an operator:\n");
    printf("Valid operators are +, -, *, and /\n");
    scanf("%d %c %d", &num1, &operation, &num2);

    switch (operation) {
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
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                isError = true;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            isError = true;
            break;
    }

    if (!isError) {
        printf("Result: %d\n", result);
    }

    return 0;
}