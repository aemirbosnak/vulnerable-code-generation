//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

int main() {
    // Get the input string from the user.
    char str[MAX_STR_LEN];
    printf("Enter a string: ");
    scanf("%s", str);

    // Get the length of the input string.
    int len = strlen(str);

    // Create an array to store the reversed string.
    char reversedStr[MAX_STR_LEN];

    // Reverse the input string.
    for (int i = 0; i < len; i++) {
        reversedStr[i] = str[len - i - 1];
    }

    // Add a null terminator to the end of the reversed string.
    reversedStr[len] = '\0';

    // Print the reversed string.
    printf("Reversed string: %s\n", reversedStr);

    // Get the substring from the input string.
    char substring[MAX_STR_LEN];
    printf("Enter the starting index of the substring: ");
    int startIndex;
    scanf("%d", &startIndex);
    printf("Enter the ending index of the substring: ");
    int endIndex;
    scanf("%d", &endIndex);

    // Check if the starting index is valid.
    if (startIndex < 0 || startIndex >= len) {
        printf("Invalid starting index.\n");
        return EXIT_FAILURE;
    }

    // Check if the ending index is valid.
    if (endIndex < 0 || endIndex >= len) {
        printf("Invalid ending index.\n");
        return EXIT_FAILURE;
    }

    // Check if the starting index is less than the ending index.
    if (startIndex > endIndex) {
        printf("Invalid indices.\n");
        return EXIT_FAILURE;
    }

    // Copy the substring from the input string to the substring array.
    int subLen = endIndex - startIndex + 1;
    strncpy(substring, str + startIndex, subLen);

    // Add a null terminator to the end of the substring.
    substring[subLen] = '\0';

    // Print the substring.
    printf("Substring: %s\n", substring);

    // Get the index of the character in the input string.
    char character;
    printf("Enter the character to find: ");
    scanf(" %c", &character);

    // Find the index of the character in the input string.
    int index = strchr(str, character) - str;

    // Check if the character was found.
    if (index == -1) {
        printf("Character not found.\n");
        return EXIT_FAILURE;
    }

    // Print the index of the character.
    printf("Index of the character: %d\n", index);

    return EXIT_SUCCESS;
}