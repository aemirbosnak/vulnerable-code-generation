//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void displayMenu();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
void computeAndDisplayResults(int a, int b);

int main() {
    int num1, num2, choice;
    char continueCalc;

    printf("Welcome to the Arithmetic Calculator!\n");
    
    do {
        printf("Please enter two integers:\n");
        printf("Enter first number: ");
        scanf("%d", &num1);
        printf("Enter second number: ");
        scanf("%d", &num2);
        
        // Ensure the second number is not zero for division
        if (num2 == 0) {
            printf("Division by zero is not allowed. Please choose another second number.\n");
            continue;
        }

        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        computeAndDisplayResults(num1, num2);
        
        printf("\nDo you want to perform another calculation? (Y/N): ");
        getchar(); // To consume the newline character left by scanf
        scanf("%c", &continueCalc);

    } while (continueCalc == 'Y' || continueCalc == 'y');

    printf("Thank you for using the Arithmetic Calculator! Goodbye!\n");
    return 0;
}

void displayMenu() {
    printf("\nArithmetic Operations Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Choose an operation from the above list.\n");
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

void computeAndDisplayResults(int a, int b) {
    int sum, diff, product, choice;
    float quotient;

    printf("\nEnter the operation you want to calculate:\n");
    printf("1 for Addition\n2 for Subtraction\n3 for Multiplication\n4 for Division\n");
    scanf("%d", &choice); 

    switch (choice) {
        case 1:
            sum = add(a, b);
            printf("The result of %d + %d is: %d\n", a, b, sum);
            break;
        case 2:
            diff = subtract(a, b);
            printf("The result of %d - %d is: %d\n", a, b, diff);
            break;
        case 3:
            product = multiply(a, b);
            printf("The result of %d * %d is: %d\n", a, b, product);
            break;
        case 4:
            quotient = divide(a, b);
            printf("The result of %d / %d is: %.2f\n", a, b, quotient);
            break;
        default:
            printf("Invalid choice! Please select a valid operation.\n");
            break;
    }
}

// Congratulations! You have created a simple yet effective arithmetic calculator. 
// This program efficiently handles basic arithmetic operations and ensures 
// the user is guided through each step, making it great for anyone 
// looking to perform calculations with ease.