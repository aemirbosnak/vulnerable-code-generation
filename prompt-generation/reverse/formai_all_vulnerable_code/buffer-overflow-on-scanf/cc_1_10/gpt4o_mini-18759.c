//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OPERANDS 10  // Maximum number of operands for calculations

// Define operations
typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MODULO,
    NUM_OPERATIONS
} Operation;

// Function prototypes
void performOperations(int *operands, int numOperands, Operation operation);
void displayMenu();
void clearBuffer();

int main() {
    srand(time(0));  // Seed for random number generation
    int operands[MAX_OPERANDS];
    int numOperands = 0;
    int choice;
    Operation operation;

    // User input for number of operands
    printf("Welcome to the C Arithmetic Adventure!\n");
    printf("How many random numbers would you like to generate (max %d)? ", MAX_OPERANDS);
    if (scanf("%d", &numOperands) != 1 || numOperands < 2 || numOperands > MAX_OPERANDS) {
        printf("Invalid input! Defaulting to 2 operands.\n");
        numOperands = 2;
    }
    
    // Generate random operands
    printf("Generating %d random operands...\n", numOperands);
    for (int i = 0; i < numOperands; i++) {
        operands[i] = rand() % 100 + 1;  // Values between 1 and 100
    }
    
    printf("Operands: ");
    for (int i = 0; i < numOperands; i++) {
        printf("%d ", operands[i]);
    }
    printf("\n");

    // Main loop
    while (1) {
        displayMenu();
        
        if (scanf("%d", &choice) != 1 || choice < 0 || choice >= NUM_OPERATIONS) {
            printf("Invalid choice! Please select a valid operation.\n");
            clearBuffer();  // Clear the input buffer
            continue;
        }

        if (choice == NUM_OPERATIONS - 1) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        operation = (Operation)choice;

        // Perform selected operation
        performOperations(operands, numOperands, operation);
    }

    return 0;
}

// Function to perform selected arithmetic operations
void performOperations(int *operands, int numOperands, Operation operation) {
    int result = operands[0];
    
    for (int i = 1; i < numOperands; i++) {
        switch (operation) {
            case ADD:
                result += operands[i];
                break;
            case SUBTRACT:
                result -= operands[i];
                break;
            case MULTIPLY:
                result *= operands[i];
                break;
            case DIVIDE:
                if (operands[i] != 0) {
                    result /= operands[i];
                } else {
                    printf("Division by zero is not allowed! Continuing with last valid result.\n");
                }
                break;
            case MODULO:
                if (operands[i] != 0) {
                    result %= operands[i];
                } else {
                    printf("Modulo by zero is not allowed! Continuing with last valid result.\n");
                }
                break;
            default:
                break;
        }
    }
    
    // Display the result
    switch (operation) {
        case ADD:
            printf("Result of Addition: %d\n", result);
            break;
        case SUBTRACT:
            printf("Result of Subtraction: %d\n", result);
            break;
        case MULTIPLY:
            printf("Result of Multiplication: %d\n", result);
            break;
        case DIVIDE:
            printf("Result of Division: %d\n", result);
            break;
        case MODULO:
            printf("Result of Modulo: %d\n", result);
            break;
        default:
            break;
    }
}

// Function to display available operations
void displayMenu() {
    printf("Select an operation to perform:\n");
    printf("0: Addition\n");
    printf("1: Subtraction\n");
    printf("2: Multiplication\n");
    printf("3: Division\n");
    printf("4: Modulo\n");
    printf("5: Exit\n");
    printf("Enter your choice: ");
}

// Function to clear the input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}