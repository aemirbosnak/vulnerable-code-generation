//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the Fibonacci sequence recursively
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate the factorial of a number recursively
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to reverse a string recursively
void reverseString(char *str, int start, int end) {
    if (start >= end) {
        return;
    }

    // Swap the characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call
    reverseString(str, start + 1, end - 1);
}

// Main function to drive the program
int main() {
    int choice, number, result;
    char str[100];

    while (1) {
        printf("\n=== Recursive Function Menu ===\n");
        printf("1. Fibonacci Sequence\n");
        printf("2. Factorial Calculation\n");
        printf("3. Reverse a String\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a positive integer for Fibonacci: ");
                scanf("%d", &number);
                if (number < 0) {
                    printf("Please enter a non-negative integer.\n");
                } else {
                    printf("Fibonacci of %d is %d\n", number, fibonacci(number));
                }
                break;

            case 2:
                printf("Enter a non-negative integer for Factorial: ");
                scanf("%d", &number);
                if (number < 0) {
                    printf("Factorial is not defined for negative numbers.\n");
                } else {
                    printf("Factorial of %d is %d\n", number, factorial(number));
                }
                break;

            case 3:
                printf("Enter a string to reverse: ");
                scanf("%s", str);
                reverseString(str, 0, strlen(str) - 1);
                printf("Reversed string: %s\n", str);
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
    return 0;
}