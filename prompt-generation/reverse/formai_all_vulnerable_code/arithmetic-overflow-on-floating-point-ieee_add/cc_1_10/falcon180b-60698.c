//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a, b, c, d, e;
    int n;
    char op;

    // prompt for input
    printf("Enter a mathematical expression in the form of a+b+c+d+e\n");
    scanf("%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c", &a, &op, &b, &op, &c, &op, &d, &op, &e, &op);

    // perform calculations
    switch(op) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", a, b, a+b);
            printf("%.2lf + %.2lf = %.2lf\n", c, d, c+d);
            printf("%.2lf + %.2lf = %.2lf\n", e, a, e+a);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", a, b, a-b);
            printf("%.2lf - %.2lf = %.2lf\n", c, d, c-d);
            printf("%.2lf - %.2lf = %.2lf\n", e, a, e-a);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", a, b, a*b);
            printf("%.2lf * %.2lf = %.2lf\n", c, d, c*d);
            printf("%.2lf * %.2lf = %.2lf\n", e, a, e*a);
            break;
        case '/':
            if(b!= 0) {
                printf("%.2lf / %.2lf = %.2lf\n", a, b, a/b);
            } else {
                printf("Division by zero is not allowed.\n");
            }
            if(d!= 0) {
                printf("%.2lf / %.2lf = %.2lf\n", c, d, c/d);
            } else {
                printf("Division by zero is not allowed.\n");
            }
            if(a!= 0) {
                printf("%.2lf / %.2lf = %.2lf\n", e, a, e/a);
            } else {
                printf("Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid operator. Please use +, -, *, or /\n");
            break;
    }

    return 0;
}