//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string recursively
void reverseString(char *str, int start, int end) {
    if (start >= end) return;
    // Swap the characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    // Recursive call
    reverseString(str, start + 1, end - 1);
}

// Function to check if a string is a palindrome recursively
int isPalindrome(char *str, int start, int end) {
    if (start >= end) return 1; // Base case: all characters checked
    if (str[start] != str[end]) return 0; // Characters do not match
    // Recursive call
    return isPalindrome(str, start + 1, end - 1);
}

// Function to calculate factorial recursively
unsigned long long factorial(int n) {
    if (n == 0) return 1; // Base case
    return n * factorial(n - 1); // Recursive case
}

// Function to display Fibonacci series using recursion
void fibonacci(int a, int b, int count) {
    if (count == 0) return;
    printf("%d ", a);
    fibonacci(b, a + b, count - 1); // Recursive call
}

// Structure to store string and its manipulation results
typedef struct {
    char original[100]; // Original string
    char reversed[100]; // Reversed string
    int palindrome; // 1 if palindrome, 0 otherwise
    unsigned long long fact; // Factorial of string length
} StringInfo;

StringInfo analyzeString(char *str) {
    StringInfo info;
    strcpy(info.original, str);
    
    // Calculate length of the string
    int len = strlen(str);

    // Reverse string
    reverseString(str, 0, len - 1);
    strcpy(info.reversed, str);
    
    // Check if palindrome
    info.palindrome = isPalindrome(info.original, 0, len - 1);
    
    // Calculate factorial of string length
    info.fact = factorial(len);
    
    return info;
}

int main() {
    char str[100];
    int fibCount;
    
    printf("Enter a string (max 99 characters): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character if present
    
    // Analyze the string
    StringInfo info = analyzeString(str);
    
    printf("\nOriginal String: %s\n", info.original);
    printf("Reversed String: %s\n", info.reversed);
    printf("Is Palindrome: %s\n", info.palindrome ? "Yes" : "No");
    printf("Factorial of Length %ld: %llu\n", strlen(info.original), info.fact);

    // Fibonacci Series
    printf("\nEnter how many Fibonacci numbers to display: ");
    scanf("%d", &fibCount);
    
    printf("Fibonacci Series: ");
    fibonacci(0, 1, fibCount);
    printf("\n");

    return 0;
}