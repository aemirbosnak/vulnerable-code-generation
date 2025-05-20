//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define DICTIONARY_SIZE 5

// Function declarations
void reverseString(char *str);
void concatenateStrings(char *dest, const char *src);
void extractSubstring(const char *str, int start, int length, char *substr);
int spellCheck(const char *word, const char *dictionary[], int dictionarySize);

int main() {
    char inputString[MAX_SIZE];
    char additionalString[MAX_SIZE];
    char substring[MAX_SIZE];
    int start = 0, length = 0;
    const char *dictionary[DICTIONARY_SIZE] = {"hello", "world", "program", "string", "manipulation"};

    // Get input string from the user
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = 0; // Remove newline character

    // Reverse the string
    printf("Original String: %s\n", inputString);
    reverseString(inputString);
    printf("Reversed String: %s\n", inputString);

    // Concatenation
    printf("Enter another string to concatenate: ");
    fgets(additionalString, sizeof(additionalString), stdin);
    additionalString[strcspn(additionalString, "\n")] = 0; // Remove newline character
    concatenateStrings(inputString, additionalString);
    printf("Concatenated String: %s\n", inputString);

    // Substring extraction
    printf("Enter start index for substring (0-indexed): ");
    scanf("%d", &start);
    printf("Enter length of substring: ");
    scanf("%d", &length);
    extractSubstring(inputString, start, length, substring);
    printf("Extracted Substring: %s\n", substring);

    // Spell checking
    char wordToCheck[MAX_SIZE];
    printf("Enter a word to spell check: ");
    scanf("%s", wordToCheck);
    if(spellCheck(wordToCheck, dictionary, DICTIONARY_SIZE)) {
        printf("'%s' is spelled correctly!\n", wordToCheck);
    } else {
        printf("'%s' is not found in the dictionary.\n", wordToCheck);
    }

    return 0;
}

// Function to reverse a string
void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; ++i) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to concatenate two strings
void concatenateStrings(char *dest, const char *src) {
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0'; // Null terminate the resulting string
}

// Function to extract a substring
void extractSubstring(const char *str, int start, int length, char *substr) {
    if (start < 0 || start >= strlen(str) || length < 0) {
        strcpy(substr, "Invalid range!");
        return;
    }

    strncpy(substr, str + start, length);
    substr[length] = '\0'; // Null terminate the substring
}

// Function to check spelling against a dictionary
int spellCheck(const char *word, const char *dictionary[], int dictionarySize) {
    for (int i = 0; i < dictionarySize; ++i) {
        if (strcasecmp(word, dictionary[i]) == 0) {
            return 1; // Word is spelled correctly
        }
    }
    return 0; // Word is not found
}