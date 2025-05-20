//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100
#define MIN_NUM -1000
#define PI 3.14159265358979323846

typedef struct {
    int num1;
    int num2;
    char op;
} Arithmetic_Operation;

void calculate_result(Arithmetic_Operation *arith_op) {
    switch (arith_op->op) {
        case '+':
            arith_op->num1 += arith_op->num2;
            break;
        case '-':
            arith_op->num1 -= arith_op->num2;
            break;
        case '*':
            arith_op->num1 *= arith_op->num2;
            break;
        case '/':
            if (arith_op->num2 != 0) {
                arith_op->num1 /= arith_op->num2;
            } else {
                printf("Error! Division by zero is not allowed.\n");
                exit(EXIT_FAILURE);
            }
            break;
        case '%':
            arith_op->num1 %= arith_op->num2;
            break;
        default:
            printf("Error! Invalid arithmetic operation.\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    Arithmetic_Operation arith_op;
    int num1, num2;
    char operation;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter an arithmetic operation (+, -, *, /, %%): ");
    scanf(" %c", &operation);

    arith_op.num1 = num1;
    arith_op.num2 = num2;
    arith_op.op = operation;

    calculate_result(&arith_op);

    printf("Result: %d\n", arith_op.num1);

    return EXIT_SUCCESS;
}