//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: medieval
#include <stdio.h>
#include <math.h>

// Function to display the menu of operations
void displayMenu() {
    printf("Welcome to the Enchanted Scientific Calculator!\n");
    printf("Please select thy desired operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Sine\n");
    printf("6. Cosine\n");
    printf("7. Logarithm (base 10)\n");
    printf("8. Exit\n");
}

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b == 0) {
        printf("Alas! Thou canst not divide by zero!\n");
        return -1; // Returning -1 as an indicator of error
    }
    return a / b;
}

// Function to calculate sine
double sine(double angle) {
    return sin(angle * (M_PI / 180)); // Convert degrees to radians
}

// Function to calculate cosine
double cosine(double angle) {
    return cos(angle * (M_PI / 180)); // Convert degrees to radians
}

// Function to calculate logarithm
double logarithm(double value) {
    if (value <= 0) {
        printf("Hark! Logarithm of non-positive numbers is invalid!\n");
        return -1; // Returning -1 as an indicator of error
    }
    return log10(value);
}

int main() {
    int choice;
    double firstNumber, secondNumber, result;

    while (1) {
        displayMenu();
        printf("What shall it be, brave soul? ");
        scanf("%d", &choice);

        if (choice == 8) {
            printf("Farewell, noble traveler!\n");
            break;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Enter the first number: ");
            scanf("%lf", &firstNumber);
            printf("Enter the second number: ");
            scanf("%lf", &secondNumber);
        } else if (choice == 5 || choice == 6) {
            printf("Enter the angle in degrees: ");
            scanf("%lf", &firstNumber); // Only one argument needed for sine and cosine
        } else if (choice == 7) {
            printf("Enter the number for logarithm: ");
            scanf("%lf", &firstNumber); // Only one argument needed for logarithm
        }

        switch (choice) {
            case 1:
                result = add(firstNumber, secondNumber);
                printf("The sum of thy numbers be: %.2lf\n", result);
                break;
            case 2:
                result = subtract(firstNumber, secondNumber);
                printf("The difference of thy numbers be: %.2lf\n", result);
                break;
            case 3:
                result = multiply(firstNumber, secondNumber);
                printf("The product of thy numbers be: %.2lf\n", result);
                break;
            case 4:
                result = divide(firstNumber, secondNumber);
                if (result != -1) {
                    printf("The quotient of thy numbers be: %.2lf\n", result);
                }
                break;
            case 5:
                result = sine(firstNumber);
                printf("The sine of thy angle be: %.2lf\n", result);
                break;
            case 6:
                result = cosine(firstNumber);
                printf("The cosine of thy angle be: %.2lf\n", result);
                break;
            case 7:
                result = logarithm(firstNumber);
                if (result != -1) {
                    printf("The logarithm of thy number be: %.2lf\n", result);
                }
                break;
            default:
                printf("Thy choice be invalid! Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}