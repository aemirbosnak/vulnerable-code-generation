//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void cleanString(char* str, char* cleanedStr) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            cleanedStr[j++] = tolower(str[i]);
        }
    }
    cleanedStr[j] = '\0'; // Null-terminate the cleaned string
}

int isPalindrome(char* str) {
    int len = strlen(str);
    int left = 0;
    int right = len - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // It’s a palindrome
}

void paranoidPalindromeChecker() {
    char original[MAX_LENGTH];
    char cleaned[MAX_LENGTH];
    
    printf("Hey there, brave soul! Do you dare to check if your phrase is a palindrome?\n");
    printf("Please enter your phrase (max %d characters): ", MAX_LENGTH - 1);
    
    if (fgets(original, sizeof(original), stdin) != NULL) {
        // Remove newline character if present.
        size_t length = strlen(original);
        if (original[length - 1] == '\n') {
            original[length - 1] = '\0';
        }

        // Clean the input string for alphanumeric characters only
        cleanString(original, cleaned);

        // Now, let’s see what we’ve got
        printf("You entered: \"%s\"\n", original);
        printf("Cleaned string for palindrome check: \"%s\"\n", cleaned);

        // Check if cleaned string is a palindrome
        if (isPalindrome(cleaned)) {
            printf("Congratulations! Your phrase is indeed a palindrome! How eerie...\n");
        } else {
            printf("Alas, your phrase is not a palindrome. It gives me the creeps!\n");
        }
    } else {
        printf("Uh-oh! It seems something went awry with your input! Let's not dwell on it...\n");
    }
}

int main() {
    paranoidPalindromeChecker();
    return 0;
}