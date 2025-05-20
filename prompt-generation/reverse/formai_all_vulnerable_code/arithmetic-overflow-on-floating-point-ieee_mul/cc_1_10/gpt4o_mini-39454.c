//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function to perform division with error handling
float safe_divide(float numerator, float denominator) {
    if (denominator == 0) {
        errno = EDOM; // Set the error number to domain error
        return 0; // Return 0 to signify an error
    }
    return numerator / denominator;
}

// Function to read an integer from user input with error handling
int get_integer_input() {
    int number;
    char term;

    while (1) {
        printf("Enter an integer: ");
        if (scanf("%d%c", &number, &term) != 2 || term != '\n') {
            printf("Invalid input! Please enter a valid integer.\n");
            while (getchar() != '\n'); // Clear invalid input from buffer
        } else {
            return number;
        }
    }
}

// Function to read a float from user input with error handling
float get_float_input() {
    float number;
    char term;

    while (1) {
        printf("Enter a float: ");
        if (scanf("%f%c", &number, &term) != 2 || term != '\n') {
            printf("Invalid input! Please enter a valid float.\n");
            while (getchar() != '\n'); // Clear invalid input from buffer
        } else {
            return number;
        }
    }
}

// Main computation function
void perform_operations() {
    int int1 = get_integer_input();
    int int2 = get_integer_input();
    
    printf("You entered integers: %d and %d\n", int1, int2);
    printf("Sum: %d + %d = %d\n", int1, int2, int1 + int2);
    printf("Difference: %d - %d = %d\n", int1, int2, int1 - int2);
    printf("Product: %d * %d = %d\n", int1, int2, int1 * int2);
    
    // Float operations
    float float1 = get_float_input();
    float float2 = get_float_input();
    
    printf("You entered floats: %.2f and %.2f\n", float1, float2);
    printf("Sum: %.2f + %.2f = %.2f\n", float1, float2, float1 + float2);
    printf("Difference: %.2f - %.2f = %.2f\n", float1, float2, float1 - float2);
    printf("Product: %.2f * %.2f = %.2f\n", float1, float2, float1 * float2);
    
    // Division with error handling
    float result = safe_divide(float1, float2);
    
    if (errno == EDOM) {
        printf("Error: Division by zero is not allowed!\n");
    } else {
        printf("Division: %.2f / %.2f = %.2f\n", float1, float2, result);
    }
}

// Function to continue or exit the program
int continue_or_exit() {
    char choice;
    
    while (1) {
        printf("Would you like to perform another operation? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'y' || choice == 'Y') {
            return 1; // Continue
        } else if (choice == 'n' || choice == 'N') {
            return 0; // Exit
        } else {
            printf("Invalid choice! Please enter 'y' or 'n'.\n");
        }
    }
}

int main() {
    printf("Welcome to the C Error Handling Example Program!\n");
    
    while (1) {
        perform_operations();
        
        if (!continue_or_exit()) {
            break; // Exit the program
        }
    }
    
    printf("Thank you for using the program! Goodbye!\n");
    return 0;
}