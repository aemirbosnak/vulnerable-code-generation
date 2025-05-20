//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    char operation;

    printf("Welcome to the Arithmetic Emporium!\n");

    do {
        printf("Please enter an operation (a, b, +, -, *, /, or %c): ", 'A' + 1);
        scanf(" %c", &operation);

        if (operation == 'a' || operation == 'A') {
            printf("Please enter the first number: ");
            scanf("%d", &num1);
            printf("Please enter the second number: ");
            scanf("%d", &num2);
            sum = num1 + num2;
            printf("The sum of %d and %d is %d\n", num1, num2, sum);
        } else if (operation == '+' || operation == '-') {
            printf("Please enter the first number: ");
            scanf("%d", &num1);
            printf("Please enter the second number: ");
            scanf("%d", &num2);
            if (operation == '+') {
                sum = num1 + num2;
                printf("The sum of %d and %d is %d\n", num1, num2, sum);
            } else {
                difference = num1 - num2;
                printf("The difference of %d and %d is %d\n", num1, num2, difference);
            }
        } else if (operation == '*' || operation == '/') {
            printf("Please enter the first number: ");
            scanf("%d", &num1);
            printf("Please enter the second number: ");
            scanf("%d", &num2);
            if (operation == '*') {
                product = num1 * num2;
                printf("The product of %d and %d is %d\n", num1, num2, product);
            } else {
                quotient = num1 / num2;
                remainder = num1 % num2;
                printf("The quotient of %d and %d is %d with a remainder of %d\n", num1, num2, quotient, remainder);
            }
        } else if (operation == '%') {
            printf("Please enter the first number: ");
            scanf("%d", &num1);
            remainder = num1 % MAGIC_NUMBER;
            printf("The remainder of %d modulo %d is %d\n", num1, MAGIC_NUMBER, remainder);
        }
    } while (operation != 'q' && operation != 'Q');

    return 0;
}