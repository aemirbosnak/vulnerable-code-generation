//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

char *funcs[] = {"+", "-", "*", "/", "sin", "cos", "tan", "log", "pow", "sqrt"};

int main() {
    char op;
    double a, b;
    bool isFunc = false;

    printf("### Enigma Calculator ###\n\n");
    printf("Enter the expression (e.g. a + b, sin a, pow a b): ");
    scanf("%lf %c %lf", &a, &op, &b);

    for (int i = 0; i < 10; i++) {
        if (funcs[i][0] == op) {
            isFunc = true;
            break;
        }
    }

    if (isFunc) {
        switch (op) {
            case '+':
                printf("%.2lf %s %.2lf = %.2lf\n", a, funcs[0], b, a + b);
                break;
            case '-':
                printf("%.2lf %s %.2lf = %.2lf\n", a, funcs[1], b, a - b);
                break;
            case '*':
                printf("%.2lf %s %.2lf = %.2lf\n", a, funcs[2], b, a * b);
                break;
            case '/':
                if (b == 0) {
                    printf("Error: Division by zero\n");
                } else {
                    printf("%.2lf %s %.2lf = %.2lf\n", a, funcs[3], b, a / b);
                }
                break;
            case 's':
                if (op == 's' && funcs[4][1] == op) {
                    printf("sin(%.2lf) = %.2lf\n", a, sin(a));
                } else if (op == 's' && funcs[5][1] == op) {
                    printf("cos(%.2lf) = %.2lf\n", a, cos(a));
                } else if (op == 's' && funcs[6][1] == op) {
                    printf("tan(%.2lf) = %.2lf\n", a, tan(a));
                }
                break;
            case 'l':
                printf("log(%.2lf) = %.2lf\n", a, log(a));
                break;
            case 'p':
                printf("pow(%.2lf, %.2lf) = %.2lf\n", a, b, pow(a, b));
                break;
            case 'r':
                if (a < 0) {
                    printf("Error: Square root of a negative number\n");
                } else {
                    printf("sqrt(%.2lf) = %.2lf\n", a, sqrt(a));
                }
                break;
        }
    } else {
        printf("Error: Invalid input\n");
    }

    return 0;
}