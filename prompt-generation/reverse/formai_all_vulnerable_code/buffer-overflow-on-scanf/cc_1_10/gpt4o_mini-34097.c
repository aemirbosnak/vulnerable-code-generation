//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

void displayMenu() {
    printf("==== Factorial Calculation Menu ====\n");
    printf("1. Calculate factorial\n");
    printf("2. Exit\n");
    printf("====================================\n");
    printf("Please select an option (1-2): ");
}

int main() {
    int choice, number, result;

    while (1) {
        displayMenu();
        // Get user input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        if (choice == 1) {
            printf("Enter a non-negative integer: ");
            if (scanf("%d", &number) != 1 || number < 0) {
                printf("Invalid input, please enter a non-negative integer.\n");
                // Clear the input buffer
                while (getchar() != '\n');
                continue;
            }

            result = factorial(number);
            printf("Factorial of %d is %d\n", number, result);
        } else if (choice == 2) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice, please select a valid option.\n");
        }

        printf("\n");
    }

    return 0;
}