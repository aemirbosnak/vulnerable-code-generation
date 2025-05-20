//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

void displayMenu() {
    printf("\n----- Scientific Calculator -----\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exponential (e^x)\n");
    printf("6. Logarithm (log base 10)\n");
    printf("7. Sine (sin)\n");
    printf("8. Cosine (cos)\n");
    printf("9. Tangent (tan)\n");
    printf("10. Exit\n");
    printf("Select an option (1-10): ");
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

double exponential(double x) {
    return exp(x);
}

double logarithm(double x) {
    if (x > 0)
        return log10(x);
    else {
        printf("Error: Logarithm of non-positive number!\n");
        return 0;
    }
}

double sine(double x) {
    return sin(x * M_PI / 180); // Convert to radians
}

double cosine(double x) {
    return cos(x * M_PI / 180); // Convert to radians
}

double tangent(double x) {
    return tan(x * M_PI / 180); // Convert to radians
}

int main() {
    int choice;
    double num1, num2, result;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = divide(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = exponential(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = logarithm(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 7:
                printf("Enter an angle (in degrees): ");
                scanf("%lf", &num1);
                result = sine(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 8:
                printf("Enter an angle (in degrees): ");
                scanf("%lf", &num1);
                result = cosine(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 9:
                printf("Enter an angle (in degrees): ");
                scanf("%lf", &num1);
                result = tangent(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 10:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 10);

    return 0;
}