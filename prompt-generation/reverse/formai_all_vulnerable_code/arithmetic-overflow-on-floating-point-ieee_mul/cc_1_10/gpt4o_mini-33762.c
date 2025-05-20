//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: decentralized
#include <stdio.h>

void add(float a, float b);
void subtract(float a, float b);
void multiply(float a, float b);
void divide(float a, float b);
void modulus(int a, int b);
void displayMenu();
int getChoice();
float getOperand(const char* prompt);

int main() {
    int choice;
    float num1, num2;
    int intNum1, intNum2;

    do {
        displayMenu();
        choice = getChoice();

        switch (choice) {
            case 1:
                num1 = getOperand("Enter first number: ");
                num2 = getOperand("Enter second number: ");
                add(num1, num2);
                break;
            case 2:
                num1 = getOperand("Enter first number: ");
                num2 = getOperand("Enter second number: ");
                subtract(num1, num2);
                break;
            case 3:
                num1 = getOperand("Enter first number: ");
                num2 = getOperand("Enter second number: ");
                multiply(num1, num2);
                break;
            case 4:
                num1 = getOperand("Enter first number: ");
                num2 = getOperand("Enter second number: ");
                divide(num1, num2);
                break;
            case 5:
                intNum1 = (int)getOperand("Enter first integer: ");
                intNum2 = (int)getOperand("Enter second integer: ");
                modulus(intNum1, intNum2);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        printf("\n");

    } while (choice != 6);

    return 0;
}

void add(float a, float b) {
    printf("Result: %.2f + %.2f = %.2f\n", a, b, a + b);
}

void subtract(float a, float b) {
    printf("Result: %.2f - %.2f = %.2f\n", a, b, a - b);
}

void multiply(float a, float b) {
    printf("Result: %.2f * %.2f = %.2f\n", a, b, a * b);
}

void divide(float a, float b) {
    if (b != 0) {
        printf("Result: %.2f / %.2f = %.2f\n", a, b, a / b);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

void modulus(int a, int b) {
    if (b != 0) {
        printf("Result: %d %% %d = %d\n", a, b, a % b);
    } else {
        printf("Error: Modulus by zero is not allowed.\n");
    }
}

void displayMenu() {
    printf("Arithmetic Operations Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus (Integer)\n");
    printf("6. Exit\n");
}

int getChoice() {
    int choice;
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    return choice;
}

float getOperand(const char* prompt) {
    float value;
    printf("%s", prompt);
    scanf("%f", &value);
    return value;
}