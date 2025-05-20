//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100000
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to the Arithmetic Playground!\n");

    do {
        printf("Enter a number: ");
        scanf("%d", &num1);

        printf("Enter an operation (+, -, *, /): ");
        scanf(" %c", &op);

        if (op == '+') {
            printf("Enter another number: ");
            scanf("%d", &num2);
            sum = num1 + num2;
            printf("The result of %d + %d is %d\n", num1, num2, sum);
        } else if (op == '-') {
            printf("Enter another number: ");
            scanf("%d", &num2);
            sum = num1 - num2;
            printf("The result of %d - %d is %d\n", num1, num2, sum);
        } else if (op == '*') {
            printf("Enter another number: ");
            scanf("%d", &num2);
            sum = num1 * num2;
            printf("The result of %d * %d is %d\n", num1, num2, sum);
        } else if (op == '/') {
            printf("Enter another number: ");
            scanf("%d", &num2);
            if (num2 == 0) {
                printf("Error: division by zero!\n");
            } else {
                sum = num1 / num2;
                printf("The result of %d / %d is %d\n", num1, num2, sum);
            }
        } else {
            printf("Invalid operation. Please try again.\n");
        }
    } while (1);

    return 0;
}