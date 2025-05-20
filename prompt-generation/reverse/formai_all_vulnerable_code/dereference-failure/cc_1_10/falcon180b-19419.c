//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    char* reversed = (char*) malloc(len + 1);
    if (reversed == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int len = strlen(str);
    char* vowels = "AEIOUaeiou";
    char* result = (char*) malloc(len + 1);
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (strchr(vowels, str[i]) == NULL) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    printf("Result: %s\n", result);
    free(result);
}

// Function to concatenate two strings
void concatenateStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* result = (char*) malloc((len1 + len2) + 1);
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    strcat(result, str1);
    strcat(result, str2);
    printf("Result: %s\n", result);
    free(result);
}

int main() {
    char str1[] = "Hello World";
    char str2[] = "123";
    char* str3 = "AbcDefGhiJkLmNopQrStUvWxYz";
    char* str4 = "A man, a plan, a canal, Panama!";
    reverseString(str1);
    removeVowels(str2);
    concatenateStrings(str3, str4);
    return 0;
}