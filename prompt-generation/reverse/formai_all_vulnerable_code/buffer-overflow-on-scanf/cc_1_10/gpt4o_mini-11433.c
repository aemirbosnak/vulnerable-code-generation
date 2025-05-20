//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("Welcome to the Simple C Calculator!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Square\n");
    printf("7. Exit\n");
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
        fprintf(stderr, "Error: Division by zero is not allowed.\n");
        return 0; // return 0 as a compromise
    }
    return a / b;
}

int modulus(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Error: Modulus by zero is not allowed.\n");
        return 0; // return 0 as a compromise
    }
    return a % b;
}

double square(double a) {
    return a * a;
}

int main() {
    int choice;
    double num1, num2;
    
    while (1) {
        displayMenu();
        
        printf("Enter your choice (1-7): ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number between 1 and 7.\n");
            while(getchar() != '\n'); // clear the invalid input
            continue; // prompt the menu again
        }
        
        if (choice == 7) {
            printf("Exiting the calculator. Goodbye!\n");
            break; // exit the loop
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2f\n", add(num1, num2));
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2f\n", subtract(num1, num2));
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2f\n", multiply(num1, num2));
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2f\n", divide(num1, num2));
                break;
            case 5:
                printf("Enter two integers: ");
                int int1, int2;
                scanf("%d %d", &int1, &int2);
                printf("Result: %d\n", modulus(int1, int2));
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("Result: %.2f\n", square(num1));
                break;
            default:
                fprintf(stderr, "Invalid choice. Please select a number between 1 and 7.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}