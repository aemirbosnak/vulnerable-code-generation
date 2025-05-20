//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num1;
    int num2;
    char op;
} CalcOperation;

void main() {
    int result;
    CalcOperation calcOps[3];
    int i;

    printf("\n***** RETRO ARITHMETIC CALCULATOR *****\n");
    printf("\nEnter the number of arithmetic operations: \n");

    for (i = 0; i < 3; i++) {
        printf("\nOperation %d:\n", i + 1);
        printf("Enter first number: ");
        scanf("%d", &calcOps[i].num1);
        printf("Enter second number: ");
        scanf("%d", &calcOps[i].num2);
        printf("Enter operation (+, -, *, /): ");
        scanf(" %c", &calcOps[i].op);
    }

    for (i = 0; i < 3; i++) {
        switch (calcOps[i].op) {
            case '+':
                result = calcOps[i].num1 + calcOps[i].num2;
                break;
            case '-':
                result = calcOps[i].num1 - calcOps[i].num2;
                break;
            case '*':
                result = calcOps[i].num1 * calcOps[i].num2;
                break;
            case '/':
                if (calcOps[i].num2 == 0) {
                    printf("\nError: Division by zero is not allowed!\n");
                    i--;
                    continue;
                }
                result = calcOps[i].num1 / calcOps[i].num2;
                break;
            default:
                printf("\nError: Invalid operation symbol!\n");
                i--;
                continue;
        }

        printf("\nResult of Operation %d: %d %c %d = %d\n", i + 1, calcOps[i].num1, calcOps[i].op, calcOps[i].num2, result);
    }

    printf("\n***** END OF RETRO ARITHMETIC CALCULATOR *****\n");
}