//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 1000

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char reversed[MAX_STRING_LENGTH];
    int index = 0;
    for (int i = length - 1; i >= 0; i--) {
        reversed[index++] = str[i];
    }
    strcpy(str, reversed);
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
    char vowels = "aeiouAEIOU";
    for (int i = 0; i < length; i++) {
        if (strchr(vowels, str[i])!= NULL) {
            str[i] = '\0';
        }
    }
}

// Function to convert a string to uppercase
void toUpperCase(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char string[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    scanf("%s", string);

    // Reverse the string
    reverseString(string);
    printf("Reversed string: %s\n", string);

    // Check if the string is a palindrome
    int isPalindromeResult = isPalindrome(string);
    if (isPalindromeResult == 1) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Remove all vowels from the string
    removeVowels(string);
    printf("String without vowels: %s\n", string);

    // Convert the string to uppercase
    toUpperCase(string);
    printf("String in uppercase: %s\n", string);

    // Convert the string to lowercase
    toLowerCase(string);
    printf("String in lowercase: %s\n", string);

    return 0;
}