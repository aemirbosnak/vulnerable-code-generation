//FormAI DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_WORDS 10000

int loadDictionary(char* dictionary[], char* fileName);
int processText(char* dictionary[], char* text);

int main(int argc, char* argv[]) {

    // Check argument count
    if (argc != 3) {
        printf("Usage: %s <dictionary file> <text file>\n", argv[0]);
        return 1;
    }

    char* dictionary[MAX_DICTIONARY_WORDS];
    int dictionarySize = loadDictionary(dictionary, argv[1]);

    // Check if dictionary loaded successfully
    if (dictionarySize == -1) {
        printf("Error: Could not load dictionary from file %s\n", argv[1]);
        return 1;
    }

    // Open text file
    FILE* textFile = fopen(argv[2], "r");

    // Check if text file exists and can be opened
    if (textFile == NULL) {
        printf("Error: File %s could not be opened\n", argv[2]);
        return 1;
    }

    // Read text from file
    char* text = (char*) malloc(sizeof(char) * MAX_WORD_LENGTH);
    char* buffer = (char*) malloc(sizeof(char) * MAX_WORD_LENGTH);

    while (fscanf(textFile, "%s", buffer) != EOF) {
        strcat(text, buffer);
        strcat(text, " ");
    }

    fclose(textFile);
    free(buffer);

    // Process text and get number of misspelled words
    int misspelledWords = processText(dictionary, text);

    // Print results
    printf("Number of misspelled words: %d\n", misspelledWords);

    // Free memory
    for (int i = 0; i < dictionarySize; i++) {
        free(dictionary[i]);
    }
    free(text);

    return 0;
}

int loadDictionary(char* dictionary[], char* fileName) {

    FILE* dictionaryFile = fopen(fileName, "r");

    // Check if dictionary file exists and can be opened
    if (dictionaryFile == NULL) {
        return -1;
    }

    char* word = (char*) malloc(sizeof(char) * MAX_WORD_LENGTH);
    int i = 0;

    while (fscanf(dictionaryFile, "%s", word) != EOF && i < MAX_DICTIONARY_WORDS) {
        dictionary[i] = (char*) malloc(sizeof(char) * strlen(word));
        strcpy(dictionary[i], word);
        i++;
    }

    fclose(dictionaryFile);
    free(word);

    return i;
}

int processText(char* dictionary[], char* text) {

    int misspelledWords = 0;

    char* word = (char*) malloc(sizeof(char) * MAX_WORD_LENGTH);

    for (int i = 0; i < strlen(text); i++) {

        // Strip non-alphanumeric characters from word
        int j = 0;
        while (isalnum(text[i])) {
            word[j] = tolower(text[i]);
            i++;
            j++;
        }
        word[j] = '\0';

        // Check if word is misspelled
        int found = 0;
        for (int k = 0; k < MAX_DICTIONARY_WORDS; k++) {
            if (dictionary[k] == NULL) {
                break;
            }
            if (strcmp(dictionary[k], word) == 0) {
                found = 1;
                break;
            }
        }
        if (!found && strlen(word) > 0) {
            printf("- %s\n", word);
            misspelledWords++;
        }
    }

    free(word);

    return misspelledWords;
}