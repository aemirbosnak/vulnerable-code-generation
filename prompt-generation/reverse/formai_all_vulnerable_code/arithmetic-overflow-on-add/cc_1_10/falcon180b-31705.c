//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }
    reversed[length] = '\0';
    printf("Reversed string: %s\n", reversed);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i]!= str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int length = strlen(str);
    char* vowels = "aeiouAEIOU";
    char* newStr = malloc(length + 1);
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (strchr(vowels, str[i]) == NULL) {
            newStr[j++] = str[i];
        }
    }
    newStr[j] = '\0';
    printf("String without vowels: %s\n", newStr);
}

// Function to count the frequency of each character in a string
void countFrequency(char* str) {
    int length = strlen(str);
    int freq[26] = {0};
    for (int i = 0; i < length; i++) {
        freq[(int)str[i] - 97]++;
    }
    for (int i = 0; i < 26; i++) {
        printf("Frequency of %c: %d\n", i + 97, freq[i]);
    }
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
    printf("\n");
    countFrequency(str);
    return 0;
}