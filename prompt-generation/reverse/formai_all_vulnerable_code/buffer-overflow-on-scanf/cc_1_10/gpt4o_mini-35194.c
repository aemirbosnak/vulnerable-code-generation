//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include <stdio.h>

// Function to calculate factorial recursively
unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Function to calculate Fibonacci number recursively
int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to display Pascal's triangle recursively
void pascalTriangle(int rows, int currentRow) {
    if (currentRow >= rows)
        return;
    
    int value = 1; // The first value in each row is always 1
    for (int j = 0; j < currentRow; j++) {
        printf("    "); // Spacing for better alignment
    }
    for (int j = 0; j <= currentRow; j++) {
        printf("%4d", value);
        // Calculate the next value in the row
        value = value * (currentRow - j) / (j + 1);
    }
    printf("\n");
    pascalTriangle(rows, currentRow + 1); // Recur for the next row
}

// Function to display the menu
void displayMenu() {
    printf("\n===== Recursive Computations Menu =====\n");
    printf("1. Calculate Factorial\n");
    printf("2. Calculate Fibonacci Number\n");
    printf("3. Display Pascal's Triangle\n");
    printf("4. Exit\n");
    printf("=======================================\n");
}

int main() {
    int choice, n;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a non-negative integer for factorial: ");
                scanf("%d", &n);
                if (n < 0) {
                    printf("Factorial is not defined for negative numbers.\n");
                } else {
                    printf("The factorial of %d is %llu\n", n, factorial(n));
                }
                break;
            case 2:
                printf("Enter a non-negative integer for Fibonacci: ");
                scanf("%d", &n);
                if (n < 0) {
                    printf("Fibonacci is not defined for negative numbers.\n");
                } else {
                    printf("The Fibonacci number at position %d is %d\n", n, fibonacci(n));
                }
                break;
            case 3:
                printf("Enter the number of rows for Pascal's Triangle: ");
                scanf("%d", &n);
                if (n < 0) {
                    printf("Number of rows cannot be negative.\n");
                } else {
                    printf("Pascal's Triangle with %d rows:\n", n);
                    pascalTriangle(n, 0);
                }
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}