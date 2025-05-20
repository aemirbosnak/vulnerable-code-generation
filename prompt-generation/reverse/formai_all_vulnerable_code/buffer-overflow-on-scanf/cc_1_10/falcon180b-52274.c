//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string without using any built-in functions
void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = (char*)malloc(length + 1); // Allocate memory for the reversed string
    char* original = str;
    char* end = str + length - 1;

    // Iterate through the string and build the reversed string
    while (original < end) {
        *reversed++ = *original++;
    }

    // Add null terminator to the reversed string
    *reversed = '\0';

    // Print the reversed string
    printf("Reversed string: %s\n", reversed);

    // Free the memory allocated for the reversed string
    free(reversed);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    char* original = str;
    char* end = str + length - 1;

    // Iterate through the string and compare characters
    while (original < end) {
        if (*original!= *end) {
            return 0; // Not a palindrome
        }
        original++;
        end--;
    }

    return 1; // Palindrome
}

int main() {
    char* input = (char*)malloc(100); // Allocate memory for user input
    printf("Enter a string: ");
    scanf("%s", input);

    // Check if the input string is empty
    if (input[0] == '\0') {
        printf("Empty string\n");
        free(input);
        return 0;
    }

    // Reverse the input string
    reverseString(input);

    // Check if the reversed string is a palindrome
    if (isPalindrome(input)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    // Free the memory allocated for user input
    free(input);
    return 0;
}