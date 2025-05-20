//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scientific
/* A C program to parse mathematical expressions */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 100

/* A function to evaluate mathematical expressions */
double evaluate(const char* expr)
{
    double stack[STACK_SIZE];
    int top = -1;
    char ch, op;
    double num;
    int i;

    for (i = 0; i < strlen(expr); i++) {
        ch = expr[i];

        if (isdigit(ch)) {
            num = 0;
            while (isdigit(ch)) {
                num = num * 10 + (double)(ch - '0');
                i++;
                ch = expr[i];
            }
            i--;
            stack[++top] = num;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            op = ch;
            double num2 = stack[top--];
            double num1 = stack[top--];
            if (op == '+') {
                stack[++top] = num1 + num2;
            } else if (op == '-') {
                stack[++top] = num1 - num2;
            } else if (op == '*') {
                stack[++top] = num1 * num2;
            } else {
                stack[++top] = num1 / num2;
            }
        } else {
            /* Error handling */
            printf("Invalid character: %c\n", ch);
            exit(1);
        }
    }

    return stack[top--];
}

int main()
{
    char expr[100];
    printf("Enter a mathematical expression: ");
    scanf("%[^\n]", expr);
    double result = evaluate(expr);
    printf("Result: %lf\n", result);
    return 0;
}