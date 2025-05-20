//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: relaxed
#include <stdio.h>
#include <math.h>

void display_menu() {
    printf("\n=== Scientific Calculator ===\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Sine\n");
    printf("6. Cosine\n");
    printf("7. Tangent\n");
    printf("8. Square Root\n");
    printf("9. Exit\n");
    printf("============================\n");
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
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return NAN; // Not-a-Number
    }
    return a / b;
}

double sine(double angle) {
    return sin(angle * (M_PI / 180)); // Convert to radians
}

double cosine(double angle) {
    return cos(angle * (M_PI / 180)); // Convert to radians
}

double tangent(double angle) {
    return tan(angle * (M_PI / 180)); // Convert to radians
}

double square_root(double a) {
    if (a < 0) {
        printf("Error: Square root of negative number!\n");
        return NAN; // Not-a-Number
    }
    return sqrt(a);
}

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        display_menu();
        printf("Choose an operation (1-9): ");
        scanf("%d", &choice);

        if (choice == 9) {
            printf("Exiting the calculator. Have a great day!\n");
            break;
        }

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
                if (!isnan(result)) {
                    printf("Result: %.2lf\n", result);
                }
                break;
            case 5:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = sine(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 6:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = cosine(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 7:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = tangent(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 8:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = square_root(num1);
                if (!isnan(result)) {
                    printf("Result: %.2lf\n", result);
                }
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}