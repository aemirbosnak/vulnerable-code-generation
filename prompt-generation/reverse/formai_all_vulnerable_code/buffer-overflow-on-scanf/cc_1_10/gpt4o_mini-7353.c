//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int factorial(int n);
void print_factorials_upto_n(int n);
void reverse_string(char *str, int start, int end);
void print_reversed_string(char *str);
int fibonacci(int n);
void print_fibonacci_series(int n);
void print_triangle(int n);
void print_pascals_triangle(int n, int row, int col);

// Main function
int main() {
    int choice, n;

    while (1) {
        printf("\n--- Recursive Functions Menu ---\n");
        printf("1. Factorial\n");
        printf("2. Reverse a String\n");
        printf("3. Fibonacci Series\n");
        printf("4. Print Patterns\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a positive integer for factorial: ");
                scanf("%d", &n);
                printf("Factorial of %d is %d\n", n, factorial(n));
                break;
            case 2:
                printf("Enter a string: ");
                char str[100];
                scanf("%s", str);
                print_reversed_string(str);
                break;
            case 3:
                printf("Enter the number of terms for Fibonacci series: ");
                scanf("%d", &n);
                print_fibonacci_series(n);
                break;
            case 4:
                printf("Enter the number of rows for patterns: ");
                scanf("%d", &n);
                print_triangle(n);
                print_pascals_triangle(n, 0, 0);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to calculate factorial recursively
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to reverse a string using recursion
void reverse_string(char *str, int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverse_string(str, start + 1, end - 1);
}

// Wrapper function to print reversed string
void print_reversed_string(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    reverse_string(str, 0, length - 1);
    printf("Reversed String: %s\n", str);
}

// Function to calculate Fibonacci recursively
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print Fibonacci series
void print_fibonacci_series(int n) {
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Function to print triangle pattern
void print_triangle(int n) {
    printf("Triangle Pattern:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print Pascal's triangle
void print_pascals_triangle(int n, int row, int col) {
    if (row >= n) {
        return;
    }
    if (col > row) {
        printf("\n");
        print_pascals_triangle(n, row + 1, 0);
        return;
    }

    if (col == 0 || col == row) {
        printf("1 ");
    } else {
        printf("%d ", (fibonacci(col) + fibonacci(row - col)));
    }
    print_pascals_triangle(n, row, col + 1);
}