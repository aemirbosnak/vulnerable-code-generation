//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 100000
#define MIN_NUM 1

int main() {
    int num1, num2, sum, diff, mult, div, mod;
    char op;
    char str[50];

    printf("Welcome to the Automated Arithmetic Program!\n");

    do {
        printf("Enter a math operation (+, -, x, /, %): ");
        scanf(" %c", &op);

        if (op == '+') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            sum = num1 + num2;
            printf("The sum of %d and %d is %d\n", num1, num2, sum);
        } else if (op == '-') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            diff = num1 - num2;
            printf("The difference of %d and %d is %d\n", num1, num2, diff);
        } else if (op == '*') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            mult = num1 * num2;
            printf("The product of %d and %d is %d\n", num1, num2, mult);
        } else if (op == '/') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            if (num2 == 0) {
                printf("Error: cannot divide by zero\n");
            } else {
                div = num1 / num2;
                printf("The quotient of %d and %d is %d\n", num1, num2, div);
            }
        } else if (op == '%') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            mod = num1 % num2;
            printf("The remainder of %d and %d is %d\n", num1, num2, mod);
        } else {
            printf("Invalid operation\n");
        }
    } while (1);

    return 0;
}