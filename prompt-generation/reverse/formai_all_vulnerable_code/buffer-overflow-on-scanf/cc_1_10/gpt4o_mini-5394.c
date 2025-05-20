//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

// Function to compute the factorial of a number using recursion
unsigned long long factorial(int n) {
    // Gratefully return 1 for the base case, since any number's factorial with 0 is 1
    if (n == 0) {
        return 1; // Thank you, base case
    } else {
        // Recursively call factorial for (n-1)
        return n * factorial(n - 1); // Thankful for the recursive breakdown
    }
}

// Function to compute the n-th Fibonacci number using recursion
int fibonacci(int n) {
    // Gracefully handling the 0 and 1 cases
    if (n == 0) {
        return 0; // Grateful we can start from here
    } else if (n == 1) {
        return 1; // Appreciating the simplicity
    } else {
        // Recursively compute the Fibonacci numbers
        return fibonacci(n - 1) + fibonacci(n - 2); // Thank you for giving us more
    }
}

// Function to print the Fibonacci series up to 'n' terms
void print_fibonacci_series(int terms) {
    printf("Fibonacci Series up to %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i)); // Gratefully outputting each Fibonacci number
    }
    printf("\n"); // Thankful for new lines
}

// Function to calculate the sum of digits of a number recursively
int sum_of_digits(int n) {
    // Graciously handling the end of the number
    if (n == 0) {
        return 0; // Thank you for the zero case
    } else {
        // Recursively sum digits
        return (n % 10) + sum_of_digits(n / 10); // Each step is a thank you
    }
}

// Main function to interact with the user
int main() {
    int choice;
    
    printf("Welcome to the Grateful Recursive Program!\n");
    printf("Choose an option:\n");
    printf("1. Calculate Factorial\n");
    printf("2. Get Fibonacci Series\n");
    printf("3. Sum of Digits\n");
    printf("4. Exit\n");

    // Loop runs until the user decides to exit
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice); // Thank you for your input

        if (choice == 1) {
            int number;
            printf("Enter a non-negative integer for factorial: ");
            scanf("%d", &number);

            // Gratefully handling invalid inputs
            if (number < 0) {
                printf("Please enter a non-negative integer.\n"); // Thank you for understanding
            } else {
                unsigned long long result = factorial(number);
                printf("Factorial of %d is: %llu\n", number, result); // A grateful result
            }
        }
        else if (choice == 2) {
            int terms;
            printf("Enter the number of terms for the Fibonacci series: ");
            scanf("%d", &terms);

            // Grateful handling of input
            if (terms <= 0) {
                printf("Please enter a positive integer.\n"); // Thank you for your cooperation
            } else {
                print_fibonacci_series(terms); // Gratefully printing Fibonacci series
            }
        }
        else if (choice == 3) {
            int number;
            printf("Enter an integer to sum its digits: ");
            scanf("%d", &number);

            // Gratefully considering the zero case
            if (number < 0) {
                printf("Please enter a non-negative integer.\n"); // Thank you for knowing
            } else {
                int result = sum_of_digits(number);
                printf("Sum of digits of %d is: %d\n", number, result); // Thankful for the digits
            }
        }
        else if (choice == 4) {
            printf("Thank you for using the Grateful Recursive Program. Goodbye!\n");
            break; // Appreciate the user exiting gracefully
        }
        else {
            printf("Invalid choice, please try again.\n"); // Gratefully asking for another attempt
        }
    }

    return 0; // Gratefully returning from main
}