//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: Ada Lovelace
#include <stdio.h>

// Function prototypes
void greetUser();
void calculateFibonacci(int n);
void displayMenu();

int main() {
    int choice, num;

    greetUser();

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while(getchar() != '\n');
            printf("Invalid input, please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the number of Fibonacci terms to display: ");
                if (scanf("%d", &num) != 1) {
                    // Clear invalid input
                    while(getchar() != '\n');
                    printf("Invalid input. Please enter a number.\n");
                    continue;
                }
                calculateFibonacci(num);
                break;
                
            case 2:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    }
}

// Function to greet the user
void greetUser() {
    printf("Welcome to the Fibonacci Sequence Calculator!\n");
    printf("You can display the Fibonacci sequence up to any number of terms.\n\n");
}

// Function to calculate and display Fibonacci series
void calculateFibonacci(int n) {
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return;
    }
    
    unsigned long long a = 0, b = 1, next;
    
    printf("Fibonacci sequence up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;  // First two terms are 0 and 1
        } else {
            next = a + b;  // Next term is the sum of the previous two
            a = b;  // Update a to the last term
            b = next;  // Update b to the current term
        }
        printf("%llu ", next);
    }
    printf("\n\n");
}

// Function to display menu
void displayMenu() {
    printf("Select an option:\n");
    printf("1. Calculate Fibonacci Sequence\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
}