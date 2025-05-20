//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void clearInputBuffer();
int isNumber(const char *str);
void performArithmetic(int num1, int num2, char operator);
void displayMenu();
void takeUserInput(int *num1, int *num2, char *operator);

int main() {
    int num1 = 0, num2 = 0;
    char operator;
    char choice;

    do {
        displayMenu(); // Display the arithmetic menu
        takeUserInput(&num1, &num2, &operator); // Take user input for numbers and operator
        performArithmetic(num1, num2, operator); // Perform selected arithmetic operation
        
        printf("\nWould you like to perform another operation? (y/n): ");
        scanf(" %c", &choice);
        clearInputBuffer(); // Clear the input buffer to prevent unwanted input issues
    } while (tolower(choice) == 'y');
    
    printf("Thank you for using the arithmetic calculator. Goodbye!\n");
    return 0;
}

// Displays the arithmetic operations menu
void displayMenu() {
    printf("\n--- Arithmetic Operations Menu ---\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("Please enter the operation (+, -, *, /): ");
}

// Takes user input for two numbers and an operator
void takeUserInput(int *num1, int *num2, char *operator) {
    char temp[100];

    // Reading first number
    printf("Enter the first number: ");
    while (1) {
        scanf("%s", temp);
        if (isNumber(temp)) {
            *num1 = atoi(temp);
            break;
        } else {
            printf("Invalid input. Please enter a valid number: ");
        }
    }
    
    // Reading second number
    printf("Enter the second number: ");
    while (1) {
        scanf("%s", temp);
        if (isNumber(temp)) {
            *num2 = atoi(temp);
            break;
        } else {
            printf("Invalid input. Please enter a valid number: ");
        }
    }
    
    // Reading operator
    while (1) {
        printf("Enter the operation (+, -, *, /): ");
        scanf(" %c", operator);
        if (*operator == '+' || *operator == '-' || *operator == '*' || *operator == '/') {
            break;
        } else {
            printf("Invalid operator. Please enter +, -, * or /: ");
        }
    }
    clearInputBuffer(); // Clear input buffer again
}

// Validates if input string can be converted to a number
int isNumber(const char *str) {
    if (*str == '\0') return 0; // If string is empty
    while (*str) {
        if (!isdigit(*str)) return 0; // Check if character is a digit
        str++;
    }
    return 1; // Return true if all characters are digits
}

// Performs the arithmetic operation based on the operator provided
void performArithmetic(int num1, int num2, char operator) {
    switch (operator) {
        case '+':
            printf("Result of %d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("Result of %d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("Result of %d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("Result of %d / %d = %.2f\n", num1, num2, (float)num1 / num2);
            } else {
                printf("Error: Division by zero is undefined.\n");
            }
            break;
        default:
            printf("Unexpected error occurred.\n");
    }
}

// Clears the input buffer to handle any leftover characters
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}