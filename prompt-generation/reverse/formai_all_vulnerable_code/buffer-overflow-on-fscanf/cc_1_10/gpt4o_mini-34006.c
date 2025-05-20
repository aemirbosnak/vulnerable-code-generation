//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

// Function prototypes
void loadDictionary(const char *filename, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int *wordCount);
int isWordInDictionary(const char *word, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int wordCount);
void toLowerCase(char *str);
void spellCheckFile(const char *filename, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int wordCount);
void extractWord(FILE *file, char *wordBuffer);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int wordCount = 0;

    loadDictionary(argv[1], dictionary, &wordCount);
    spellCheckFile(argv[2], dictionary, wordCount);
    
    return 0;
}

void loadDictionary(const char *filename, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int *wordCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(1);
    }

    while (fscanf(file, "%s", dictionary[*wordCount]) != EOF) {
        toLowerCase(dictionary[*wordCount]); // Normalize to lowercase
        (*wordCount)++;
        if (*wordCount >= MAX_DICTIONARY_SIZE) {
            fprintf(stderr, "Dictionary is too large.\n");
            fclose(file);
            exit(1);
        }
    }

    fclose(file);
}

int isWordInDictionary(const char *word, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void spellCheckFile(const char *filename, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int wordCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open text file");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    printf("Misspelled words:\n");
    
    while (1) {
        extractWord(file, word);
        if (feof(file)) break;

        toLowerCase(word); // Normalize to lowercase
        if (isWordInDictionary(word, dictionary, wordCount) == 0) {
            printf("%s\n", word);
        }
    }

    fclose(file);
}

void extractWord(FILE *file, char *wordBuffer) {
    char ch;
    int index = 0;

    // Skip non-alphabetic characters
    while ((ch = fgetc(file)) != EOF && !isalpha(ch));

    // If end of file is reached
    if (ch == EOF) {
        wordBuffer[0] = '\0'; // Indicate end of input
        return;
    }

    // Store the word
    do {
        wordBuffer[index++] = ch;
        ch = fgetc(file);
    } while (isalpha(ch) && index < MAX_WORD_LENGTH - 1);

    wordBuffer[index] = '\0'; // Null-terminate the string
}