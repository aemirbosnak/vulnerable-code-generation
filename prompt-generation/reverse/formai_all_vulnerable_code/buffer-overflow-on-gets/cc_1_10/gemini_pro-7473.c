//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to count the number of words in a string */
int countWords(const char *str) {
    int wordCount = 0;
    int inWord = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!inWord && str[i] != ' ') {
            inWord = 1;
            wordCount++;
        } else if (inWord && str[i] == ' ') {
            inWord = 0;
        }
    }
    return wordCount;
}

/* Function to count the number of lines in a string */
int countLines(const char *str) {
    int lineCount = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            lineCount++;
        }
    }
    return lineCount;
}

/* Function to count the number of characters in a string */
int countChars(const char *str) {
    int charCount = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        charCount++;
    }
    return charCount;
}

/* Function to print the most frequent word in a string */
void printMostFrequentWord(const char *str) {
    // Create a hash table to store the word frequencies
    int *hashTable[256];
    for (int i = 0; i < 256; i++) {
        hashTable[i] = 0;
    }
    // Fill the hash table with the word frequencies
    int maxFreq = 0;
    char *mostFrequentWord = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            hashTable[str[i]]++;
            if (hashTable[str[i]] > maxFreq) {
                maxFreq = hashTable[str[i]];
                mostFrequentWord = str[i];
            }
        }
    }
    // Print the most frequent word
    printf("The most frequent word is %c with a frequency of %d\n", mostFrequentWord, maxFreq);
}

/* Main function */
int main() {
    // Get the input string from the user
    char str[1000];
    printf("Enter a string: ");
    gets(str);
    // Count the number of words, lines, and characters in the string
    int wordCount = countWords(str);
    int lineCount = countLines(str);
    int charCount = countChars(str);
    // Print the results
    printf("The string has %d words, %d lines, and %d characters.\n", wordCount, lineCount, charCount);
    // Print the most frequent word in the string
    printMostFrequentWord(str);
    return 0;
}