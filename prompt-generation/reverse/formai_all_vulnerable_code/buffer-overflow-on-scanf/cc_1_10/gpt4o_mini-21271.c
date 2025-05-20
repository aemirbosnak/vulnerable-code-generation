//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Shocking macro!
#define SHOCKING_MESSAGE "Behold! The strings are about to be manipulated in a most shocking fashion!\n"

// Function to remove vowels from a string
void removeVowels(char *str) {
    int n = strlen(str);
    char *result = (char *)malloc(n + 1); // allocate memory for result
    if (!result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        // Check if current character is a vowel
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
              str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')) {
            result[j++] = str[i]; // add consonants to result
        }
    }
    result[j] = '\0'; // null-terminate the result
    printf("Vowels removed: %s\n", result);
    free(result);
}

// Function to reverse a string
void reverseString(char *str) {
    int n = strlen(str);
    char *result = (char *)malloc(n + 1); // allocate memory for result
    if (!result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        result[i] = str[n - i - 1]; // reverse it
    }
    result[n] = '\0'; // null-terminate the result
    printf("Reversed string: %s\n", result);
    free(result);
}

// Function to find the length of a string
int stringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to concatenate two strings
void concatenateStrings(char *str1, const char *str2) {
    char *result = (char *)malloc(strlen(str1) + strlen(str2) + 1); // allocate memory for result
    if (!result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result, str1); // copy first string
    strcat(result, str2); // concatenate second string
    printf("Concatenated string: %s\n", result);
    free(result);
}

// Function to count occurrences of a character in a string
void countCharacterOccurrences(char *str, char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    printf("Character '%c' occurs %d times.\n", ch, count);
}

// Main function
int main() {
    printf(SHOCKING_MESSAGE);
    
    char str1[100], str2[100];
    char ch;

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // remove the newline character

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // remove the newline character

    printf("Enter a character to count: ");
    scanf(" %c", &ch); // note the space before %c to consume any leftover newline

    // Invoke string manipulation functions
    removeVowels(str1);
    reverseString(str1);
    int length = stringLength(str1);
    printf("Length of the first string: %d\n", length);
    concatenateStrings(str1, str2);
    countCharacterOccurrences(str1, ch);

    return 0;
}