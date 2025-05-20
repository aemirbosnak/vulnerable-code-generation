//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int isPalindrome(char* str) {
    int length = strlen(str);
    if(length <= 1) {
        return 1;
    }
    char* reversed = malloc(length * sizeof(char));
    int j = 0;
    for(int i = length - 1; i >= 0; i--) {
        if(!isalnum(str[i])) {
            continue;
        }
        reversed[j++] = tolower(str[i]);
    }
    reversed[j] = '\0';
    int isPal = strcmp(str, reversed) == 0;
    free(reversed);
    return isPal;
}

char* removeNonAlphanumeric(char* str) {
    int length = strlen(str);
    char* cleaned = malloc(length * sizeof(char));
    int j = 0;
    for(int i = 0; i < length; i++) {
        if(isalnum(str[i])) {
            cleaned[j++] = tolower(str[i]);
        }
    }
    cleaned[j] = '\0';
    return cleaned;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    char* cleaned = removeNonAlphanumeric(input);
    int isPalindromeResult = isPalindrome(cleaned);
    if(isPalindromeResult) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    free(cleaned);
    return 0;
}