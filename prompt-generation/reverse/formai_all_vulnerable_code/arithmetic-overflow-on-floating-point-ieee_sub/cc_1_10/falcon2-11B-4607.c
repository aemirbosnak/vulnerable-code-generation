//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int precision;
    char buffer[100];
} Calculator;

void add(Calculator* calc, double num1, double num2) {
    char* endptr;
    double sum = num1 + num2;
    sprintf(calc->buffer, "%.*f", calc->precision, sum);
}

void subtract(Calculator* calc, double num1, double num2) {
    char* endptr;
    double diff = num1 - num2;
    sprintf(calc->buffer, "%.*f", calc->precision, diff);
}

void multiply(Calculator* calc, double num1, double num2) {
    char* endptr;
    double product = num1 * num2;
    sprintf(calc->buffer, "%.*f", calc->precision, product);
}

void divide(Calculator* calc, double num1, double num2) {
    char* endptr;
    double result = num1 / num2;
    sprintf(calc->buffer, "%.*f", calc->precision, result);
}

int main(void) {
    Calculator calc;
    calc.precision = 2;

    printf("Welcome to the Scientific Calculator!\n");

    while (1) {
        printf("\nPlease select an operation: \n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-4): ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the first number: ");
            double num1;
            scanf("%lf", &num1);

            printf("Enter the second number: ");
            double num2;
            scanf("%lf", &num2);

            add(&calc, num1, num2);
        } else if (choice == 2) {
            printf("Enter the first number: ");
            double num1;
            scanf("%lf", &num1);

            printf("Enter the second number: ");
            double num2;
            scanf("%lf", &num2);

            subtract(&calc, num1, num2);
        } else if (choice == 3) {
            printf("Enter the first number: ");
            double num1;
            scanf("%lf", &num1);

            printf("Enter the second number: ");
            double num2;
            scanf("%lf", &num2);

            multiply(&calc, num1, num2);
        } else if (choice == 4) {
            printf("Enter the first number: ");
            double num1;
            scanf("%lf", &num1);

            printf("Enter the second number: ");
            double num2;
            scanf("%lf", &num2);

            divide(&calc, num1, num2);
        } else if (choice == 5) {
            printf("\nThank you for using the Scientific Calculator!\n");
            break;
        } else {
            printf("\nInvalid choice!\n");
        }
    }

    printf("The result is: %s\n", calc.buffer);

    return 0;
}