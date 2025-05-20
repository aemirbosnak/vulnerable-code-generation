//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define DICT_SIZE 1000
#define BUFFER_SIZE 1024

// Structure to store dictionary words
typedef struct Dictionary {
    char words[DICT_SIZE][MAX_WORD_LENGTH];
    int count;
} Dictionary;

// Function to load words into the dictionary
Dictionary loadDictionary(const char *filename) {
    Dictionary dict;
    dict.count = 0;
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dict.words[dict.count]) != EOF && dict.count < DICT_SIZE) {
        dict.count++;
    }

    fclose(file);
    return dict;
}

// Function to check if a word is in the dictionary
int isWordInDictionary(const Dictionary *dict, const char *word) {
    for (int i = 0; i < dict->count; i++) {
        if (strcasecmp(dict->words[i], word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to split text into words
void splitWords(char *text, char words[][MAX_WORD_LENGTH], int *wordCount) {
    char *token = strtok(text, " \n\r\t,.!?:;");
    *wordCount = 0;

    while (token != NULL && *wordCount < BUFFER_SIZE) {
        strncpy(words[(*wordCount)++], token, MAX_WORD_LENGTH);
        token = strtok(NULL, " \n\r\t,.!?:;");
    }
}

// Function to display potential misspelled words
void checkSpelling(const Dictionary *dict, char *text) {
    char words[BUFFER_SIZE][MAX_WORD_LENGTH];
    int wordCount = 0;
    
    splitWords(text, words, &wordCount);
    
    printf("Potentially misspelled words:\n");
    for (int i = 0; i < wordCount; i++) {
        if (!isWordInDictionary(dict, words[i])) {
            printf(" - %s\n", words[i]);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dictionaryFile = argv[1];
    const char *textFile = argv[2];

    // Load the dictionary
    Dictionary dict = loadDictionary(dictionaryFile);

    // Load the text
    FILE *text_fp = fopen(textFile, "r");
    if (!text_fp) {
        perror("Failed to open text file");
        return EXIT_FAILURE;
    }

    char *text = (char *)malloc(BUFFER_SIZE * sizeof(char));
    if (!text) {
        perror("Failed to allocate memory");
        fclose(text_fp);
        return EXIT_FAILURE;
    }

    fread(text, sizeof(char), BUFFER_SIZE, text_fp);
    fclose(text_fp);

    // Check spelling
    checkSpelling(&dict, text);

    // Free allocated memory
    free(text);
    
    return EXIT_SUCCESS;
}