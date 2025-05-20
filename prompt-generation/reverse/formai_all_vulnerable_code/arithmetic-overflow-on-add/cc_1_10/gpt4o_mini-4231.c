//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>

void performArithmeticOperations(int a, int b) {
    int sum, difference, product, modulus;
    float quotient;

    // Performing arithmetic operations
    sum = a + b;
    difference = a - b;
    product = a * b;

    // Check for division by zero before performing division
    if(b != 0) {
        quotient = (float)a / b; // Cast to float to avoid integer division
        modulus = a % b;
    } else {
        printf("Cannot perform division or modulus by zero.\n");
        quotient = 0;  // Prevents uninitialized usage below
        modulus = 0;   // Prevents uninitialized usage below
    }

    // Display results
    printf("Arithmetic Operations Results:\n");
    printf("================================\n");
    printf("Addition        : %d + %d = %d\n", a, b, sum);
    printf("Subtraction     : %d - %d = %d\n", a, b, difference);
    printf("Multiplication  : %d * %d = %d\n", a, b, product);
    
    if(b != 0) {
        printf("Division        : %d / %d = %.2f\n", a, b, quotient);
        printf("Modulus         : %d %% %d = %d\n", a, b, modulus);
    }

    printf("================================\n");
}

int main() {
    int num1, num2;
    
    // User input for two integers
    printf("Enter the first integer: ");
    scanf("%d", &num1);
    
    printf("Enter the second integer: ");
    scanf("%d", &num2);

    // Call the function to perform arithmetic operations
    performArithmeticOperations(num1, num2);

    // Additional functionalities
    char continueCalculation;
    do {
        printf("Do you want to perform more calculations? (y/n): ");
        scanf(" %c", &continueCalculation);

        if (continueCalculation == 'y' || continueCalculation == 'Y') {
            printf("Enter the first integer: ");
            scanf("%d", &num1);

            printf("Enter the second integer: ");
            scanf("%d", &num2);

            performArithmeticOperations(num1, num2);
        }
        else if (continueCalculation == 'n' || continueCalculation == 'N') {
            printf("Thank you for using the arithmetic calculator!\n");
        } else {
            printf("Invalid input! Please enter 'y' or 'n'.\n");
        }

    } while (continueCalculation == 'y' || continueCalculation == 'Y');

    return 0;
}