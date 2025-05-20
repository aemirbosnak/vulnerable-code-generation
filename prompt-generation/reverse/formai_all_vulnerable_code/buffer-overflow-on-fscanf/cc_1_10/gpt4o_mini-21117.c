//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000
#define MAX_SUGGESTIONS 5

// Function to load the dictionary from a file
int loadDictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open dictionary file.\n");
        return 0;
    }

    int wordCount = 0;
    while (fscanf(file, "%s", dictionary[wordCount]) != EOF && wordCount < MAX_DICTIONARY_SIZE) {
        wordCount++;
    }
    fclose(file);
    return wordCount;
}

// Function to check if a word is in the dictionary
int checkWord(const char *word, char dictionary[][MAX_WORD_LENGTH], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcasecmp(word, dictionary[i]) == 0) {
            return 1;  // Word found
        }
    }
    return 0;  // Word not found
}

// Function to suggest similar words (very basic)
void suggestWords(const char *word, char dictionary[][MAX_WORD_LENGTH], int dictSize) {
    printf("Suggestions for '%s':\n", word);
    int suggestions = 0;

    for (int i = 0; i < dictSize && suggestions < MAX_SUGGESTIONS; i++) {
        if (abs((int)strlen(dictionary[i]) - (int)strlen(word)) <= 1) { 
            // Basic length difference; can be improved with more sophisticated algorithms
            printf("  %s\n", dictionary[i]);
            suggestions++;
        }
    }
}

// Function to read text from a file and check spelling
void checkSpelling(const char *filename, char dictionary[][MAX_WORD_LENGTH], int dictSize) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open the text file.\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Remove punctuation from the word
        for (int i = 0; word[i]; i++) {
            if (ispunct(word[i])) {
                word[i] = '\0';
                break;
            }
        }
        
        if (!checkWord(word, dictionary, dictSize)) {
            printf("Misspelled word: %s\n", word);
            suggestWords(word, dictionary, dictSize);
        }
    }
    fclose(file);
}

int main() {
    char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dictSize = loadDictionary("dictionary.txt", dictionary);

    if (dictSize > 0) {
        const char *textFile = "textfile.txt"; // Specify your text file
        checkSpelling(textFile, dictionary, dictSize);
    }

    return 0;
}