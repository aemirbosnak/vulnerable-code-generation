//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 1000

// Function to check if a string is a palindrome using bitwise operations
bool isPalindrome(char* str) {
    int len = strlen(str);
    if (len <= 1) {
        return true;
    }

    // Convert string to lowercase and remove non-alphabetic characters
    char* cleanedStr = malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            cleanedStr[j++] = tolower(str[i]);
        }
    }
    cleanedStr[j] = '\0';

    // Reverse the cleaned string
    char* reversedStr = malloc(j + 1);
    for (int i = j - 1, k = 0; i >= 0; i--, k++) {
        reversedStr[k] = cleanedStr[i];
    }
    reversedStr[j] = '\0';

    // Compare the original and reversed strings using bitwise operations
    int result = 0;
    for (int i = 0; i < j; i++) {
        if (cleanedStr[i]!= reversedStr[i]) {
            result |= 1 << (cleanedStr[i] - 'a');
        }
    }

    // Check if the result is odd, indicating a non-palindrome
    return (result & 1) == 0;
}

int main() {
    char input[MAX_SIZE];
    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}