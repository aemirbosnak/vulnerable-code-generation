//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>

// Function prototypes
void displayMenu();
void performOperation(int choice);

int main() {
    int choice;
    
    printf("Welcome to the Brave Calculator!\n");
    
    do {
        displayMenu();
        printf("Choose an operation (1-5, or 0 to exit): ");
        scanf("%d", &choice);
        
        if (choice < 0 || choice > 5) {
            printf("Invalid choice! Please choose again.\n");
        } else if (choice != 0) {
            performOperation(choice);
        }
    } while (choice != 0);

    printf("Thank you for using the Brave Calculator. Goodbye!\n");
    return 0;
}

void displayMenu() {
    printf("\n------- Brave Calculator -------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Calculate Power\n");
    printf("0. Exit\n");
    printf("--------------------------------\n");
}

void performOperation(int choice) {
    float num1, num2, result;

    switch(choice) {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%f %f", &num1, &num2);
            if (num2 == 0) {
                printf("Error! Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
            }
            break;
        case 5:
            printf("Enter base and exponent: ");
            scanf("%f %f", &num1, &num2);
            result = 1;
            for (int i = 0; i < (int)num2; i++) {
                result *= num1;
            }
            printf("Result: %.2f ^ %.2f = %.2f\n", num1, num2, result);
            break;
        default:
            printf("Invalid operation! Please try again.\n");
            break;
    }
}