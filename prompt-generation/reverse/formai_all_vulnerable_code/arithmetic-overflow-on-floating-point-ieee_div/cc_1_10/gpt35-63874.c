//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: romantic
#include <stdio.h>
#include <math.h>

void add(double a, double b);
void subtract(double a, double b);
void multiply(double a, double b);
void divide(double a, double b);

int main() {
    double num1, num2, ans;
    char op;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch(op) {
        case '+':
            add(num1, num2);
            break;

        case '-':
            subtract(num1, num2);
            break;

        case '*':
            multiply(num1, num2);
            break;

        case '/':
            divide(num1, num2);
            break;

        default:
            printf("Invalid operator");
    }

    return 0;
}

void add(double a, double b) {
    double ans = a + b;
    printf("%.2lf + %.2lf = %.2lf", a, b, ans);
}

void subtract(double a, double b) {
    double ans = a - b;
    printf("%.2lf - %.2lf = %.2lf", a, b, ans);
}

void multiply(double a, double b) {
    double ans = a * b;
    printf("%.2lf x %.2lf = %.2lf", a, b, ans);
}

void divide(double a, double b) {
    if(b == 0) {
        printf("Cannot divide by 0");
        return;
    }

    double ans = a / b;
    printf("%.2lf / %.2lf = %.2lf", a, b, ans);
}