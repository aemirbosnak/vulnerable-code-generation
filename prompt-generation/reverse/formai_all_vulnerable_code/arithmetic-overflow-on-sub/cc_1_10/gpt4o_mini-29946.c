//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to reverse a string
void reverseString(char *str, int start, int end) {
    char temp;
    if (start >= end) {
        return;
    }
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start + 1, end - 1);
}

// Function to demonstrate the program
void demonstrate() {
    int n, fibResult, factResult;
    char str[100];

    printf("Welcome to the Fun C Program!\n");
    printf("This program will generate Fibonacci numbers and calculate factorials, along with a little string magic!\n");

    // Fibonacci series
    printf("Enter a number to get the Fibonacci number: ");
    scanf("%d", &n);
    fibResult = fibonacci(n);
    printf("Fibonacci number at position %d is: %d\n\n", n, fibResult);

    // Factorial calculation
    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);
    factResult = factorial(n);
    printf("Factorial of %d is: %d\n\n", n, factResult);

    // String reverse
    printf("Enter a string to reverse: ");
    scanf("%s", str);
    int len = strlen(str);
    reverseString(str, 0, len - 1);
    printf("Reversed string is: %s\n\n", str);

    printf("Thank you for playing! Give it another shot or take a bow!\n");
}

int main() {
    demonstrate();
    return 0;
}