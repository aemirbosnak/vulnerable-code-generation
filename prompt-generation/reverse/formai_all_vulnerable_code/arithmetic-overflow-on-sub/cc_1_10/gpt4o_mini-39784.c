//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
void displayMenu();

int main() {
    int choice;
    int num1, num2;
    
    do {
        displayMenu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter two integers: ");
        scanf("%d %d", &num1, &num2);

        switch (choice) {
            case 1:
                printf("Result of addition: %d\n", add(num1, num2));
                break;
            case 2:
                printf("Result of subtraction: %d\n", subtract(num1, num2));
                break;
            case 3:
                printf("Result of multiplication: %d\n", multiply(num1, num2));
                break;
            case 4:
                if (num2 != 0) {
                    printf("Result of division: %.2f\n", divide(num1, num2));
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to add two numbers recursively
int add(int a, int b) {
    if (b == 0) {
        return a;
    }
    return add(a + 1, b - 1);
}

// Function to subtract two numbers recursively
int subtract(int a, int b) {
    if (b == 0) {
        return a;
    }
    return subtract(a - 1, b - 1);
}

// Function to multiply two numbers recursively
int multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return add(a, multiply(a, b - 1));
}

// Function to divide two numbers recursively
float divide(int a, int b) {
    if (a < b) {
        return 0;
    }
    return 1 + divide(a - b, b);
}

// Function to display the menu of operations
void displayMenu() {
    printf("\n---- Arithmetic Operations ----\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("0. Exit\n");
}