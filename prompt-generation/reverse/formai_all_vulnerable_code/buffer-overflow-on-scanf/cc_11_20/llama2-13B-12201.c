//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, d, e, f;
    char op;

    printf("Welcome to the Math Exercise!\n");

    // Problem 1: Simplify the expression
    printf("Enter two numbers: ");
    scanf("%f%c%f", &a, &op, &b);
    if (op == '+') {
        c = a + b;
    } else if (op == '-') {
        c = a - b;
    } else if (op == '*') {
        c = a * b;
    } else if (op == '/') {
        c = a / b;
    }
    printf("The result of %f + %f is %f\n", a, b, c);

    // Problem 2: Solve the equation
    printf("Enter a number: ");
    scanf("%f", &d);
    e = d * d;
    f = d + 2;
    c = e + f;
    printf("The value of x is %f\n", c);

    // Problem 3: Find the maximum value
    printf("Enter three numbers: ");
    scanf("%f%c%f%c%f", &a, &op, &b, &op, &c);
    if (op == '>') {
        if (a > b) {
            if (c > a) {
                printf("The maximum value is %f\n", c);
            } else {
                printf("The maximum value is %f\n", a);
            }
        } else {
            printf("The maximum value is %f\n", b);
        }
    } else if (op == '<') {
        if (a < b) {
            if (c < a) {
                printf("The maximum value is %f\n", c);
            } else {
                printf("The maximum value is %f\n", a);
            }
        } else {
            printf("The maximum value is %f\n", b);
        }
    }

    return 0;
}