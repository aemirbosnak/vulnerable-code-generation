//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];
int numWords = 0;

void addWord(char *word) {
    if (numWords >= MAX_WORDS) {
        printf("Error: Too many words.\n");
        exit(1);
    }
    strcpy(words[numWords].word, word);
    words[numWords].count = 1;
    numWords++;
}

void readWords(FILE *file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        addWord(word);
    }
}

void printMisspelledWords(FILE *file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i, found = 0;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            fprintf(file, "Misspelled word: %s\n", word);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    if (argc < 3) {
        printf("Usage: %s dictionary.txt text.txt\n", argv[0]);
        exit(1);
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }
    readWords(file);
    fclose(file);

    file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error: Could not open text file.\n");
        exit(1);
    }
    printMisspelledWords(file);
    fclose(file);

    return 0;
}