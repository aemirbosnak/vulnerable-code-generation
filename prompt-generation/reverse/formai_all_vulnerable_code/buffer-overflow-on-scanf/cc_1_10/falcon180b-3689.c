//Falcon-180B DATASET v1.0 Category: Recursive ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print a string in reverse order
void printReverse(char* str) {
    if (str == NULL || strlen(str) == 0) {
        printf("Empty string\n");
        return;
    }
    char* end = str + strlen(str) - 1;
    while (end >= str) {
        printf("%c", *end);
        end--;
    }
    printf("\n");
}

// Recursive function to print a string in reverse order
void printReverseRecursive(char* str) {
    if (str == NULL || strlen(str) == 0) {
        printf("Empty string\n");
        return;
    }
    char* end = str + strlen(str) - 1;
    printf("%c", *end);
    printReverseRecursive(end - 1);
}

// Function to check if a string is a palindrome
bool isPalindrome(char* str) {
    if (str == NULL || strlen(str) == 0) {
        return true;
    }
    char* start = str;
    char* end = str + strlen(str) - 1;
    while (start < end) {
        if (*start!= *end) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Recursive function to check if a string is a palindrome
bool isPalindromeRecursive(char* str) {
    if (str == NULL || strlen(str) == 0) {
        return true;
    }
    if (strlen(str) == 1) {
        return true;
    }
    if (*str!= *(str + strlen(str) - 1)) {
        return false;
    }
    return isPalindromeRecursive(str + 1);
}

int main() {
    char input[1000];
    printf("Enter a string: ");
    scanf("%s", input);
    printReverse(input);
    printf("Is %s a palindrome? %s\n", input, isPalindrome(input)? "Yes" : "No");
    printReverseRecursive(input);
    printf("Is %s a palindrome? %s\n", input, isPalindromeRecursive(input)? "Yes" : "No");
    return 0;
}