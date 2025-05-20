//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: Ada Lovelace
// Ada Lovelace style, Performance-Critical Component

// Preliminaries:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants and definitions:
#define MAX_LENGTH 100

// Function prototypes:
int countVowels(char* str);
int countConsonants(char* str);
int countWords(char* str);

// The main function:
int main() {
    // Variable declarations:
    char str[MAX_LENGTH];
    int vowels, consonants, words;

    // Get the string from the user:
    printf("Enter a string: ");
    scanf("%s", str);

    // Count the vowels, consonants, and words:
    vowels = countVowels(str);
    consonants = countConsonants(str);
    words = countWords(str);

    // Print the results:
    printf("The string '%s' contains:\n", str);
    printf("  %d vowels\n", vowels);
    printf("  %d consonants\n", consonants);
    printf("  %d words\n", words);

    return 0;
}

// Function to count the vowels in a string:
int countVowels(char* str) {
    // Variable declarations:
    int count = 0;
    int i;

    // Loop through the string:
    for (i = 0; str[i] != '\0'; i++) {
        // Check if the character is a vowel:
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            // Increment the count:
            count++;
        }
    }

    // Return the count:
    return count;
}

// Function to count the consonants in a string:
int countConsonants(char* str) {
    // Variable declarations:
    int count = 0;
    int i;

    // Loop through the string:
    for (i = 0; str[i] != '\0'; i++) {
        // Check if the character is a consonant:
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
                // Increment the count:
                count++;
            }
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            if (str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
                // Increment the count:
                count++;
            }
        }
    }

    // Return the count:
    return count;
}

// Function to count the words in a string:
int countWords(char* str) {
    // Variable declarations:
    int count = 0;
    int i;

    // Loop through the string:
    for (i = 0; str[i] != '\0'; i++) {
        // Check if the character is a space:
        if (str[i] == ' ') {
            // Increment the count:
            count++;
        }
    }

    // Return the count:
    return count + 1;
}