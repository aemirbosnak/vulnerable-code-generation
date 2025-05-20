//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayMenu() {
    printf("\n🌟 Welcome to the Happy Scientific Calculator! 🌟\n");
    printf("Choose an operation:\n");
    printf("1. Add (+)\n");
    printf("2. Subtract (-)\n");
    printf("3. Multiply (*)\n");
    printf("4. Divide (/)\n");
    printf("5. Square Root (√)\n");
    printf("6. Sine (sin)\n");
    printf("7. Cosine (cos)\n");
    printf("8. Tangent (tan)\n");
    printf("9. Exit\n");
    printf("Please enter your choice: ");
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
    if (b != 0) {
        return a / b;
    } else {
        printf("🤔 Oops! Division by zero is not allowed!\n");
        return NAN;
    }
}

double squareRoot(double a) {
    if (a < 0) {
        printf("🤔 Oops! Can't take the square root of a negative number!\n");
        return NAN;
    }
    return sqrt(a);
}

double sine(double angle) {
    return sin(angle * M_PI / 180.0);
}

double cosine(double angle) {
    return cos(angle * M_PI / 180.0);
}

double tangent(double angle) {
    if (cos(angle * M_PI / 180.0) == 0) {
        printf("🤔 Oops! Tan of 90 or 270 degrees is undefined!\n");
        return NAN;
    }
    return tan(angle * M_PI / 180.0);
}

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 9) {
            printf("🌈 Thank you for using the Happy Scientific Calculator! Goodbye! 🌈\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("✨ Result: %.2lf + %.2lf = %.2lf ✨\n", num1, num2, result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("✨ Result: %.2lf - %.2lf = %.2lf ✨\n", num1, num2, result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("✨ Result: %.2lf * %.2lf = %.2lf ✨\n", num1, num2, result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = divide(num1, num2);
                if (!isnan(result)) {
                    printf("✨ Result: %.2lf / %.2lf = %.2lf ✨\n", num1, num2, result);
                }
                break;

            case 5:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = squareRoot(num1);
                if (!isnan(result)) {
                    printf("✨ Result: √%.2lf = %.2lf ✨\n", num1, result);
                }
                break;

            case 6:
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = sine(num1);
                printf("✨ Result: sin(%.2lf°) = %.2lf ✨\n", num1, result);
                break;

            case 7:
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = cosine(num1);
                printf("✨ Result: cos(%.2lf°) = %.2lf ✨\n", num1, result);
                break;

            case 8:
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = tangent(num1);
                if (!isnan(result)) {
                    printf("✨ Result: tan(%.2lf°) = %.2lf ✨\n", num1, result);
                }
                break;

            default:
                printf("🤔 Hmm, that's not a valid choice! Please try again!\n");
        }
    }
    
    return 0;
}