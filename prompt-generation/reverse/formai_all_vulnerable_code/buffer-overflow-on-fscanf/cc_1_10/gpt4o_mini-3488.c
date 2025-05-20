//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000

// Function to convert the string to lowercase
void toLowerCase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to load words from a dictionary file
int loadDictionary(char *filename, char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open dictionary file: %s\n", filename);
        return -1;
    }
    
    int count = 0;
    while (fscanf(file, "%s", dictionary[count]) != EOF && count < DICTIONARY_SIZE) {
        toLowerCase(dictionary[count]);
        count++;
    }
    
    fclose(file);
    return count;
}

// Function to check if a word is in the dictionary
int checkWord(char *word, char dictionary[][MAX_WORD_LENGTH], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Found the word
        }
    }
    return 0; // Word not found
}

// Function to suggest corrections for a misspelled word
void suggestCorrections(char *word, char dictionary[][MAX_WORD_LENGTH], int dictSize) {
    printf("Suggestions for '%s':\n", word);
    for (int i = 0; i < dictSize; i++) {
        if (strlen(dictionary[i]) == strlen(word)) {
            int differences = 0;
            for (int j = 0; j < strlen(word); j++) {
                if (word[j] != dictionary[i][j]) {
                    differences++;
                }
            }
            if (differences == 1) {
                printf("- %s\n", dictionary[i]);
            }
        }
    }
}

// Main Function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary file> <text file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dictSize = loadDictionary(argv[1], dictionary);
    if (dictSize < 0) {
        return EXIT_FAILURE;
    }

    FILE *textFile = fopen(argv[2], "r");
    if (textFile == NULL) {
        fprintf(stderr, "Could not open text file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    char word[MAX_WORD_LENGTH];
    printf("Spell checking the file: %s\n\n", argv[2]);

    while (fscanf(textFile, "%s", word) != EOF) {
        toLowerCase(word);
        if (!checkWord(word, dictionary, dictSize)) {
            printf("Misspelled word: %s\n", word);
            suggestCorrections(word, dictionary, dictSize);
        }
    }

    fclose(textFile);
    return EXIT_SUCCESS;
}