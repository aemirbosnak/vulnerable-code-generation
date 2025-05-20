//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Recursive function to calculate the nth fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print the fibonacci series up to the nth term
void printFibonacciSeries(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}

// Recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to print the factorial of a number
void printFactorial(int n) {
    printf("%d! = %d\n", n, factorial(n));
}

// Recursive function to calculate the sum of digits of a number
int sumOfDigits(int n) {
    if (n < 10) {
        return n;
    } else {
        return n % 10 + sumOfDigits(n / 10);
    }
}

// Function to print the sum of digits of a number
void printSumOfDigits(int n) {
    printf("The sum of digits of %d is %d\n", n, sumOfDigits(n));
}

// Recursive function to reverse a string
char *reverseString(char *str) {
    if (*str == '\0') {
        return str;
    } else {
        reverseString(str + 1);
        printf("%c", *str);
        return str;
    }
}

// Function to print the reverse of a string
void printReverseString(char *str) {
    printf("The reverse of %s is %s\n", str, reverseString(str));
}

// Recursive function to print all the subsequences of a string
void printSubsequences(char *str) {
    if (*str == '\0') {
        printf("\n");
        return;
    }
    printf("%c", *str);
    printSubsequences(str + 1);
    printf("\n");
    printSubsequences(str + 1);
}

// Main function to test the recursive functions
int main() {
    int n;
    char str[100];

    printf("Enter a number to calculate its fibonacci number: ");
    scanf("%d", &n);
    printf("The fibonacci number is: %d\n", fibonacci(n));

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);
    printFactorial(n);

    printf("Enter a number to calculate the sum of its digits: ");
    scanf("%d", &n);
    printSumOfDigits(n);

    printf("Enter a string to reverse it: ");
    scanf("%s", str);
    printReverseString(str);

    printf("Enter a string to print all its subsequences: ");
    scanf("%s", str);
    printSubsequences(str);

    return 0;
}