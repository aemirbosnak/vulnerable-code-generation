//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include<stdio.h>
#include<math.h>

double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, int);
double factorial(double);

int main()
{
    int choice;
    double num1, num2, result;
    int exponent;

    do {
        printf("\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Power\n");
        printf("6. Factorial\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%lf %lf", &num1, &num2);
                result = divide(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("Enter an exponent: ");
                scanf("%d", &exponent);
                result = power(num1, exponent);
                printf("Result: %lf\n", result);
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = factorial(num1);
                printf("Result: %lf\n", result);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (1);

    return 0;
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double power(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent == 1) {
        return base;
    } else if (exponent < 0) {
        return (1/base) * power(base, exponent+1);
    } else {
        return base * power(base, exponent-1);
    }
}

double factorial(double num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num-1);
    }
}