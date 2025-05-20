//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORD_COUNT 1000
#define MAX_FILE_NAME_LENGTH 100

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compareWords(const void *a, const void *b) {
    struct WordFrequency *wordA = (struct WordFrequency *)a;
    struct WordFrequency *wordB = (struct WordFrequency *)b;
    return strcmp(wordA->word, wordB->word);
}

void readWords(FILE *file, struct WordFrequency *words, int *wordCount) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        if (*wordCount >= MAX_WORD_COUNT) {
            printf("Error: Maximum word count exceeded.\n");
            exit(1);
        }
        strncpy(words[*wordCount].word, word, MAX_WORD_LENGTH);
        words[*wordCount].frequency = 1;
        (*wordCount)++;
    }
}

void sortWords(struct WordFrequency *words, int wordCount) {
    qsort(words, wordCount, sizeof(struct WordFrequency), compareWords);
}

void printWords(struct WordFrequency *words, int wordCount) {
    int i;
    for (i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    struct WordFrequency words[MAX_WORD_COUNT];
    int wordCount = 0;
    readWords(file, words, &wordCount);
    sortWords(words, wordCount);
    printWords(words, wordCount);
    fclose(file);
    return 0;
}