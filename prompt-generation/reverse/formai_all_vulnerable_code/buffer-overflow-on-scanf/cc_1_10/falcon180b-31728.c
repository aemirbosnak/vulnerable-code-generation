//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(char *str) {
    // Remove non-alphanumeric characters and convert to lowercase
    int i, j;
    char cleanStr[100];
    strcpy(cleanStr, str);
    for (i = 0, j = 0; str[i]; i++) {
        if (isalnum(str[i])) {
            cleanStr[j++] = tolower(str[i]);
        }
    }
    cleanStr[j] = '\0';

    // Check if the cleaned string is equal to its reverse
    int len = strlen(cleanStr);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (cleanStr[i]!= cleanStr[j]) {
            return false;
        }
    }

    return true;
}

// Recursive function to check if a string is a palindrome
bool isPalindromeRecursive(char *str, int start, int end) {
    // Base case: single character string is always a palindrome
    if (start >= end) {
        return true;
    }

    // Check if the first and last characters match
    if (tolower(str[start])!= tolower(str[end])) {
        return false;
    }

    // Recursive case: check the substring between the first and last characters
    return isPalindromeRecursive(str, start + 1, end - 1);
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    // Check if the input string is a palindrome
    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    return 0;
}