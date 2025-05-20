//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 100
#define DICTIONARY_FILE "dictionary.txt"

typedef struct word {
    char word[MAX_WORD_LEN];
    bool isCorrect;
} Word;

void loadDictionary(Word *words) {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (file == NULL) {
        printf("Error loading dictionary file.\n");
        exit(1);
    }

    int wordCount = 0;
    while (fscanf(file, "%s", words[wordCount].word)!= EOF) {
        words[wordCount].isCorrect = true;
        wordCount++;
    }

    fclose(file);
}

bool isCorrect(const char *word) {
    Word *dictionary = (Word *)malloc(sizeof(Word));
    FILE *file = fopen(DICTIONARY_FILE, "r");
    int wordCount = 0;

    while (fscanf(file, "%s", dictionary[wordCount].word)!= EOF) {
        if (strcmp(dictionary[wordCount].word, word) == 0) {
            free(dictionary);
            return true;
        }
        wordCount++;
    }

    free(dictionary);
    return false;
}

int main() {
    Word words[MAX_WORD_LEN];
    loadDictionary(words);

    char input[MAX_WORD_LEN];
    printf("Enter text to spell check:\n");
    while (fgets(input, MAX_WORD_LEN, stdin)) {
        char *word = strtok(input, " ");
        while (word!= NULL) {
            if (!isCorrect(word)) {
                printf("Incorrect spelling: %s\n", word);
            }
            word = strtok(NULL, " ");
        }
    }

    return 0;
}