//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double num1, num2, result;
    char op;
} calc_t;

void add(calc_t *calc) {
    calc->result = calc->num1 + calc->num2;
}

void subtract(calc_t *calc) {
    calc->result = calc->num1 - calc->num2;
}

void multiply(calc_t *calc) {
    calc->result = calc->num1 * calc->num2;
}

void divide(calc_t *calc) {
    if (calc->num2 == 0) {
        printf("Error: Division by zero.\n");
        exit(1);
    }
    calc->result = calc->num1 / calc->num2;
}

int main() {
    calc_t calc;
    double num1, num2;

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator: ");
    scanf(" %c", &calc.op);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (calc.op) {
        case '+':
            add(&calc);
            break;
        case '-':
            subtract(&calc);
            break;
        case '*':
            multiply(&calc);
            break;
        case '/':
            divide(&calc);
            break;
        default:
            printf("Error: Invalid operator.\n");
            exit(1);
    }

    printf("Result: %.2lf\n", calc.result);

    return 0;
}