//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Galactic Word Frequency Counter v1.0
// Scans cosmic scrolls for omnipresent lexical entities

// Define the sentinel value for the end of the scroll
#define LEXICON_TERMINATOR "END_OF_SCROLL"

// Data structures to represent a single word and its frequency
typedef struct {
    char* word;
    int frequency;
} WordFrequency;

// Data structure to represent a cosmic lexicon of words
typedef struct {
    int size;
    WordFrequency* entries;
} Lexicon;

// Initialize a cosmic lexicon
Lexicon* createLexicon() {
    Lexicon* lexicon = malloc(sizeof(Lexicon));
    lexicon->size = 0;
    lexicon->entries = NULL;
    return lexicon;
}

// Add a word to the cosmic lexicon, or increment its frequency if it already exists
void addWordToLexicon(Lexicon* lexicon, char* word) {
    // Check if the word already exists in the lexicon
    for (int i = 0; i < lexicon->size; i++) {
        if (strcmp(lexicon->entries[i].word, word) == 0) {
            lexicon->entries[i].frequency++;
            return;
        }
    }

    // If the word doesn't exist, create a new entry for it
    lexicon->entries = realloc(lexicon->entries, (lexicon->size + 1) * sizeof(WordFrequency));
    lexicon->entries[lexicon->size].word = malloc(strlen(word) + 1);
    strcpy(lexicon->entries[lexicon->size].word, word);
    lexicon->entries[lexicon->size].frequency = 1;
    lexicon->size++;
}

// Scan a cosmic scroll and populate the cosmic lexicon
Lexicon* scanScroll(char* scroll) {
    Lexicon* lexicon = createLexicon();
    char* word = strtok(scroll, " .,;:-");
    while (word != NULL && strcmp(word, LEXICON_TERMINATOR) != 0) {
        addWordToLexicon(lexicon, word);
        word = strtok(NULL, " .,;:-");
    }
    return lexicon;
}

// Sort the cosmic lexicon by frequency in descending order
void sortLexiconByFrequency(Lexicon* lexicon) {
    for (int i = 0; i < lexicon->size - 1; i++) {
        for (int j = 0; j < lexicon->size - i - 1; j++) {
            if (lexicon->entries[j].frequency < lexicon->entries[j + 1].frequency) {
                WordFrequency temp = lexicon->entries[j];
                lexicon->entries[j] = lexicon->entries[j + 1];
                lexicon->entries[j + 1] = temp;
            }
        }
    }
}

// Print the cosmic lexicon to the interstellar console
void printLexicon(Lexicon* lexicon) {
    printf("Lexical entities discovered:\n\n");
    printf("---------------------\n");
    for (int i = 0; i < lexicon->size; i++) {
        printf("%-20s %d\n", lexicon->entries[i].word, lexicon->entries[i].frequency);
    }
    printf("---------------------\n\n");
}

// Free the memory allocated for the cosmic lexicon
void destroyLexicon(Lexicon* lexicon) {
    for (int i = 0; i < lexicon->size; i++) {
        free(lexicon->entries[i].word);
    }
    free(lexicon->entries);
    free(lexicon);
}

int main() {
    // Welcome message
    printf("\nGalactic Word Frequency Counter v1.0\n");
    printf("---------------------------------\n");

    // Get the cosmic scroll from the user
    char* scroll = malloc(10000);
    printf("Enter the cosmic scroll to be scanned (terminated by \"END_OF_SCROLL\"):\n");
    gets(scroll);

    // Scan the scroll and populate the cosmic lexicon
    Lexicon* lexicon = scanScroll(scroll);

    // Sort the lexicon by frequency
    sortLexiconByFrequency(lexicon);

    // Print the lexicon to the interstellar console
    printLexicon(lexicon);

    // Free the memory allocated for the lexicon
    destroyLexicon(lexicon);

    // Farewell message
    printf("\nMay your lexical explorations be fruitful!\n");

    return 0;
}