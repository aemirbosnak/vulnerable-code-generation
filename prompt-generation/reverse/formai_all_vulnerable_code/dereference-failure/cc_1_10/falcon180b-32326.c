//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    for (int i = len - 1; i >= 0; i--) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    for (int i = len - 1; i >= 0; i--) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    if (strcmp(str, reversed) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int len = strlen(str);
    char* vowels = "aeiouAEIOU";
    char* result = malloc(len + 1);
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

// Function to count the frequency of each character in a string
void countFrequency(char* str) {
    int len = strlen(str);
    int freq[26] = {0};
    for (int i = 0; i < len; i++) {
        freq[(int)str[i] - 97]++;
    }
    printf("Frequency of characters:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", (char)(i + 97), freq[i]);
    }
}

int main() {
    char* str = "A man, a plan, a canal: Panama";
    printf("Original string: %s\n", str);
    reverse(str);
    printf("\n");
    isPalindrome(str);
    printf("\n");
    removeVowels(str);
    printf("\n");
    countFrequency(str);
    return 0;
}