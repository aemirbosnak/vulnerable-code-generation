//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
int getChoice();
float getNumber(const char *prompt);
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
int modulus(int a, int b);

int main() {
    int choice;
    float num1, num2;
    
    do {
        displayMenu();
        choice = getChoice();
        
        if (choice == 6) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        num1 = getNumber("Enter first number: ");
        if (choice == 5) {
            int intNum1 = (int) num1; // Casting to int for modulus
            num2 = getNumber("Enter second number (integer only): ");
            int intNum2 = (int) num2; // Casting to int
            printf("Result: %d\n", modulus(intNum1, intNum2));
            continue;
        }
        num2 = getNumber("Enter second number: ");
        
        switch (choice) {
            case 1:
                printf("Result: %.2f\n", add(num1, num2));
                break;
            case 2:
                printf("Result: %.2f\n", subtract(num1, num2));
                break;
            case 3:
                printf("Result: %.2f\n", multiply(num1, num2));
                break;
            case 4:
                if (num2 != 0) {
                    printf("Result: %.2f\n", divide(num1, num2));
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
        
    } while (1);

    return 0;
}

void displayMenu() {
    printf("\n--- Arithmetic Operations Menu ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("-----------------------------------\n");
}

int getChoice() {
    int choice;
    printf("Choose an operation (1-6): ");
    scanf("%d", &choice);
    return choice;
}

float getNumber(const char *prompt) {
    float number;
    printf("%s", prompt);
    scanf("%f", &number);
    return number;
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

int modulus(int a, int b) {
    if (b == 0) {
        printf("Error: Modulus by zero!\n");
        return -1; // Indicates an error
    }
    return a % b;
}