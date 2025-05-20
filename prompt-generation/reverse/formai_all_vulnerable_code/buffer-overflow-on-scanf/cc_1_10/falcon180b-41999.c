//Falcon-180B DATASET v1.0 Category: Recursive ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function to print a string in reverse order
void printReverse(char* str) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Recursive function to calculate Fibonacci series
void fibonacci(int n) {
    if (n == 0) {
        printf("0\n");
        return;
    }
    printf("%d ", 0);
    fibonacci(n - 1);
}

// Recursive function to calculate sum of digits in a number
int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return n % 10 + sumOfDigits(n / 10);
}

// Recursive function to print a string in reverse order
void reverseString(char* str, int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Original string: %s\n", str);
    reverseString(str, 0, strlen(str) - 1);
    printf("Reversed string: %s\n", str);
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n));
    printf("Fibonacci series up to %d:\n", n);
    for (int i = 0; i <= n; i++) {
        fibonacci(i);
    }
    printf("Sum of digits in %d is %d\n", n, sumOfDigits(n));
    return 0;
}