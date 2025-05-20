//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isWordCharacter(char c) {
    return isalnum(c) || c == '\''; // Allow alphanumeric characters and apostrophes
}

int isNewWord(char *word, WordCount *wordCounts, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            return 0; // The word already exists
        }
    }
    return 1; // New word
}

void insertWord(char *word, WordCount *wordCounts, int *size) {
    strcpy(wordCounts[*size].word, word);
    wordCounts[*size].count = 1;
    (*size)++;
}

void updateWordCount(char *word, WordCount *wordCounts, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return;
        }
    }
}

void printWordCounts(WordCount *wordCounts, int size) {
    printf("\nWord Count Summary:\n");
    printf("--------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
    printf("--------------------\n");
}

void freeMemory(WordCount *wordCounts) {
    free(wordCounts);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordCount *wordCounts = malloc(MAX_WORDS * sizeof(WordCount));
    
    if (wordCounts == NULL) {
        fclose(file);
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    char currentWord[MAX_WORD_LENGTH];
    int wordCountSize = 0;

    while (fscanf(file, "%s", currentWord) != EOF) {
        toLowerCase(currentWord);
        
        // Clean the word to remove non-word characters
        char cleanedWord[MAX_WORD_LENGTH];
        int j = 0;

        for (int i = 0; currentWord[i]; i++) {
            if (isWordCharacter(currentWord[i])) {
                cleanedWord[j++] = currentWord[i];
            }
        }
        cleanedWord[j] = '\0';

        if (strlen(cleanedWord) > 0) {
            if (isNewWord(cleanedWord, wordCounts, wordCountSize)) {
                insertWord(cleanedWord, wordCounts, &wordCountSize);
            } else {
                updateWordCount(cleanedWord, wordCounts, wordCountSize);
            }
        }
    }

    fclose(file);
    printWordCounts(wordCounts, wordCountSize);
    freeMemory(wordCounts);

    return EXIT_SUCCESS;
}