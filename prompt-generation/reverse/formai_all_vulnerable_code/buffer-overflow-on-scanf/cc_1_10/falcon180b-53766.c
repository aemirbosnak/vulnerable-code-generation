//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 10000

struct Word {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compareWords(const void *a, const void *b) {
    struct Word *wordA = (struct Word *)a;
    struct Word *wordB = (struct Word *)b;
    return strcmp(wordA->word, wordB->word);
}

void readWords(struct Word *words, int numWords, FILE *file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords == MAX_NUM_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }
        strcpy(words[numWords].word, word);
        words[numWords].frequency = 1;
        numWords++;
    }
}

void countWords(struct Word *words, int numWords, FILE *file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }
    }
}

void sortWords(struct Word *words, int numWords) {
    qsort(words, numWords, sizeof(struct Word), compareWords);
}

void printWords(struct Word *words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    struct Word words[MAX_NUM_WORDS];
    int numWords = 0;

    readWords(words, numWords, file);
    countWords(words, numWords, file);
    sortWords(words, numWords);
    printWords(words, numWords);

    fclose(file);
    return 0;
}