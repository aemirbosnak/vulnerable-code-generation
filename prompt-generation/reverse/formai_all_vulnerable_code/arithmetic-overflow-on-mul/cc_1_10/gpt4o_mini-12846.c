//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>

// Function prototypes
void displayMenu();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
int modulus(int a, int b);

int main() {
    int choice, num1, num2;
    float result;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-5 or 0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter two integers: ");
        scanf("%d %d", &num1, &num2);

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result of addition: %d\n", (int)result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result of subtraction: %d\n", (int)result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result of multiplication: %d\n", (int)result);
                break;
            case 4:
                if (num2 != 0) {
                    result = divide(num1, num2);
                    printf("Result of division: %.2f\n", result);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;
            case 5:
                if (num2 != 0) {
                    result = modulus(num1, num2);
                    printf("Result of modulus: %d\n", (int)result);
                } else {
                    printf("Error: Modulus by zero is not allowed.\n");
                }
                break;
            default:
                printf("Invalid choice! Please select a valid operation.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}

// Function to display the menu options
void displayMenu() {
    printf("----- Arithmetic Operations Menu -----\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("-------------------------------------\n");
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
    return (float)a / (float)b;
}

// Function for modulus
int modulus(int a, int b) {
    return a % b;
}