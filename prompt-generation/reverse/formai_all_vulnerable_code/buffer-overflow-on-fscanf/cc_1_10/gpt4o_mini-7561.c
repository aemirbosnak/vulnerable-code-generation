//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000

// Function to read the dictionary from a file
int loadDictionary(char words[][MAX_WORD_LENGTH], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open dictionary file: %s\n", filename);
        return 0;
    }

    int count = 0;
    while (count < DICTIONARY_SIZE && fscanf(file, "%s", words[count]) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}

// Function to check if a word is in the dictionary
int isWordInDictionary(const char *word, char words[][MAX_WORD_LENGTH], int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(word, words[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to split a text into words
int splitWords(const char *text, char words[][MAX_WORD_LENGTH]) {
    int count = 0;
    char *str = strdup(text);
    char *token = strtok(str, " ,.-\n");
    
    while (token != NULL && count < DICTIONARY_SIZE) {
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, " ,.-\n");
    }
    free(str);
    return count;
}

// Main function
int main() {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    char inputText[1000];
    char inputWords[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    
    int wordCount = loadDictionary(dictionary, "dictionary.txt");
    if (wordCount == 0) {
        return 1; // Exit if dictionary loading failed
    }

    printf("Enter the text to check for spelling errors:\n");
    fgets(inputText, sizeof(inputText), stdin);

    int numWords = splitWords(inputText, inputWords);

    printf("\nSpelling mistakes:\n");
    for (int i = 0; i < numWords; i++) {
        // Remove punctuation from the word
        char cleanWord[MAX_WORD_LENGTH];
        strcpy(cleanWord, inputWords[i]);
        // Check if the word is in the dictionary
        if (!isWordInDictionary(cleanWord, dictionary, wordCount)) {
            printf(" - %s\n", cleanWord);
        }
    }

    return 0;
}