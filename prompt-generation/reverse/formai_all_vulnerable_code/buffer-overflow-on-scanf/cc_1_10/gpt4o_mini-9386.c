//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void clearInputBuffer() {
    while (getchar() != '\n');
}

void getInputString(char *str, int max_length) {
    printf("Enter a string (max %d characters): ", max_length - 1);
    fgets(str, max_length, stdin);
    str[strcspn(str, "\n")] = 0; // Remove the trailing newline
}

void concatenateStrings(char *dest, const char *src1, const char *src2) {
    strcpy(dest, src1);
    strcat(dest, src2);
}

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int countOccurrences(const char *str, char ch) {
    int count = 0;
    while (*str) {
        if (*str == ch) count++;
        str++;
    }
    return count;
}

void findSubstring(const char *haystack, const char *needle) {
    char *pos = strstr(haystack, needle);
    if (pos) {
        printf("Substring '%s' found at position: %ld\n", needle, pos - haystack);
    } else {
        printf("Substring '%s' not found.\n", needle);
    }
}

void displayStringDetails(const char *str) {
    int length = strlen(str);
    printf("String: '%s'\n", str);
    printf("Length: %d\n", length);
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    char concatenated[MAX_LENGTH * 2];
    char substring[MAX_LENGTH], character;
    int occurrences;

    clearInputBuffer(); // Ensure the input buffer is clear

    // Get first string
    getInputString(str1, MAX_LENGTH);

    // Get second string
    getInputString(str2, MAX_LENGTH);

    // Concatenation
    concatenateStrings(concatenated, str1, str2);
    printf("Concatenated string: '%s'\n", concatenated);

    // Reverse first string
    char reversed1[MAX_LENGTH];
    strcpy(reversed1, str1);
    reverseString(reversed1);
    printf("Reversed first string: '%s'\n", reversed1);

    // Reverse second string
    char reversed2[MAX_LENGTH];
    strcpy(reversed2, str2);
    reverseString(reversed2);
    printf("Reversed second string: '%s'\n", reversed2);

    // Count occurrences of a character
    printf("Enter a character to count its occurrences in the first string: ");
    scanf(" %c", &character);
    occurrences = countOccurrences(str1, character);
    printf("Character '%c' occurs %d times in the first string.\n", character, occurrences);
    clearInputBuffer(); // Clear input buffer for next input

    // Get substring to find
    getInputString(substring, MAX_LENGTH);
    findSubstring(str1, substring);
    findSubstring(str2, substring);

    // Display details of the first string
    displayStringDetails(str1);

    return 0;
}