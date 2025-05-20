//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

// Struct to hold word information
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

// Function to compare two words (case insensitive)
int compareWords(const void* a, const void* b) {
    const Word* wordA = a;
    const Word* wordB = b;

    return strcasecmp(wordA->word, wordB->word);
}

// Function to read words from a file and store them in an array
int readWordsFromFile(FILE* file, Word words[]) {
    char line[MAX_WORD_LENGTH];
    int numWords = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char* word = strtok(line, ",.!?;:\"'");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many words in file.\n");
                exit(1);
            }

            int length = strlen(word);
            if (length > MAX_WORD_LENGTH) {
                printf("Error: Word \"%s\" is too long.\n", word);
                exit(1);
            }

            strcpy(words[numWords].word, word);
            words[numWords].count = 0;
            numWords++;

            word = strtok(NULL, ",.!?;:\"'");
        }
    }

    return numWords;
}

// Function to spell check a word
bool spellCheck(const char* word) {
    char dictionary[MAX_WORD_LENGTH];
    strcpy(dictionary, "dictionary.txt");
    FILE* file = fopen(dictionary, "r");

    if (file == NULL) {
        printf("Error: Dictionary file not found.\n");
        exit(1);
    }

    Word words[MAX_WORDS];
    int numWords = readWordsFromFile(file, words);
    fclose(file);

    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(word, words[i].word) == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    int numWords = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char* word = strtok(line, ",.!?;:\"'");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many words in file.\n");
                exit(1);
            }

            int length = strlen(word);
            if (length > MAX_WORD_LENGTH) {
                printf("Error: Word \"%s\" is too long.\n", word);
                exit(1);
            }

            strcpy(filename, word);

            if (!spellCheck(word)) {
                printf("Misspelled word: %s\n", word);
            }

            word = strtok(NULL, ",.!?;:\"'");
            numWords++;
        }
    }

    fclose(file);

    return 0;
}