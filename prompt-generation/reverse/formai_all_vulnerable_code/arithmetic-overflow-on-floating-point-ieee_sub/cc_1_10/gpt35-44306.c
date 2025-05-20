//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <math.h>

double addition(double a, double b) { return a + b; }
double subtraction(double a, double b) { return a - b; }
double multiplication(double a, double b) { return a * b; }
double division(double a, double b) { return a / b; }
double power(double a, double b) { return pow(a, b); }
double square_root(double a) { return sqrt(a); }

int main() {
    int choice;
    double a, b;

    printf("Enter 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division, 5 for power, 6 for square root: ");
    scanf("%d", &choice);

    if (choice < 6) {
        printf("Enter first number: ");
        scanf("%lf", &a);

        printf("Enter second number: ");
        scanf("%lf", &b);

        switch (choice) {
            case 1:
                printf("%.2lf + %.2lf = %.2lf", a, b, addition(a, b));
                break;
            case 2:
                printf("%.2lf - %.2lf = %.2lf", a, b, subtraction(a, b));
                break;
            case 3:
                printf("%.2lf * %.2lf = %.2lf", a, b, multiplication(a, b));
                break;
            case 4:
                printf("%.2lf / %.2lf = %.2lf", a, b, division(a, b));
                break;
        }
    } else {
        printf("Enter number: ");
        scanf("%lf", &a);

        switch (choice) {
            case 5:
                printf("%.2lf ^ 2 = %.2lf", a, power(a, 2));
                break;
            case 6:
                printf("Square root of %.2lf = %.2lf", a, square_root(a));
                break;
        }
    }

    return 0;
}