//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 1000000
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, square;
    char operation[5];

    printf("Welcome to the Arithmetic Playground! \n");

    do {
        printf("Enter the first number: ");
        scanf("%d", &num1);

        printf("Enter the second number: ");
        scanf("%d", &num2);

        printf("Enter the operation (+, -, *, /): ");
        scanf("%s", operation);

        if (strcmp(operation, "+") == 0) {
            sum = num1 + num2;
        } else if (strcmp(operation, "-") == 0) {
            sum = num1 - num2;
        } else if (strcmp(operation, "*") == 0) {
            product = num1 * num2;
        } else if (strcmp(operation, "/") == 0) {
            if (num2 == 0) {
                printf("Error: division by zero!\n");
            } else {
                square = num1 * num1;
                sum = num1 / num2;
            }
        } else {
            printf("Error: invalid operation!\n");
        }

        printf("Result: %d\n", sum);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &operation);

    } while (strcmp(operation, "y") != 0);

    return 0;
}