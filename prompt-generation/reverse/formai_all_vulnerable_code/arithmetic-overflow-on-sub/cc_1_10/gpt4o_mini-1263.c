//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>

void displayMenu() {
    printf("\nArithmetic Operations Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("Choose an operation (1-6): ");
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
    if (b != 0) {
        return (float)a / b;
    } else {
        printf("Error: Division by zero is not allowed.\n");
        return 0.0; // Returning 0 as a fail-safe
    }
}

int modulus(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        printf("Error: Modulus by zero is not allowed.\n");
        return -1; // Returning -1 as a fail-safe
    }
}

int main() {
    int choice, num1, num2;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        if (choice == 6) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        
        if (choice < 1 || choice > 6) {
            printf("Invalid choice. Please select a valid operation.\n");
            continue;
        }
        
        printf("Enter the first number: ");
        scanf("%d", &num1);
        printf("Enter the second number: ");
        scanf("%d", &num2);
        
        switch (choice) {
            case 1:
                printf("%d + %d = %d\n", num1, num2, add(num1, num2));
                break;
            case 2:
                printf("%d - %d = %d\n", num1, num2, subtract(num1, num2));
                break;
            case 3:
                printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));
                break;
            case 4:
                printf("%d / %d = %.2f\n", num1, num2, divide(num1, num2));
                break;
            case 5:
                {
                    int result = modulus(num1, num2);
                    if (result != -1) {
                        printf("%d %% %d = %d\n", num1, num2, result);
                    }
                }
                break;
            default:
                printf("Unexpected error. Please try again.\n");
        }
    }

    return 0;
}