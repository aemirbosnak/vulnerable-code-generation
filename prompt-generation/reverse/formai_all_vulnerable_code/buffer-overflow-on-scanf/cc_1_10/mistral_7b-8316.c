//MISTRAL-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct { double stack[128]; int top; } calculator;

void push(calculator *calc, double value) {
    if (calc->top >= 128) {
        printf("Oh dear! Stack overflow.\n");
        exit(EXIT_FAILURE);
    }
    calc->stack[calc->top++] = value;
}

double pop(calculator *calc) {
    if (calc->top <= 0) {
        printf("Uh oh! Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    return calc->stack[--calc->top];
}

void evaluate_expression(calculator *calc, char *expression) {
    int i = 0;
    double num1, num2, result;

    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            num1 = strtod(&expression[i], NULL);
            push(calc, num1);
            i += strlen(&expression[i]) + 1;
        } else if (expression[i] == '+' && isdigit(expression[i + 1])) {
            num1 = pop(calc);
            num2 = strtod(&expression[i + 1], NULL);
            push(calc, num1 + num2);
            i += strlen(&expression[i + 1]) + 1;
        } else if (expression[i] == '-') {
            num1 = pop(calc);
            num2 = pop(calc);
            push(calc, num2 - num1);
            i++;
        } else if (expression[i] == '*') {
            num1 = pop(calc);
            num2 = pop(calc);
            push(calc, num1 * num2);
            i++;
        } else if (expression[i] == '/') {
            num1 = pop(calc);
            num2 = pop(calc);
            push(calc, num2 / num1);
            i++;
        } else if (expression[i] == '^') {
            num1 = pop(calc);
            num2 = pop(calc);
            push(calc, pow(num2, num1));
            i++;
        } else if (expression[i] == 's' && expression[i + 1] == 'i' && expression[i + 2] == 'n') {
            result = pop(calc);
            printf("The square root of %g is %g!\n", pop(calc), sqrt(result));
            push(calc, sqrt(result));
            i += 3;
        } else if (expression[i] == 'l' && expression[i + 1] == 'o' && expression[i + 2] == 'g') {
            printf("The natural logarithm of %g is %g!\n", pop(calc), log(pop(calc)));
            push(calc, log(pop(calc)));
            i += 3;
        } else if (expression[i] == 'e' && expression[i + 1] == 'x' && expression[i + 2] == 'p') {
            push(calc, M_E);
            i += 3;
        } else {
            printf("I'm sorry, I don't understand the symbol %c. Please check the expression and try again.\n", expression[i]);
            exit(EXIT_FAILURE);
        }
    }

    result = pop(calc);
    printf("The result of the expression is %g.\n", result);
}

int main() {
    calculator calc;
    calc.top = 0;

    char expression[128];
    printf("Enter a mathematical expression (e.g. 3.14 * sin(x) + 2): ");
    scanf("%s", expression);

    evaluate_expression(&calc, expression);

    return 0;
}