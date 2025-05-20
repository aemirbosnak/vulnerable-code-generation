//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the factorial of a number recursively
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate Fibonacci number at position n recursively
int fibonacci(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to reverse a string recursively
void reverse_string(char *str, int start, int end) {
    if (start >= end) return;
    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    // Recursive call
    reverse_string(str, start + 1, end - 1);
}

// Function to find GCD of two numbers using recursion
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to display the menu and process user choices
void display_menu() {
    printf("Welcome to the Recursive Functions Demo!\n");
    printf("1. Factorial\n");
    printf("2. Fibonacci\n");
    printf("3. Reverse String\n");
    printf("4. Greatest Common Divisor (GCD)\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");
}

int main() {
    int choice, num;
    char str[100];
    
    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Factorial
                printf("Enter a non-negative integer: ");
                scanf("%d", &num);
                if (num < 0) {
                    printf("Factorial is not defined for negative numbers.\n");
                } else {
                    printf("Factorial of %d is %llu\n", num, factorial(num));
                }
                break;

            case 2: // Fibonacci
                printf("Enter the position for Fibonacci sequence: ");
                scanf("%d", &num);
                if (num < 0) {
                    printf("Fibonacci is not defined for negative indices.\n");
                } else {
                    printf("Fibonacci number at position %d is %d\n", num, fibonacci(num));
                }
                break;

            case 3: // Reverse String
                printf("Enter a string: ");
                scanf(" %[^\n]", str); // Read string with spaces
                reverse_string(str, 0, strlen(str) - 1);
                printf("Reversed string is: %s\n", str);
                break;

            case 4: // GCD
                printf("Enter two integers to find GCD: ");
                scanf("%d %d", &num, &num + 1);
                printf("GCD of %d and %d is %d\n", num, num + 1, gcd(num, num + 1));
                break;

            case 5: // Exit
                printf("Exiting the program. Have a great day!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please select again.\n");
        }
        printf("\n");
    }
    return 0;
}