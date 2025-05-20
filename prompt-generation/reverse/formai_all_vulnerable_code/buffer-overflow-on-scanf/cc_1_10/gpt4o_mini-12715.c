//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function declarations
int fibonacci(int n);
void print_fibonacci(int n);
int factorial(int n);
void print_factorial(int n);
void print_reverse(char *str, int index);
void reverse_string(char *str);

// Main function
int main() {
    int choice, num;

    printf("Choose an option:\n");
    printf("1. Fibonacci Series\n");
    printf("2. Factorial\n");
    printf("3. Reverse a String\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of Fibonacci terms: ");
                scanf("%d", &num);
                print_fibonacci(num);
                break;
            case 2:
                printf("Enter a number to calculate factorial: ");
                scanf("%d", &num);
                print_factorial(num);
                break;
            case 3:
                {
                    char str[100];
                    printf("Enter a string to reverse: ");
                    scanf(" %[^\n]%*c", str); // Read string with spaces
                    reverse_string(str);
                }
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}

// Function to calculate Fibonacci number recursively
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print Fibonacci series
void print_fibonacci(int n) {
    printf("Fibonacci Series up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Function to calculate factorial recursively
int factorial(int n) {
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return -1; // Indicate error
    }
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// Function to print factorial of a number
void print_factorial(int n) {
    int result = factorial(n);
    if (result == -1) return; // Error case already handled
    printf("Factorial of %d is: %d\n", n, result);
}

// Recursive function to print string in reverse
void print_reverse(char *str, int index) {
    if (index < 0) return;
    putchar(str[index]);
    print_reverse(str, index - 1);
}

// Function to reverse a string using recursion
void reverse_string(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    printf("Reversed string: ");
    print_reverse(str, length - 1);
    printf("\n");
}