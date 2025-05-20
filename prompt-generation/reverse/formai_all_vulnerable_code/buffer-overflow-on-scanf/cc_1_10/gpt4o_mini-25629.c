//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_OPERATIONS 5

// Function prototypes
void display_menu();
int get_random_int(int min, int max);
double perform_operation(int operation, double num1, double num2);
void handle_operation(int operation, double num1, double num2);

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation

    double num1, num2;
    int operation, choice;

    do {
        display_menu();
        printf("Choose an operation (0 to exit): ");
        scanf("%d", &operation);

        if (operation < 0 || operation >= MAX_OPERATIONS) {
            if (operation != 0) {
                printf("Invalid choice! Please try again.\n");
            }
            continue;
        }

        // Generate two random numbers for the operation
        num1 = get_random_int(1, 100);
        num2 = get_random_int(1, 100);

        handle_operation(operation, num1, num2);

        printf("Do you want to perform another operation? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice != 0);

    printf("Thank you for using the Math operations program!\n");
    return 0;
}

// Function to display menu options
void display_menu() {
    printf("\n--- Math Operations Menu ---\n");
    printf("0: Exit\n");
    printf("1: Addition\n");
    printf("2: Subtraction\n");
    printf("3: Multiplication\n");
    printf("4: Division\n");
    printf("5: Power\n");
}

// Function to get a random integer between min and max (inclusive)
int get_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to perform the selected operation
double perform_operation(int operation, double num1, double num2) {
    switch (operation) {
        case 1:
            return num1 + num2; // Addition
        case 2:
            return num1 - num2; // Subtraction
        case 3:
            return num1 * num2; // Multiplication
        case 4:
            if (num2 != 0) {
                return num1 / num2; // Division
            } else {
                printf("Error: Division by zero!\n");
                return NAN; // Return Not-a-Number
            }
        case 5:
            return pow(num1, num2); // Power
        default:
            return NAN;
    }
}

// Function to handle the operation and display the result
void handle_operation(int operation, double num1, double num2) {
    double result = perform_operation(operation, num1, num2);
    
    printf("Numbers generated: %.2f and %.2f\n", num1, num2);
    switch (operation) {
        case 1:
            printf("Result of Addition: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case 2:
            printf("Result of Subtraction: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case 3:
            printf("Result of Multiplication: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case 4:
            if (num2 != 0) {
                printf("Result of Division: %.2f / %.2f = %.2f\n", num1, num2, result);
            }
            break;
        case 5:
            printf("Result of Power: %.2f ^ %.2f = %.2f\n", num1, num2, result);
            break;
        default:
            printf("Operation not recognized.\n");
            break;
    }
}