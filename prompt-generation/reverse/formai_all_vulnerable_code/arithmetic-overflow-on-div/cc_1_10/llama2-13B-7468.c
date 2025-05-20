//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 1000000
#define MIN_NUMBER -1000000

int main() {
    int num1, num2, sum, diff, mult, div, mod;
    char op;

    printf("Welcome to the Arithmetic Game! \n");

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

    } while (num1 != 0 || num2 != 0);

    return 0;
}