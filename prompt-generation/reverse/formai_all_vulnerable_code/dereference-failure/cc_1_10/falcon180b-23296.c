//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1); // Allocate memory for reversed string
    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        reversed[i++] = str[j];
    }
    reversed[i] = '\0'; // Add null terminator to end of string
    printf("Reversed string: %s\n", reversed);
    free(reversed); // Free memory allocated for reversed string
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int len = strlen(str);
    char* vowels = "aeiouAEIOU";
    char* newStr = malloc(len + 1); // Allocate memory for new string
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (strchr(vowels, str[i]) == NULL) { // Check if character is not a vowel
            newStr[j++] = str[i];
        }
    }
    newStr[j] = '\0'; // Add null terminator to end of string
    printf("New string: %s\n", newStr);
    free(newStr); // Free memory allocated for new string
}

int main() {
    char* str = "A man, a plan, a canal, Panama!";
    printf("Original string: %s\n", str);
    reverseString(str);
    printf("\n");
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    printf("\n");
    removeVowels(str);
    return 0;
}