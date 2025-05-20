//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

// Function to calculate the power of a number
double power(double base, double exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Function to calculate the logarithm of a number
double logarithm(double base, double num) {
    double result = 0.0;
    while (num >= base) {
        num /= base;
        result++;
    }
    return result;
}

// Function to calculate the sine of a number
double sine(double angle) {
    double result = 0.0;
    for (int i = 0; i < 100; i++) {
        result += power(-1, i) * power(angle, 2 * i + 1) / factorial(2 * i + 1);
    }
    return result;
}

// Function to calculate the cosine of a number
double cosine(double angle) {
    double result = 0.0;
    for (int i = 0; i < 100; i++) {
        result += power(-1, i) * power(angle, 2 * i) / factorial(2 * i);
    }
    return result;
}

// Function to calculate the tangent of a number
double tangent(double angle) {
    return sine(angle) / cosine(angle);
}

// Function to calculate the inverse sine of a number
double arcsine(double num) {
    double result = 0.0;
    for (int i = 0; i < 100; i++) {
        result += power(-1, i) * power(num, 2 * i + 1) / factorial(2 * i + 1) * (2 * i + 1);
    }
    return result;
}

// Function to calculate the inverse cosine of a number
double arccosine(double num) {
    double result = 0.0;
    for (int i = 0; i < 100; i++) {
        result += power(-1, i) * power(num, 2 * i) / factorial(2 * i) * (2 * i);
    }
    return result;
}

// Function to calculate the inverse tangent of a number
double arctangent(double num) {
    double result = 0.0;
    for (int i = 0; i < 100; i++) {
        result += power(-1, i) * power(num, 2 * i + 1) / (2 * i + 1);
    }
    return result;
}

int main() {
    // Declare variables
    int choice;
    double num1, num2;

    // Display the menu
    printf("1. Factorial\n");
    printf("2. Power\n");
    printf("3. Logarithm\n");
    printf("4. Sine\n");
    printf("5. Cosine\n");
    printf("6. Tangent\n");
    printf("7. Inverse Sine\n");
    printf("8. Inverse Cosine\n");
    printf("9. Inverse Tangent\n");
    printf("10. Exit\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the calculation based on the user's choice
    switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            printf("Factorial of %.2lf is %.2lf\n", num1, factorial(num1));
            break;
        case 2:
            printf("Enter a base: ");
            scanf("%lf", &num1);
            printf("Enter an exponent: ");
            scanf("%lf", &num2);
            printf("%.2lf to the power of %.2lf is %.2lf\n", num1, num2, power(num1, num2));
            break;
        case 3:
            printf("Enter a base: ");
            scanf("%lf", &num1);
            printf("Enter a number: ");
            scanf("%lf", &num2);
            printf("Logarithm of %.2lf to the base %.2lf is %.2lf\n", num2, num1, logarithm(num1, num2));
            break;
        case 4:
            printf("Enter an angle in degrees: ");
            scanf("%lf", &num1);
            printf("Sine of %.2lf degrees is %.2lf\n", num1, sine(num1 * M_PI / 180.0));
            break;
        case 5:
            printf("Enter an angle in degrees: ");
            scanf("%lf", &num1);
            printf("Cosine of %.2lf degrees is %.2lf\n", num1, cosine(num1 * M_PI / 180.0));
            break;
        case 6:
            printf("Enter an angle in degrees: ");
            scanf("%lf", &num1);
            printf("Tangent of %.2lf degrees is %.2lf\n", num1, tangent(num1 * M_PI / 180.0));
            break;
        case 7:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            printf("Inverse sine of %.2lf is %.2lf degrees\n", num1, arcsine(num1) * 180.0 / M_PI);
            break;
        case 8:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            printf("Inverse cosine of %.2lf is %.2lf degrees\n", num1, arccosine(num1) * 180.0 / M_PI);
            break;
        case 9:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            printf("Inverse tangent of %.2lf is %.2lf degrees\n", num1, arctangent(num1) * 180.0 / M_PI);
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid choice\n");
    }

    return 0;
}