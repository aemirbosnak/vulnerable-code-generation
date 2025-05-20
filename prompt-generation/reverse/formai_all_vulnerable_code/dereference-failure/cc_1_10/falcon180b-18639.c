//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char* str) {
    int len = strlen(str);
    char* reversed = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    printf("Reversed string: %s\n", reversed);
}

// Function to remove vowels from a string
void remove_vowels(char* str) {
    char vowels[] = "aeiouAEIOU";
    int len = strlen(str);
    char* result = (char*)malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (strchr(vowels, str[i]) == NULL) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    printf("Result: %s\n", result);
}

// Function to replace a substring in a string
void replace_substring(char* str1, char* str2, char* substr) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(substr);
    char* result = (char*)malloc(len1 + len2 - len3 + 1);
    int j = 0;
    for (int i = 0; i < len1; i++) {
        if (strncmp(&str1[i], substr, len3) == 0) {
            for (int k = 0; k < len3; k++) {
                result[j++] = str2[k];
            }
            i += len3 - 1;
        } else {
            result[j++] = str1[i];
        }
    }
    result[j] = '\0';
    printf("Result: %s\n", result);
}

// Main function
int main() {
    char* str1 = "Hello World";
    reverse(str1);

    char* str2 = "The quick brown fox jumps over the lazy dog";
    remove_vowels(str2);

    char* str3 = "The quick brown fox jumps over the lazy dog";
    char* substr = "fox";
    char* replacement = "cat";
    replace_substring(str3, replacement, substr);

    return 0;
}