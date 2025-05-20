//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char op;
    double num1, num2;
} Calc;

void error(char *msg) {
    perror(msg);
    exit(1);
}

void input(Calc *calc) {
    printf("Enter first number: ");
    scanf("%lf", &calc->num1);
    printf("Enter operator: ");
    scanf(" %c", &calc->op);
    printf("Enter second number: ");
    scanf("%lf", &calc->num2);
}

void result(Calc *calc) {
    switch (calc->op) {
        case '+':
            printf("%lf\n", calc->num1 + calc->num2);
            break;
        case '-':
            printf("%lf\n", calc->num1 - calc->num2);
            break;
        case '*':
            printf("%lf\n", calc->num1 * calc->num2);
            break;
        case '/':
            if (calc->num2 == 0) {
                error("Division by zero error");
            } else {
                printf("%lf\n", calc->num1 / calc->num2);
            }
            break;
        default:
            error("Invalid operator");
            break;
    }
}

int main() {
    Calc calc;
    input(&calc);
    result(&calc);
    return 0;
}