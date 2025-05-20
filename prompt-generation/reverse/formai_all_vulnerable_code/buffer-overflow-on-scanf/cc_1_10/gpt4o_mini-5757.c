//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

// Function declarations
void displayInstructions();
int performAddition(int a, int b);
int performSubtraction(int a, int b);
int performMultiplication(int a, int b);
float performDivision(int a, int b);
void logResult(const char* operation, int a, int b, float result);

int main() {
    printf("Welcome to the Arithmetic Enigma Solver!\n");
    printf("A case inspired by the logic of Sherlock Holmes.\n\n");

    displayInstructions();

    // Variables for arithmetic operations
    int num1, num2;
    char operation[MAX_CHARS];
    char continueChoice[MAX_CHARS];

    do {
        printf("Enter first number: ");
        scanf("%d", &num1);
        printf("Enter second number: ");
        scanf("%d", &num2);
        printf("Choose an operation (+, -, *, /): ");
        scanf("%s", operation);

        float result = 0.0;
        if (strcmp(operation, "+") == 0) {
            result = performAddition(num1, num2);
            logResult("Addition", num1, num2, result);
        } else if (strcmp(operation, "-") == 0) {
            result = performSubtraction(num1, num2);
            logResult("Subtraction", num1, num2, result);
        } else if (strcmp(operation, "*") == 0) {
            result = performMultiplication(num1, num2);
            logResult("Multiplication", num1, num2, result);
        } else if (strcmp(operation, "/") == 0) {
            if (num2 != 0) {
                result = performDivision(num1, num2);
                logResult("Division", num1, num2, result);
            } else {
                printf("Error: Division by zero is not allowed!\n");
            }
        } else {
            printf("Error: Invalid operation selected.\n");
        }

        // Asking the detective if he wants to calculate again
        printf("Would you like to perform another calculation? (yes/no): ");
        scanf("%s", continueChoice);
    } while (strcmp(continueChoice, "yes") == 0);

    printf("Thank you for using the Arithmetic Enigma Solver.\n");
    printf("May your calculations always be correct!\n");
    return 0;
}

// Function to display instructions
void displayInstructions() {
    printf("Instructions:\n");
    printf("1. Enter two integers to perform arithmetic operations.\n");
    printf("2. Choose one of the following operations:\n");
    printf("   + : Addition\n");
    printf("   - : Subtraction\n");
    printf("   * : Multiplication\n");
    printf("   / : Division\n");
    printf("3. The result will be calculated and logged.\n");
    printf("4. You may perform another calculation or exit the program.\n\n");
}

// Function for addition
int performAddition(int a, int b) {
    return a + b;
}

// Function for subtraction
int performSubtraction(int a, int b) {
    return a - b;
}

// Function for multiplication
int performMultiplication(int a, int b) {
    return a * b;
}

// Function for division
float performDivision(int a, int b) {
    return (float)a / b;
}

// Function to log results in a detective style
void logResult(const char* operation, int a, int b, float result) {
    printf("Holmes deduces: The result of %d %s %d is %.2f.\n", a, operation, b, result);
}