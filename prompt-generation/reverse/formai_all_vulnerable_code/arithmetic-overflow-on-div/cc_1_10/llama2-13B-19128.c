//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 100000
#define MIN_NUMBER -100000

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;

    printf("Welcome to the Arithmetic Game!\n");

    do {
        printf("Enter a number: ");
        scanf("%d", &num1);

        printf("Enter an operation (+, -, *, /): ");
        scanf(" %c", &op);

        if (op == '+') {
            printf("Enter a second number: ");
            scanf("%d", &num2);
            sum = num1 + num2;
        } else if (op == '-') {
            printf("Enter a second number: ");
            scanf("%d", &num2);
            diff = num1 - num2;
        } else if (op == '*') {
            printf("Enter a second number: ");
            scanf("%d", &num2);
            mult = num1 * num2;
        } else if (op == '/') {
            printf("Enter a second number: ");
            scanf("%d", &num2);
            div = num1 / num2;

            if (div == 0) {
                printf("Error: Division by zero!\n");
            } else {
                printf("Result: %d\n", div);
            }
        } else {
            printf("Invalid operation. Try again.\n");
        }
    } while (1);

    return 0;
}