//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: visionary
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int isPalindrome(char* str);

int main(void) {
    char input[MAX_LENGTH];
    int length;

    printf("Enter a string to check if it's a palindrome: ");
    fgets(input, MAX_LENGTH, stdin);
    length = strlen(input);
    input[length - 1] = '\0'; // remove newline character

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(char* str) {
    int i, j;
    char cleanStr[MAX_LENGTH];
    int cleanStrLength;

    // remove non-alphabetic characters and convert to lowercase
    cleanStrLength = 0;
    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            cleanStr[cleanStrLength++] = tolower(str[i]);
        }
    }
    cleanStr[cleanStrLength] = '\0';

    // check if the cleaned string is a palindrome
    for (i = 0, j = strlen(cleanStr) - 1; i < j; i++, j--) {
        if (cleanStr[i]!= cleanStr[j]) {
            return 0;
        }
    }

    return 1;
}