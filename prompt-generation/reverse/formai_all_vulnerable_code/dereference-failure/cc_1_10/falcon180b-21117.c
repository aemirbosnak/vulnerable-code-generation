//Falcon-180B DATASET v1.0 Category: Recursive ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to count number of words in a string
int countWords(char* str) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to reverse a string
char* reverseString(char* str) {
    int length = strlen(str);
    char* reversed = (char*) malloc(length + 1);
    int i = 0;
    for (int j = length - 1; j >= 0; j--) {
        reversed[i] = str[j];
        i++;
    }
    reversed[i] = '\0';
    return reversed;
}

// Function to calculate factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate Fibonacci sequence up to a given number of terms
void fibonacci(int n) {
    int first = 0, second = 1, nextTerm;
    printf("Fibonacci sequence up to %d terms:\n", n);
    printf("0 1 ");
    for (int i = 2; i < n; i++) {
        nextTerm = first + second;
        printf("%d ", nextTerm);
        first = second;
        second = nextTerm;
    }
}

int main() {
    // Example usage of functions
    char* inputString = "This is a test string";
    int numWords = countWords(inputString);
    printf("Number of words in input string: %d\n", numWords);

    char* reversedString = reverseString(inputString);
    printf("Reversed string: %s\n", reversedString);

    int numTerms = 10;
    fibonacci(numTerms);

    int factResult = factorial(5);
    printf("Factorial of 5: %d\n", factResult);

    return 0;
}