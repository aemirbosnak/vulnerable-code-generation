//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 1000000
#define MIN_NUM 1

int main() {
    srand(time(0));

    int num1, num2, operation, result;
    char op;

    printf("Welcome to the Arithmetic Calculator!\n");
    printf("-----------------------------\n");

    while (1) {
        printf("Enter two numbers separated by space:\n");
        scanf("%d %d", &num1, &num2);

        printf("Enter the operation (+, -, *, /):\n");
        scanf(" %c", &op);

        switch (op) {
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
                    printf("Error: Division by zero is not allowed!\n");
                    continue;
                }
                result = num1 / num2;
                break;
            default:
                printf("Error: Invalid operation!\n");
                continue;
        }

        printf("Result: %d\n", result);
        printf("\nDo you want to continue? (y/n): ");
        char cont;
        scanf(" %c", &cont);

        if (cont == 'n') {
            break;
        }
    }

    return 0;
}