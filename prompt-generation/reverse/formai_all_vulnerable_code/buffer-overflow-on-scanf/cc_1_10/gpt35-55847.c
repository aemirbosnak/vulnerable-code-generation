//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int menu();
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double logBase(double, double);

int main() {
    double num1, num2, result;
    int choice = 0;
    do {
        choice = menu();
        switch (choice) {
            case 1: // addition
                printf("\nEnter two numbers to add: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("%.2lf + %.2lf = %.2lf\n\n", num1, num2, result);
                break;
            case 2: // subtraction
                printf("\nEnter two numbers to subtract: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("%.2lf - %.2lf = %.2lf\n\n", num1, num2, result);
                break;
            case 3: // multiplication
                printf("\nEnter two numbers to multiply: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("%.2lf * %.2lf = %.2lf\n\n", num1, num2, result);
                break;
            case 4: // division
                printf("\nEnter two numbers to divide: ");
                scanf("%lf %lf", &num1, &num2);
                result = divide(num1, num2);
                printf("%.2lf / %.2lf = %.2lf\n\n", num1, num2, result);
                break;
            case 5: // exponentiation
                printf("\nEnter the base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = power(num1, num2);
                printf("%.2lf ^ %.2lf = %.2lf\n\n", num1, num2, result);
                break;
            case 6: // logarithm
                printf("\nEnter the base and argument: ");
                scanf("%lf %lf", &num1, &num2);
                result = logBase(num1, num2);
                printf("log base %.2lf of %.2lf = %.2lf\n\n", num1, num2, result);
                break;
            case 7: // exit program
                printf("\nThank you for using the calculator!\n");
                break;
            default: // invalid option
                printf("\nInvalid option, please try again.\n\n");
                break;
        }
    } while (choice != 7);
    return 0;
}

// recursive addition function
double add(double x, double y) {
    if (y == 0) { // base case
        return x;
    } else {
        return add(x+1, y-1); // recursive call
    }
}

// recursive subtraction function
double subtract(double x, double y) {
    if (y == 0) { // base case
        return x;
    } else {
        return subtract(x-1, y-1); // recursive call
    }
}

// recursive multiplication function
double multiply(double x, double y) {
    if (y == 1) { // base case
        return x;
    } else {
        return multiply(x, y-1) + x; // recursive call
    }
}

// recursive division function
double divide(double x, double y) {
    if (x < y) { // base case
        return 0;
    } else {
        return divide(x-y, y) + 1; // recursive call
    }
}

// recursive exponentiation function
double power(double x, double y) {
    if (y == 0) { // base case
        return 1;
    } else if (y < 0) { // handle negative exponents
        return 1/power(x, -y);
    } else {
        return x * power(x, y-1); // recursive call
    }
}

// recursive logarithm function
double logBase(double b, double x) {
    if (x < b) { // base case
        return 0;
    } else {
        return 1 + logBase(b, x/b); // recursive call
    }
}

// menu function to display options to user and return their choice
int menu() {
    int choice;
    printf("*** Scientific Calculator ***\n");
    printf("1) Addition\n");
    printf("2) Subtraction\n");
    printf("3) Multiplication\n");
    printf("4) Division\n");
    printf("5) Exponentiation\n");
    printf("6) Logarithm\n");
    printf("7) Exit\n");
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);
    return choice;
}