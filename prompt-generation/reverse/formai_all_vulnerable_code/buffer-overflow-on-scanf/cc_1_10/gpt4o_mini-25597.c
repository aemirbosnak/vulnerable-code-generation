//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to capitalize the first letter of each word in a string
void capitalizeWords(char* str) {
    int capitalize = 1; // Flag to identify if we need to capitalize
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            capitalize = 1; // Reset flag for spaces
        } else if (capitalize) {
            str[i] = str[i] & ~0x20; // Capitalizing the letter
            capitalize = 0; // Reset the flag after capitalizing
        }
    }
}

// Function to reverse a given string
void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to find the length of the longest word in the string
int longestWordLength(char* str) {
    int maxLength = 0, currentLength = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 0; // Reset current word length
        } else {
            currentLength++;
        }
    }
    return currentLength > maxLength ? currentLength : maxLength; // Final comparison for last word
}

// Function to replace all occurrences of a word in the string with another word
char* replaceWord(const char* str, const char* oldWord, const char* newWord) {
    char *result;
    int i, count = 0;
    int oldWordLen = strlen(oldWord);
    int newWordLen = strlen(newWord);

    // Counting the number of times oldWord occurs in str
    for (i = 0; str[i] != '\0'; i++) {
        if (strstr(&str[i], oldWord) == &str[i]) {
            count++;
            i += oldWordLen - 1; // Skip the old word
        }
    }

    // Allocate space for new result string
    result = (char*)malloc(i + count * (newWordLen - oldWordLen) + 1);
    if (!result) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    i = 0;
    while (*str) {
        // Compare the substring with the newWord
        if (strstr(str, oldWord) == str) {
            strcpy(&result[i], newWord); // Replace with newWord
            i += newWordLen;
            str += oldWordLen; // Advance the oldWord
        } else {
            result[i++] = *str++; // Copy character
        }
    }
    result[i] = '\0';
    return result;
}

int main() {
    char str[256];
    
    printf("Enter a string (max 255 characters): ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character from input string if present
    str[strcspn(str, "\n")] = 0;

    printf("\nOriginal string: '%s'\n", str);

    // Capitalize words
    char capitalizedStr[256];
    strcpy(capitalizedStr, str);
    capitalizeWords(capitalizedStr);
    printf("Capitalized string: '%s'\n", capitalizedStr);

    // Reverse the original string
    char reversedStr[256];
    strcpy(reversedStr, str);
    reverseString(reversedStr);
    printf("Reversed string: '%s'\n", reversedStr);

    // Find the longest word length
    int longestLength = longestWordLength(str);
    printf("Length of the longest word: %d\n", longestLength);

    // Replace a word in the string
    char oldWord[50], newWord[50];
    printf("Enter a word to replace: ");
    scanf("%s", oldWord);
    printf("Enter the new word: ");
    scanf("%s", newWord);

    char* replacedStr = replaceWord(str, oldWord, newWord);
    printf("String after replacement: '%s'\n", replacedStr);

    free(replacedStr);
    return 0;
}