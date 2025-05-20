//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    char* rev = malloc(len + 1);
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        rev[j++] = str[i];
    }
    rev[j] = '\0';
    strcpy(str, rev);
    free(rev);
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int len = strlen(str);
    char* vowels = "aeiouAEIOU";
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (strchr(vowels, tolower(str[i])) == NULL) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main() {
    // Example usage
    char* input = "A man, a plan, a canal: Panama";
    printf("Original string: %s\n", input);
    reverseString(input);
    printf("Reversed string: %s\n", input);
    removeVowels(input);
    printf("String with vowels removed: %s\n", input);
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}