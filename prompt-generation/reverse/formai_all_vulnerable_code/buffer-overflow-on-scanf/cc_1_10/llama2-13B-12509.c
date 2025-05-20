//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PRINT_MAX 100

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;

    printf("Welcome to the C Math Exercise!\n");

    do {
        printf("Enter a math operation (+, -, *, /, or ^): ");
        scanf(" %c", &op);

        if (op == '+') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            sum = num1 + num2;
            printf("The sum of %d and %d is %d.\n", num1, num2, sum);
        } else if (op == '-') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            diff = num1 - num2;
            printf("The difference of %d and %d is %d.\n", num1, num2, diff);
        } else if (op == '*') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            mult = num1 * num2;
            printf("The product of %d and %d is %d.\n", num1, num2, mult);
        } else if (op == '/') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            if (num2 == 0) {
                printf("Error: cannot divide by zero!\n");
            } else {
                div = num1 / num2;
                printf("The quotient of %d and %d is %d.\n", num1, num2, div);
            }
        } else if (op == '^') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            if (num2 == 0) {
                printf("Error: cannot raise to zero!\n");
            } else {
                mult = num1 ^ num2;
                printf("The result of raising %d to the power of %d is %d.\n", num1, num2, mult);
            }
        } else {
            printf("Invalid operation. Please try again.\n");
        }
    } while (op != 'q');

    return 0;
}