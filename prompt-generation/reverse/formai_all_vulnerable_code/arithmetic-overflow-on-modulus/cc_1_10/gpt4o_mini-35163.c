//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>

// Function to add two numbers
float add(float a, float b) {
    return a + b;
}

// Function to subtract two numbers
float subtract(float a, float b) {
    return a - b;
}

// Function to multiply two numbers
float multiply(float a, float b) {
    return a * b;
}

// Function to divide two numbers
float divide(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero is not allowed.\n");
        return 0; // Returning 0, should ideally handle this case better
    }
}

// Function to calculate the modulus of two numbers
int modulus(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        printf("Error: Modulus by zero is not allowed.\n");
        return 0; // Returning 0, should ideally handle this case better
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Simple Arithmetic Operations ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("-----------------------------------\n");
}

// Main function
int main() {
    int choice;
    float num1, num2;
    int intNum1, intNum2;

    while (1) {
        displayMenu();
        printf("Please select an option (1-6): ");
        scanf("%d", &choice);

        // Checking the user's choice
        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                printf("Result: %.2f\n", add(num1, num2));
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                printf("Result: %.2f\n", subtract(num1, num2));
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                printf("Result: %.2f\n", multiply(num1, num2));
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                printf("Result: %.2f\n", divide(num1, num2));
                break;
            case 5:
                printf("Enter two integers: ");
                scanf("%d %d", &intNum1, &intNum2);
                printf("Result: %d\n", modulus(intNum1, intNum2));
                break;
            case 6:
                printf("Thank you for using the Simple Arithmetic Program!\n");
                return 0; // Exiting the program
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
    
    return 0;
}