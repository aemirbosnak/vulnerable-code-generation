//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is a vowel
int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Function to check if a string is a palindrome
int isPalindrome(char* str, int len) {
    int i;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    char str[100];
    int len;

    // Get the input string
    printf("Enter a string: ");
    scanf("%s", str);

    // Find the length of the string
    len = strlen(str);

    // Check if the string is a palindrome
    if (isPalindrome(str, len)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Check if the string contains only vowels
    int allVowels = 1;
    for (int i = 0; i < len; i++) {
        if (!isVowel(str[i])) {
            allVowels = 0;
            break;
        }
    }

    if (allVowels) {
        printf("The string contains only vowels.\n");
    } else {
        printf("The string does not contain only vowels.\n");
    }

    return 0;
}