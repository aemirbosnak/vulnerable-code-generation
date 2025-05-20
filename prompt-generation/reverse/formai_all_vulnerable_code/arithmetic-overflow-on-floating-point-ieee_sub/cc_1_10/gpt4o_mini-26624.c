//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_menu() {
    printf("\nScientific Calculator Menu:\n");
    printf("1. Addition (a + b)\n");
    printf("2. Subtraction (a - b)\n");
    printf("3. Multiplication (a * b)\n");
    printf("4. Division (a / b)\n");
    printf("5. Square (a^2)\n");
    printf("6. Square Root (sqrt(a))\n");
    printf("7. Sine (sin(a))\n");
    printf("8. Cosine (cos(a))\n");
    printf("9. Tangent (tan(a))\n");
    printf("10. Exit\n");
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
    if (b != 0)
        return a / b;
    else {
        printf("Error: Division by zero!\n");
        return 0;
    }
}

double square(double a) {
    return a * a;
}

double square_root(double a) {
    if (a >= 0)
        return sqrt(a);
    else {
        printf("Error: Cannot compute square root of a negative number!\n");
        return 0;
    }
}

double sine(double a) {
    return sin(a);
}

double cosine(double a) {
    return cos(a);
}

double tangent(double a) {
    return tan(a);
}

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        print_menu();
        printf("Enter your choice (1-10): ");
        scanf("%d", &choice);

        if (choice == 10) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = divide(num1, num2);
                printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = square(num1);
                printf("Result: %.2lf^2 = %.2lf\n", num1, result);
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = square_root(num1);
                printf("Result: sqrt(%.2lf) = %.2lf\n", num1, result);
                break;
            case 7:
                printf("Enter an angle in radians: ");
                scanf("%lf", &num1);
                result = sine(num1);
                printf("Result: sin(%.2lf) = %.2lf\n", num1, result);
                break;
            case 8:
                printf("Enter an angle in radians: ");
                scanf("%lf", &num1);
                result = cosine(num1);
                printf("Result: cos(%.2lf) = %.2lf\n", num1, result);
                break;
            case 9:
                printf("Enter an angle in radians: ");
                scanf("%lf", &num1);
                result = tangent(num1);
                printf("Result: tan(%.2lf) = %.2lf\n", num1, result);
                break;
            default:
                printf("Invalid choice! Please choose a number between 1 and 10.\n");
                break;
        }
    }

    return 0;
}