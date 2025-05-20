//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
void performArithmetic(int choice, int num1, int num2);

int main() {
    int num1, num2, choice;
    
    printf("Welcome to the C Arithmetic Program!\n");
    printf("Please enter the first integer: ");
    scanf("%d", &num1);
    printf("Please enter the second integer: ");
    scanf("%d", &num2);
    
    while (1) {
        displayMenu();
        printf("Enter your choice (1-5 to perform operation, 0 to exit): ");
        scanf("%d", &choice);
        
        if(choice == 0) {
            printf("Exiting program. Thank you for using the C Arithmetic Program!\n");
            break;
        }
        
        performArithmetic(choice, num1, num2);
    }
    
    return 0;
}

void displayMenu() {
    printf("\nArithmetic Operations Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
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
    if (b == 0) {
        printf("Error: Division by zero is not allowed!\n");
        return 0.0f; // Returning 0.0f for division error
    }
    return (float)a / (float)b;
}

int modulus(int a, int b) {
    if (b == 0) {
        printf("Error: Modulus by zero is not allowed!\n");
        return 0; // Returning 0 for modulus error
    }
    return a % b;
}

void performArithmetic(int choice, int num1, int num2) {
    int result;
    float divisionResult;
    
    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Result of %d + %d = %d\n", num1, num2, result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result of %d - %d = %d\n", num1, num2, result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result of %d * %d = %d\n", num1, num2, result);
            break;
        case 4:
            divisionResult = divide(num1, num2);
            if (num2 != 0) {
                printf("Result of %d / %d = %.2f\n", num1, num2, divisionResult);
            }
            break;
        case 5:
            result = modulus(num1, num2);
            if (num2 != 0) {
                printf("Result of %d %% %d = %d\n", num1, num2, result);
            }
            break;
        default:
            printf("Invalid choice! Please choose a valid operation.\n");
            break;
    }
}