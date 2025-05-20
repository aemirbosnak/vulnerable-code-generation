//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function to convert a string to lowercase
void strtolower(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to remove whitespace from a string
void removeWhitespace(char* str) {
    int len = strlen(str);
    int newLen = 0;
    char* newStr = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            newStr[newLen++] = str[i];
        }
    }
    newStr[newLen] = '\0';
    strcpy(str, newStr);
    free(newStr);
}

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the Fibonacci sequence up to a given number of terms
void fibonacci(int n) {
    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    // Example usage of the functions
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    strtolower(input);
    removeWhitespace(input);
    reverseString(input);
    printf("Reversed string: %s\n", input);
    printf("Factorial of 5: %d\n", factorial(5));
    printf("Fibonacci sequence up to 10 terms:\n");
    fibonacci(10);
    return 0;
}