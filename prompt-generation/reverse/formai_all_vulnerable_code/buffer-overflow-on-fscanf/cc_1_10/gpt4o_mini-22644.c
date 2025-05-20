//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Function to load the dictionary into an array
int loadDictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        return -1;
    }

    int wordCount = 0;
    while (wordCount < MAX_DICTIONARY_SIZE && fscanf(file, "%s", dictionary[wordCount]) != EOF) {
        toLowerCase(dictionary[wordCount]); // Convert dictionary word to lowercase
        wordCount++;
    }
    fclose(file);
    return wordCount;
}

// Function to check if a word is in the dictionary
int checkWord(const char *word, char dictionary[][MAX_WORD_LENGTH], int dictionarySize) {
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Found the word
        }
    }
    return 0; // Word not found
}

// Function to read input text and check for spelling
void spellCheck(const char *inputFilename, char dictionary[][MAX_WORD_LENGTH], int dictionarySize) {
    FILE *file = fopen(inputFilename, "r");
    if (!file) {
        perror("Could not open input file");
        return;
    }

    char word[MAX_WORD_LENGTH];
    printf("Misspelled words:\n");
    while (fscanf(file, "%s", word) != EOF) {
        toLowerCase(word); // Convert word to lowercase
        // Remove punctuation
        for (int i = 0; word[i]; i++) {
            if (ispunct(word[i])) {
                word[i] = '\0'; // Replace punctuation with null terminator
                break;
            }
        }
        if (!checkWord(word, dictionary, dictionarySize)) {
            printf("%s\n", word); // Print the misspelled word
        }
    }
    fclose(file);
}

// Main function
int main() {
    char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
    const char *dictionaryFile = "dictionary.txt"; // Name of the dictionary file
    const char *inputFile; // Name of the input text file

    printf("Enter the name of the input text file: ");
    scanf("%s", inputFile);

    int dictionarySize = loadDictionary(dictionaryFile, dictionary);
    if (dictionarySize < 0) {
        return EXIT_FAILURE; // Error loading dictionary
    }

    spellCheck(inputFile, dictionary, dictionarySize);

    return EXIT_SUCCESS;
}