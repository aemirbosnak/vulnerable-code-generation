//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100
#define OPERATOR_COUNT 4

// Enumeration for different mathematical operations
typedef enum {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
} Operator;

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to perform calculation based on the operator
double calculate(double a, double b, Operator op) {
    switch (op) {
        case ADDITION:
            return a + b;
        case SUBTRACTION:
            return a - b;
        case MULTIPLICATION:
            return a * b;
        case DIVISION:
            if (b != 0) {
                return a / b;
            } else {
                printf("Division by zero error!\n");
                exit(EXIT_FAILURE);
            }
        default:
            printf("Unknown operator!\n");
            exit(EXIT_FAILURE);
    }
}

// Function to display the operation and result
void display_result(double a, double b, Operator op) {
    const char *operators[OPERATOR_COUNT] = {"+", "-", "*", "/"};
    double result = calculate(a, b, op);
    printf("What is %g %s %g? The answer is: %g\n", a, operators[op], b, result);
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Define variables
    double num1, num2;
    Operator op;
    char choice;

    // Start the arithmetic quiz
    printf("Welcome to the Surprise Arithmetic Quiz!\n");
    printf("You will solve some unexpected arithmetic problems. Are you ready? (y/n): ");
    scanf(" %c", &choice);
    
    while (choice == 'y' || choice == 'Y') {
        // Generate two random numbers
        num1 = random_number(1, MAX_NUM);
        num2 = random_number(1, MAX_NUM);
        
        // Randomly select an operator
        op = random_number(0, OPERATOR_COUNT - 1);
        
        // Display the result
        display_result(num1, num2, op);
        
        // Ask if the user wants to continue
        printf("Would you like to solve another problem? (y/n): ");
        scanf(" %c", &choice);
    }

    // Thank the user
    printf("Thank you for participating! Stay curious and keep calculating!\n");
    return 0;
}