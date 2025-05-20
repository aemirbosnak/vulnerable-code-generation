//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void display_menu() {
    printf("==== Scientific Calculator ====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Sine\n");
    printf("6. Cosine\n");
    printf("7. Tangent\n");
    printf("8. Logarithm\n");
    printf("9. Exit\n");
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
        printf("Error: Division by zero\n");
        return 0;
    }
}

double sine(double angle) {
    return sin(angle * M_PI / 180);  // Convert to radians
}

double cosine(double angle) {
    return cos(angle * M_PI / 180);  // Convert to radians
}

double tangent(double angle) {
    return tan(angle * M_PI / 180);  // Convert to radians
}

double logarithm(double value) {
    if (value > 0)
        return log(value);
    else {
        printf("Error: Logarithm of non-positive value\n");
        return 0;
    }
}

int main() {
    int choice;
    double num1, num2;

    do {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", add(num1, num2));
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", subtract(num1, num2));
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", multiply(num1, num2));
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", divide(num1, num2));
                break;
            case 5:
                printf("Enter angle (degrees): ");
                scanf("%lf", &num1);
                printf("Result: %.2lf\n", sine(num1));
                break;
            case 6:
                printf("Enter angle (degrees): ");
                scanf("%lf", &num1);
                printf("Result: %.2lf\n", cosine(num1));
                break;
            case 7:
                printf("Enter angle (degrees): ");
                scanf("%lf", &num1);
                printf("Result: %.2lf\n", tangent(num1));
                break;
            case 8:
                printf("Enter a value: ");
                scanf("%lf", &num1);
                printf("Result: %.2lf\n", logarithm(num1));
                break;
            case 9:
                printf("Exiting calculator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
        
        printf("\n");
    } while (choice != 9);

    return 0;
}