//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>

void add(float a, float b) {
    printf("Result of addition: %.2f\n", a + b);
}

void subtract(float a, float b) {
    printf("Result of subtraction: %.2f\n", a - b);
}

void multiply(float a, float b) {
    printf("Result of multiplication: %.2f\n", a * b);
}

void divide(float a, float b) {
    if (b != 0) {
        printf("Result of division: %.2f\n", a / b);
    } else {
        printf("Error: Division by zero is undefined.\n");
    }
}

void modulus(int a, int b) {
    if (b != 0) {
        printf("Result of modulus: %d\n", a % b);
    } else {
        printf("Error: Modulus by zero is undefined.\n");
    }
}

void displayMenu() {
    printf("\n--- Simple Calculator ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("Choose an operation (1-6): ");
}

int main() {
    int choice;
    float num1, num2;
    int intNum1, intNum2;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 6) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            printf("Invalid choice! Please select a number between 1 and 6.\n");
            continue;
        }

        printf("Enter the first number: ");
        scanf("%f", &num1);
        
        if (choice == 5) {
            printf("For modulus operation, please enter integers only.\n");
            printf("Enter the first integer: ");
            scanf("%d", &intNum1);
            printf("Enter the second integer: ");
            scanf("%d", &intNum2);
        } else {
            printf("Enter the second number: ");
            scanf("%f", &num2);
        }

        switch (choice) {
            case 1:
                add(num1, num2);
                break;
            case 2:
                subtract(num1, num2);
                break;
            case 3:
                multiply(num1, num2);
                break;
            case 4:
                divide(num1, num2);
                break;
            case 5:
                modulus(intNum1, intNum2);
                break;
            default:
                printf("An unknown error occurred.\n");
        }

        char continueCalculating;
        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &continueCalculating);
        if (continueCalculating == 'n' || continueCalculating == 'N') {
            printf("Thank you for using the calculator. Goodbye!\n");
            break;
        }
    }
    
    return 0;
}