//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>

// Function prototypes
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void divide(int a, int b);
void modulus(int a, int b);
void display_menu();
void execute_operation(int choice, int a, int b);

int main() {
    int a, b, choice;
    
    printf("Welcome to the C Arithmetic Calculator!\n");
    
    // Input the two numbers
    printf("Please enter the first integer: ");
    scanf("%d", &a);
    
    printf("Please enter the second integer: ");
    scanf("%d", &b);

    // Menu for operation selection
    while (1) {
        display_menu();
        printf("Enter your choice (1-5 or 0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        execute_operation(choice, a, b);
    }
    
    return 0;
}

// Function to display the arithmetic operations menu
void display_menu() {
    printf("\nSelect an arithmetic operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("0. Exit\n");
}

// Function to execute the selected operation
void execute_operation(int choice, int a, int b) {
    switch (choice) {
        case 1:
            add(a, b);
            break;
        case 2:
            subtract(a, b);
            break;
        case 3:
            multiply(a, b);
            break;
        case 4:
            divide(a, b);
            break;
        case 5:
            modulus(a, b);
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
    }
}

// Function to perform addition
void add(int a, int b) {
    printf("Result of %d + %d = %d\n", a, b, a + b);
}

// Function to perform subtraction
void subtract(int a, int b) {
    printf("Result of %d - %d = %d\n", a, b, a - b);
}

// Function to perform multiplication
void multiply(int a, int b) {
    printf("Result of %d * %d = %d\n", a, b, a * b);
}

// Function to perform division
void divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result of %d / %d = %.2f\n", a, b, (float)a / b);
    }
}

// Function to perform modulus
void modulus(int a, int b) {
    if (b == 0) {
        printf("Error: Modulus by zero is not allowed.\n");
    } else {
        printf("Result of %d %% %d = %d\n", a, b, a % b);
    }
}