//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>

// Function prototypes
unsigned long long factorial(int n);
unsigned long long permutation(int n, int r);
unsigned long long combination(int n, int r);
void displayMenu();

// Main function
int main() {
    int choice, n, r;
    while (1) {
        displayMenu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program.\n");
            break;
        }
        
        switch (choice) {
            case 1:
                printf("Enter a number to calculate its factorial: ");
                scanf("%d", &n);
                if (n < 0) {
                    printf("Factorial is not defined for negative numbers.\n");
                } else {
                    printf("Factorial of %d = %llu\n", n, factorial(n));
                }
                break;
            case 2:
                printf("Enter n and r for permutation (nPr): ");
                scanf("%d %d", &n, &r);
                if (n < r || n < 0 || r < 0) {
                    printf("Invalid input. Ensure that n >= r and both are non-negative.\n");
                } else {
                    printf("%dP%d = %llu\n", n, r, permutation(n, r));
                }
                break;
            case 3:
                printf("Enter n and r for combination (nCr): ");
                scanf("%d %d", &n, &r);
                if (n < r || n < 0 || r < 0) {
                    printf("Invalid input. Ensure that n >= r and both are non-negative.\n");
                } else {
                    printf("%dC%d = %llu\n", n, r, combination(n, r));
                }
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1; 
    else
        return n * factorial(n - 1);
}

// Function to calculate permutation
unsigned long long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Function to calculate combination
unsigned long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Math Operations Menu ---\n");
    printf("1. Calculate Factorial\n");
    printf("2. Calculate Permutation (nPr)\n");
    printf("3. Calculate Combination (nCr)\n");
    printf("0. Exit\n");
}