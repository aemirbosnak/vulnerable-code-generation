//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void display_menu() {
    printf("*****************************\n");
    printf("*      SCIENTIFIC CALCULATOR  *\n");
    printf("*****************************\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Sin\n");
    printf("6. Cos\n");
    printf("7. Tan\n");
    printf("8. Exit\n");
    printf("Choose your quest (1-8): ");
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
        printf("Beware! Division by zero is a forbidden spell!\n");
        return 0; // Handle division by zero
    }
    return a / b;
}

double calculate_sin(double angle) {
    return sin(angle * PI / 180);
}

double calculate_cos(double angle) {
    return cos(angle * PI / 180);
}

double calculate_tan(double angle) {
    return tan(angle * PI / 180);
}

int main() {
    int choice;
    double num1, num2, result;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You chose the path of Addition.\n");
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Result of your addition: %.2lf\n", result);
                break;

            case 2:
                printf("You chose the path of Subtraction.\n");
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result of your subtraction: %.2lf\n", result);
                break;

            case 3:
                printf("You chose the path of Multiplication.\n");
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result of your multiplication: %.2lf\n", result);
                break;

            case 4:
                printf("You chose the path of Division.\n");
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = divide(num1, num2);
                if (num2 != 0) {
                    printf("Result of your division: %.2lf\n", result);
                }
                break;

            case 5:
                printf("You chose the path of Sine.\n");
                printf("Enter the angle in degrees: ");
                scanf("%lf", &num1);
                result = calculate_sin(num1);
                printf("Result of sin(%.2lf): %.2lf\n", num1, result);
                break;

            case 6:
                printf("You chose the path of Cosine.\n");
                printf("Enter the angle in degrees: ");
                scanf("%lf", &num1);
                result = calculate_cos(num1);
                printf("Result of cos(%.2lf): %.2lf\n", num1, result);
                break;

            case 7:
                printf("You chose the path of Tangent.\n");
                printf("Enter the angle in degrees: ");
                scanf("%lf", &num1);
                result = calculate_tan(num1);
                printf("Result of tan(%.2lf): %.2lf\n", num1, result);
                break;

            case 8:
                printf("Exiting... May your calculations be ever accurate!\n");
                break;

            default:
                printf("Alas! That is not a valid path. Choose again!\n");
                break;
        }

        printf("\n");
    } while (choice != 8);

    return 0;
}