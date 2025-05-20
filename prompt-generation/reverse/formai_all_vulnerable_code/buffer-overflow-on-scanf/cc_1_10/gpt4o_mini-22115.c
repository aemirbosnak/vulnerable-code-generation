//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute factorial of a number using recursion
unsigned long long factorial(int n) {
    if (n < 0) {
        fprintf(stderr, "Error: Negative input for factorial\n");
        exit(EXIT_FAILURE);
    }
    return (n == 0) ? 1 : n * factorial(n - 1);
}

// Function to reverse a string using recursion
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

// Function to check if a string is a palindrome using recursion
int isPalindrome(char *str, int start, int end) {
    if (start >= end) {
        return 1;
    }
    if (str[start] != str[end]) {
        return 0;
    }
    return isPalindrome(str, start + 1, end - 1);
}

// Main function to demonstrate the recursive functions
int main() {
    int choice;
    do {
        printf("Choose an operation:\n");
        printf("1. Calculate Factorial\n");
        printf("2. Reverse a String\n");
        printf("3. Check Palindrome\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input\n");
            exit(EXIT_FAILURE);
        }
        switch (choice) {
            case 1: {
                int num;
                printf("Enter a non-negative integer: ");
                if (scanf("%d", &num) != 1) {
                    fprintf(stderr, "Invalid input\n");
                    exit(EXIT_FAILURE);
                }
                unsigned long long result = factorial(num);
                printf("Factorial of %d is %llu\n", num, result);
                break;
            }
            case 2: {
                char str[100];
                printf("Enter a string: ");
                scanf(" %[^\n]", str); // Read string with spaces
                int len = strlen(str);
                reverseString(str, 0, len - 1);
                printf("Reversed string: %s\n", str);
                break;
            }
            case 3: {
                char str[100];
                printf("Enter a string: ");
                scanf(" %[^\n]", str); // Read string with spaces
                int len = strlen(str);
                if (isPalindrome(str, 0, len - 1)) {
                    printf("\"%s\" is a palindrome.\n", str);
                } else {
                    printf("\"%s\" is not a palindrome.\n", str);
                }
                break;
            }
            case 4:
                printf("Exiting...\n");
                break;
            default:
                fprintf(stderr, "Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}