//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM 100000
#define MAX_OPER 5

typedef struct {
    int num;
    char op[2];
} expression;

expression eval_expression(expression e1, expression e2) {
    int num1 = e1.num;
    char op1 = e1.op[0];
    int num2 = e2.num;
    char op2 = e2.op[0];

    if (op1 == '+') {
        return (expression) { num1 + num2, op2 };
    } else if (op1 == '-') {
        return (expression) { num1 - num2, op2 };
    } else if (op1 == '*') {
        return (expression) { num1 * num2, op2 };
    } else if (op1 == '/') {
        return (expression) { num1 / num2, op2 };
    } else if (op1 == '%') {
        return (expression) { num1 % num2, op2 };
    } else {
        printf("Invalid operation\n");
        return (expression) { 0, op2 };
    }
}

int main() {
    int num1, num2, res;
    char op[2];

    printf("Enter two numbers and an operation (+, -, *, /, %): ");
    scanf("%d%c%d", &num1, &op[0], &num2);

    expression e1 = (expression) { num1, op };
    expression e2 = (expression) { num2, op };

    res = eval_expression(e1, e2).num;

    printf("Result: %d\n", res);

    return 0;
}