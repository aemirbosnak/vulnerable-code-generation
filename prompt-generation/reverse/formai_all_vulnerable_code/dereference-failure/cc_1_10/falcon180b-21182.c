//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE "dictionary.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

WordPair dictionary[MAX_WORDS];
int numWords = 0;

void loadDictionary() {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");
        char *translation = strtok(NULL, " ");

        if (word == NULL || translation == NULL) {
            printf("Error: malformed line in dictionary file.\n");
            exit(1);
        }

        strcpy(dictionary[numWords].word, word);
        strcpy(dictionary[numWords].translation, translation);

        numWords++;
    }

    fclose(file);
}

int findWord(char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    loadDictionary();

    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        char *word = strtok(input, " ");
        int wordIndex = findWord(word);

        if (wordIndex == -1) {
            printf("Unknown word: %s\n", word);
        } else {
            printf("Translation: %s\n", dictionary[wordIndex].translation);
        }
    }

    return 0;
}