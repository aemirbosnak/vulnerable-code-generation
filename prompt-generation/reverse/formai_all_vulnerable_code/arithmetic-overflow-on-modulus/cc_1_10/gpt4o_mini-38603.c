//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Alan Turing
#include <stdio.h>

void displayMenu() {
    printf("Welcome to the C Arithmetic Operations Program\n");
    printf("==========================================\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("==========================================\n");
}

double performAddition(double a, double b) {
    return a + b;
}

double performSubtraction(double a, double b) {
    return a - b;
}

double performMultiplication(double a, double b) {
    return a * b;
}

double performDivision(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0.0; // return zero for error handling
    }
    return a / b;
}

int performModulus(int a, int b) {
    if (b == 0) {
        printf("Error: Modulus by zero is not allowed.\n");
        return 0; // return zero for error handling
    }
    return a % b;
}

int main() {
    int choice;
    double num1, num2;
    
    while (1) {
        displayMenu();
        
        printf("Please enter your choice (1-6): ");
        scanf("%d", &choice);

        if (choice == 6) {
            printf("Thank you for using the C Arithmetic Operations Program. Goodbye!\n");
            break;
        }
        
        if (choice < 1 || choice > 6) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        printf("Enter the first number: ");
        scanf("%lf", &num1);

        printf("Enter the second number: ");
        scanf("%lf", &num2);

        switch (choice) {
            case 1: 
                printf("Result of %.2lf + %.2lf = %.2lf\n", num1, num2, performAddition(num1, num2));
                break;
            case 2: 
                printf("Result of %.2lf - %.2lf = %.2lf\n", num1, num2, performSubtraction(num1, num2));
                break;
            case 3: 
                printf("Result of %.2lf * %.2lf = %.2lf\n", num1, num2, performMultiplication(num1, num2));
                break;
            case 4: 
                printf("Result of %.2lf / %.2lf = %.2lf\n", num1, num2, performDivision(num1, num2));
                break;
            case 5: 
                // Convert numbers to integers for modulus
                printf("Result of %d %% %d = %d\n", (int)num1, (int)num2, performModulus((int)num1, (int)num2));
                break;
            default:
                printf("This choice is not valid, something has gone wrong.\n");
        }
        printf("\n");
    }
    
    return 0;
}