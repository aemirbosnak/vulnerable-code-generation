//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <math.h>

// Function prototypes
void showWelcomeMessage();
void showMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double squareRoot(double a);
double sine(double a);
double cosine(double a);
double tangent(double a);

int main() {
    showWelcomeMessage();
    
    int choice;
    double num1, num2, result;

    while (1) {
        showMenu();
        printf("Please enter your choice (1-8), or 0 to exit: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Thank you for using our Happy Scientific Calculator! Have a wonderful day!\n");
            break;
        }

        if (choice < 1 || choice > 8) {
            printf("Oops! That's not a valid choice. Please try again!\n");
            continue;
        }

        if (choice <= 5) {
            printf("Please enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
        } else {
            printf("Please enter a number: ");
            scanf("%lf", &num1);
        }

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("The sum of %.2f and %.2f is: %.2f\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("The difference between %.2f and %.2f is: %.2f\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("The product of %.2f and %.2f is: %.2f\n", num1, num2, result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Oh, no! Can't divide by zero! Try again.\n");
                } else {
                    result = divide(num1, num2);
                    printf("The quotient of %.2f and %.2f is: %.2f\n", num1, num2, result);
                }
                break;
            case 5:
                result = squareRoot(num1);
                printf("The square root of %.2f is: %.2f\n", num1, result);
                break;
            case 6:
                result = sine(num1);
                printf("The sine of %.2f radians is: %.2f\n", num1, result);
                break;
            case 7:
                result = cosine(num1);
                printf("The cosine of %.2f radians is: %.2f\n", num1, result);
                break;
            case 8:
                result = tangent(num1);
                printf("The tangent of %.2f radians is: %.2f\n", num1, result);
                break;
            default:
                printf("Something went wrong! Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}

void showWelcomeMessage() {
    printf("🎉 Welcome to the Happy Scientific Calculator! 🎉\n");
    printf("This calculator is here to make your calculations fun and efficient!\n\n");
}

void showMenu() {
    printf("📋 Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Sine\n");
    printf("7. Cosine\n");
    printf("8. Tangent\n");
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
    return a / b;
}

double squareRoot(double a) {
    return sqrt(a);
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