//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000
#define MAX_WORD_LENGTH 100

int isPalindrome(char *string);
int isPalindromeIgnoreCase(char *string);

int main(int argc, char *argv[]) {
    char inputString[MAX_STRING_LENGTH];
    int ignoreCase = 0;
    int result;
    printf("Enter a string to check if it is a palindrome (up to %d characters):\n", MAX_STRING_LENGTH - 1);
    fgets(inputString, MAX_STRING_LENGTH, stdin);
    inputString[strcspn(inputString, "\n")] = '\0'; // Remove newline character
    if (argc > 1) {
        if (strcmp(argv[1], "--ignore-case") == 0) {
            ignoreCase = 1;
        }
    }
    printf("Checking if \"%s\" is a palindrome...\n", inputString);
    if (ignoreCase) {
        result = isPalindromeIgnoreCase(inputString);
    } else {
        result = isPalindrome(inputString);
    }
    if (result) {
        printf("\"%s\" is a palindrome.\n", inputString);
    } else {
        printf("\"%s\" is not a palindrome.\n", inputString);
    }
    return 0;
}

int isPalindrome(char *string) {
    int i, j;
    for (i = 0, j = strlen(string) - 1; i < j; i++, j--) {
        if (tolower(string[i])!= tolower(string[j])) {
            return 0;
        }
    }
    return 1;
}

int isPalindromeIgnoreCase(char *string) {
    int i, j;
    for (i = 0, j = strlen(string) - 1; i < j; i++, j--) {
        if (tolower(string[i])!= tolower(string[j])) {
            return 0;
        }
    }
    return 1;
}