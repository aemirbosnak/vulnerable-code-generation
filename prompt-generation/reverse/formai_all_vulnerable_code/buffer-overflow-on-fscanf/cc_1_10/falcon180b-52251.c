//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compareWords(const void *a, const void *b) {
    struct WordFrequency *wordA = (struct WordFrequency *)a;
    struct WordFrequency *wordB = (struct WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequency(struct WordFrequency *wordFrequency, int numWords) {
    qsort(wordFrequency, numWords, sizeof(struct WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    int wordLength = 0;
    int numWords = 0;

    struct WordFrequency wordFrequency[MAX_WORDS];

    while (fscanf(file, "%s", word)!= EOF) {
        word[wordLength] = '\0';
        for (int i = 0; i < wordLength; i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                wordLength = i;
                break;
            }
        }

        for (int i = 0; i < numWords; i++) {
            if (strcmp(wordFrequency[i].word, word) == 0) {
                wordFrequency[i].frequency++;
                break;
            }
        }

        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words (%d) reached.\n", MAX_WORDS);
            break;
        }

        strcpy(wordFrequency[numWords].word, word);
        wordFrequency[numWords].frequency = 1;
        numWords++;
    }

    fclose(file);

    printWordFrequency(wordFrequency, numWords);

    return 0;
}