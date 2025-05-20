//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: mathematical
#include <stdio.h>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
long factorial(int n);
double power(double base, int exponent);
void displayMenu();

int main() {
    int choice, num1, num2;
    double base;
    int exponent, factNum;

    while (1) {
        displayMenu();
        printf("Choose an operation (1-6) or 0 to exit: ");
        scanf("%d", &choice);

        if(choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two integers for addition: ");
                scanf("%d %d", &num1, &num2);
                printf("Result: %d + %d = %d\n", num1, num2, add(num1, num2));
                break;

            case 2:
                printf("Enter two integers for subtraction: ");
                scanf("%d %d", &num1, &num2);
                printf("Result: %d - %d = %d\n", num1, num2, subtract(num1, num2));
                break;

            case 3:
                printf("Enter two integers for multiplication: ");
                scanf("%d %d", &num1, &num2);
                printf("Result: %d * %d = %d\n", num1, num2, multiply(num1, num2));
                break;

            case 4:
                printf("Enter two integers for division: ");
                scanf("%d %d", &num1, &num2);
                if (num2 != 0)
                    printf("Result: %d / %d = %.2f\n", num1, num2, divide(num1, num2));
                else
                    printf("Error: Division by zero is undefined.\n");
                break;

            case 5:
                printf("Enter an integer for factorial: ");
                scanf("%d", &factNum);
                if (factNum < 0)
                    printf("Error: Factorial is not defined for negative numbers.\n");
                else
                    printf("Result: %d! = %ld\n", factNum, factorial(factNum));
                break;

            case 6:
                printf("Enter base and exponent for power calculation (base exponent): ");
                scanf("%lf %d", &base, &exponent);
                printf("Result: %.2f ^ %d = %.2f\n", base, exponent, power(base, exponent));
                break;

            default:
                printf("Invalid choice. Please select a valid operation.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}

void displayMenu() {
    printf("Mathematical Operations Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Factorial\n");
    printf("6. Power\n");
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / b;
}

long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

double power(double base, int exponent) {
    double result = 1.0;
    int exp = exponent < 0 ? -exponent : exponent;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return exponent < 0 ? 1 / result : result;
}