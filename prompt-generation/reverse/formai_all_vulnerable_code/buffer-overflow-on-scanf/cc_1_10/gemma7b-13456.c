//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

typedef struct Calculator {
    int num1;
    int num2;
    char operator;
} Calculator;

void calculate(Calculator *calc) {
    switch (calc->operator) {
        case '+':
            calc->num1 += calc->num2;
            break;
        case '-':
            calc->num1 -= calc->num2;
            break;
        case '*':
            calc->num1 *= calc->num2;
            break;
        case '/':
            if (calc->num2 == 0) {
                printf("Error: division by zero is not allowed.\n");
            } else {
                calc->num1 /= calc->num2;
            }
            break;
        default:
            printf("Invalid operator.\n");
    }
}

int main() {
    Calculator calc;
    calc.num1 = 0;
    calc.num2 = 0;
    calc.operator = '\0';

    printf("Welcome to the Ancient Calculator!\n");
    printf("Please enter an operator (+, -, *, /): ");
    scanf("%c", &calc.operator);

    printf("Please enter two numbers: ");
    scanf("%d %d", &calc.num1, &calc.num2);

    calculate(&calc);

    printf("The result is: %d\n", calc.num1);

    return 0;
}