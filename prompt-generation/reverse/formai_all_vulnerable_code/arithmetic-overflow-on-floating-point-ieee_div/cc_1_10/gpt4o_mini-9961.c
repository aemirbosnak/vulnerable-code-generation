//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_OPERATIONS 5

// Enumeration for operations
typedef enum {
    ADDITION = 1,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    MODULUS
} Operation;

// Function prototypes
void displayMenu();
void performOperation(int operation, float num1, float num2);
bool askForConfiguration(int *operationCount, bool *showHistory);

int main() {
    int operationCount = MAX_OPERATIONS;
    bool showHistory = true;
    float num1, num2;
    int operation;
    char choice;

    // Setting up configuration from user
    if (!askForConfiguration(&operationCount, &showHistory)) {
        printf("Invalid configuration! Exiting program.\n");
        return 1;
    }

    // History storage
    float results[MAX_OPERATIONS] = {0}; 
    int resultCount = 0;

    do {
        displayMenu();
        printf("Choose an operation (1-%d): ", operationCount);
        scanf("%d", &operation);

        if (operation < 1 || operation > operationCount) {
            printf("Invalid operation! Please try again.\n");
            continue;
        }

        printf("Enter two numbers (separated by space): ");
        scanf("%f %f", &num1, &num2);

        // Performing operation
        performOperation(operation, num1, num2);
        
        // Store result for history
        if (showHistory && resultCount < MAX_OPERATIONS) {
            results[resultCount++] = (operation == ADDITION) ? (num1 + num2) :
                                       (operation == SUBTRACTION) ? (num1 - num2) :
                                       (operation == MULTIPLICATION) ? (num1 * num2) :
                                       (operation == DIVISION && num2 != 0) ? (num1 / num2) :
                                       (operation == MODULUS && ((int) num2 != 0)) ? ((int) num1 % (int) num2) : 0;
        }

        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');

    // Display history if enabled
    if (showHistory) {
        printf("\nHistory of Results:\n");
        for (int i = 0; i < resultCount; i++) {
            printf("Result %d: %.2f\n", i + 1, results[i]);
        }
    }

    printf("Thank you for using the arithmetic program!\n");
    return 0;
}

// Function to display the menu of operations
void displayMenu() {
    printf("\nArithmetic Operations Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("Please choose an operation:\n");
}

// Function to perform the selected arithmetic operation
void performOperation(int operation, float num1, float num2) {
    float result;
    switch (operation) {
        case ADDITION:
            result = num1 + num2;
            printf("Result of Addition: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case SUBTRACTION:
            result = num1 - num2;
            printf("Result of Subtraction: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case MULTIPLICATION:
            result = num1 * num2;
            printf("Result of Multiplication: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case DIVISION:
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result of Division: %.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                printf("Error: Division by zero is undefined!\n");
            }
            break;
        case MODULUS:
            if ((int)num2 != 0) {
                result = (int)num1 % (int)num2;
                printf("Result of Modulus: %.0f %% %.0f = %.0f\n", num1, num2, result);
            } else {
                printf("Error: Modulus by zero is undefined!\n");
            }
            break;
        default:
            printf("Invalid operation selected.\n");
    }
}

// Function to ask for configuration settings
bool askForConfiguration(int *operationCount, bool *showHistory) {
    printf("Configure your settings:\n");
    printf("Enter maximum number of operations (1-5): ");
    scanf("%d", operationCount);
    
    if (*operationCount < 1 || *operationCount > MAX_OPERATIONS) {
        return false;
    }

    char choice;
    printf("Would you like to show results history? (y/n): ");
    scanf(" %c", &choice);
    *showHistory = (choice == 'y' || choice == 'Y') ? true : false;

    return true;
}