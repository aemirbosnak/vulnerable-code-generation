//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000

// Function prototypes
void loadDictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *wordCount);
int isSpellingCorrect(const char *word, char dictionary[][MAX_WORD_LENGTH], int wordCount);
void toLowerCase(char *str);

// Main function to read the input file and check for spelling errors
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int wordCount = 0;

    // Load the dictionary
    loadDictionary(argv[1], dictionary, &wordCount);

    // Open the input text file
    FILE *textFile = fopen(argv[2], "r");
    if (textFile == NULL) {
        perror("Error opening text file");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(textFile, "%s", word) != EOF) {
        // Process punctuation
        for (int i = 0; i < strlen(word); i++) {
            if (ispunct(word[i])) {
                word[i] = '\0'; // Terminate the string at punctuation
                break;
            }
        }

        // Check spelling
        if (!isSpellingCorrect(word, dictionary, wordCount)) {
            printf("Misspelled word: %s\n", word);
        }
    }

    // Cleanup
    fclose(textFile);
    return 0;
}

// Function to load the dictionary from a file
void loadDictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *wordCount) {
    FILE *dictFile = fopen(filename, "r");
    if (dictFile == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    while (fscanf(dictFile, "%s", dictionary[*wordCount]) != EOF) {
        toLowerCase(dictionary[*wordCount]);
        (*wordCount)++;
        if (*wordCount >= DICTIONARY_SIZE) {
            printf("Dictionary size limit reached!\n");
            break;
        }
    }

    fclose(dictFile);
}

// Function to check if a word is in the dictionary
int isSpellingCorrect(const char *word, char dictionary[][MAX_WORD_LENGTH], int wordCount) {
    char lowerWord[MAX_WORD_LENGTH];
    strcpy(lowerWord, word);
    toLowerCase(lowerWord);

    for (int i = 0; i < wordCount; i++) {
        if (strcmp(lowerWord, dictionary[i]) == 0) {
            return 1; // Correct spelling
        }
    }

    return 0; // Incorrect spelling
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}