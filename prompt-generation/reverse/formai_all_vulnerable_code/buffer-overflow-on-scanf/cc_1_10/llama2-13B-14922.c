//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 1000
#define MIN_NUMBER -1000

int main() {
    int num1, num2, sum, diff, mult, div, mod;
    char operator;
    char prompt[] = "Welcome to the Introspective Arithmetic Program! Please enter your first number: ";

    printf(prompt, sizeof(prompt));
    scanf("%d", &num1);

    printf("You have entered: %d\n", num1);

    do {
        printf("Please enter an arithmetic operator (+, -, *, /, or %).: ");
        scanf(" %c", &operator);

        if (operator == '+') {
            printf("Please enter your second number: ");
            scanf("%d", &num2);
            sum = num1 + num2;
            printf("The sum of %d and %d is %d\n", num1, num2, sum);
        } else if (operator == '-') {
            printf("Please enter your second number: ");
            scanf("%d", &num2);
            diff = num1 - num2;
            printf("The difference of %d and %d is %d\n", num1, num2, diff);
        } else if (operator == '*') {
            printf("Please enter your second number: ");
            scanf("%d", &num2);
            mult = num1 * num2;
            printf("The product of %d and %d is %d\n", num1, num2, mult);
        } else if (operator == '/') {
            printf("Please enter your second number: ");
            scanf("%d", &num2);
            div = num1 / num2;
            printf("The quotient of %d and %d is %d\n", num1, num2, div);
        } else if (operator == '%') {
            printf("Please enter your second number: ");
            scanf("%d", &num2);
            mod = num1 % num2;
            printf("The remainder of %d and %d is %d\n", num1, num2, mod);
        } else {
            printf("Invalid operator. Please try again.\n");
        }
    } while (1);

    return 0;
}