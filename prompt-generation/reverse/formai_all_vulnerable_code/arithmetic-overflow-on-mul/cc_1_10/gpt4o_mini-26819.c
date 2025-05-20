//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>

// Function prototypes
void displayMenu();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

int main() {
    int choice;
    int num1, num2;
    float result;

    while (1) {
        displayMenu();
        
        // Taking user input for the choice
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        // If the user chooses to exit
        if (choice == 5) {
            printf("Exiting the program. Have a nice day!\n");
            break;
        }
        
        // Requesting the numbers for calculations
        printf("Enter the first number: ");
        scanf("%d", &num1);
        printf("Enter the second number: ");
        scanf("%d", &num2);
        
        // Perform the desired operation
        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("The result of %d + %d = %.2f\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("The result of %d - %d = %.2f\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("The result of %d * %d = %.2f\n", num1, num2, result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is undefined.\n");
                } else {
                    result = divide(num1, num2);
                    printf("The result of %d / %d = %.2f\n", num1, num2, result);
                }
                break;
            default:
                printf("Invalid choice. Please choose a valid option from the menu.\n");
        }
        
        printf("\n"); // Just for better readability in output
    }
    
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Simple Calculator ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
}

// Function for addition
int add(int a, int b) {
    return a + b;
}

// Function for subtraction
int subtract(int a, int b) {
    return a - b;
}

// Function for multiplication
int multiply(int a, int b) {
    return a * b;
}

// Function for division
float divide(int a, int b) {
    return (float)a / b;
}