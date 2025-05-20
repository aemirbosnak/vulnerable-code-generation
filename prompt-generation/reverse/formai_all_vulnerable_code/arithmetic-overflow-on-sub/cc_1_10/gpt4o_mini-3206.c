//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function to compute the factorial of a number recursively
unsigned long long factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Recursive case
        return n * factorial(n - 1);
    }
}

// Function to calculate Fibonacci sequence recursively
int fibonacci(int n) {
    // Base cases: return n if n is 0 or 1
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        // Recursive case
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print a pyramid pattern of stars recursively
void printPyramid(int rows, int currentRow) {
    if (currentRow == rows) {
        return;
    }
    // Print spaces
    for (int i = 0; i < rows - currentRow - 1; i++) {
        printf(" ");
    }
    // Print stars
    for (int j = 0; j < (2 * currentRow + 1); j++) {
        printf("*");
    }
    printf("\n");
    // Recursive call for the next row
    printPyramid(rows, currentRow + 1);
}

// Function to reverse a string recursively
void reverseString(char *str, int start, int end) {
    if (start >= end) {
        return; // Base case: when the indices cross
    }
    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    // Recursive call
    reverseString(str, start + 1, end - 1);
}

// Function to print the digits of an integer recursively
void printDigits(int n) {
    if (n == 0) {
        return; // Base case for non-negative integer
    }
    printDigits(n / 10); // Recursive call for the next digit
    printf("%d ", n % 10); // Print the last digit
}

// Main function to test the above functionalities
int main() {
    int number, rows;

    // Test factorial
    printf("Enter a number to compute its factorial: ");
    scanf("%d", &number);
    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %llu\n", number, factorial(number));
    }
    
    // Test Fibonacci
    printf("Enter the position in Fibonacci sequence: ");
    scanf("%d", &number);
    if (number < 0) {
        printf("Fibonacci is not defined for negative numbers.\n");
    } else {
        printf("Fibonacci at position %d is %d\n", number, fibonacci(number));
    }

    // Test pyramid printing
    printf("Enter the number of rows for pyramid: ");
    scanf("%d", &rows);
    printPyramid(rows, 0);

    // Test reversing string
    char str[100];
    printf("Enter a string to reverse: ");
    scanf("%s", str);
    int len = 0;
    while (str[len] != '\0') { // Find the length of the string
        len++;
    }
    reverseString(str, 0, len - 1);
    printf("Reversed string: %s\n", str);

    // Test printing digits
    printf("Enter a number to print its digits: ");
    scanf("%d", &number);
    if (number < 0) {
        printf("Digits for negative numbers are not printed.\n");
    } else {
        printf("Digits of %d are: ", number);
        printDigits(number);
        printf("\n");
    }

    return 0;
}