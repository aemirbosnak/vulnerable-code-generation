//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Declare function to reverse the string
void reverseString(char* str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (end > start) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

// Declare function to remove all non-alphanumeric characters from the string
void removeNonAlphaNumeric(char* str) {
    int readIndex = 0, writeIndex = 0;

    while (str[readIndex]) {
        // Check if element is alphanumeric
        if (isalnum(str[readIndex])) {
            str[writeIndex++] = str[readIndex];
        }
        readIndex++;
    }

    // Add null terminator at the end of string
    str[writeIndex] = '\0';
}

int main() {
    char inputString[100];

    // Take user input
    printf("Enter a string: ");
    fgets(inputString, 100, stdin);

    // Remove trailing newline character
    if (inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }

    // Make all characters lowercase
    for (int i = 0; i < strlen(inputString); i++) {
        inputString[i] = tolower(inputString[i]);
    }

    // Remove all non-alphanumeric characters
    removeNonAlphaNumeric(inputString);

    // Reverse the string
    char reversedString[100];
    strcpy(reversedString, inputString);
    reverseString(reversedString);

    // Check if string is a palindrome
    if (strcmp(inputString, reversedString) == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}