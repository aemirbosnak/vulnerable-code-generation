//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: mind-bending
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000 // Maximum length of input string

int isPalindrome(char* str); // Function to check if string is palindrome

int main() {
    char input[MAX_LENGTH]; // Input string
    int length; // Length of input string

    // Prompt user for input
    printf("Enter a string to check if it's a palindrome: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input string
    length = strlen(input) - 1;
    input[length] = '\0';

    // Check if input string is a palindrome
    if (isPalindrome(input)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(char* str) {
    int i, j, length;
    char temp;

    // Remove non-alphanumeric characters from input string
    length = strlen(str);
    char* newStr = malloc(length + 1);
    for (i = 0, j = 0; i < length; i++) {
        if (isalnum(str[i])) {
            newStr[j++] = tolower(str[i]);
        }
    }
    newStr[j] = '\0';

    // Check if new string is a palindrome
    for (i = 0, j = strlen(newStr) - 1; i < j; i++, j--) {
        if (newStr[i]!= newStr[j]) {
            free(newStr);
            return 0;
        }
    }

    free(newStr);
    return 1;
}