//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 100000
#define MIN_NUMBER -100000

int main() {
    int num1, num2, sum, diff, mult, div, mod;
    char op;

    printf("Welcome to the Arithmetic Program!\n");

    do {
        printf("Enter the first number: ");
        scanf("%d", &num1);

        printf("Enter the second number: ");
        scanf("%d", &num2);

        printf("Enter the operation (+, -, *, /, %): ");
        scanf(" %c", &op);

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
            default:
                printf("Invalid operation. Please try again.\n");
                break;
        }

        printf("Result: %d\n", sum);
        printf("Result: %d\n", diff);
        printf("Result: %d\n", mult);
        printf("Result: %d\n", div);
        printf("Result: %d\n", mod);

    } while (1);

    return 0;
}