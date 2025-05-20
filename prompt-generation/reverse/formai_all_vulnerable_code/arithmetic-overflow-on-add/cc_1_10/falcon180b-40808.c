//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: protected
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

void printWordFrequencies(struct WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(struct WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    FILE *file;
    char line[100];
    char word[MAX_WORD_LENGTH];
    int wordLength;
    struct WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        int inWord = 0;
        for (int i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                inWord = 1;
            } else if (inWord) {
                inWord = 0;
                word[wordLength] = '\0';
                strcpy(wordFrequencies[numWords].word, word);
                wordFrequencies[numWords].frequency++;
                wordLength = 0;
            }

            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached!\n");
                exit(1);
            }

            numWords++;
        }

        if (inWord) {
            word[wordLength] = '\0';
            strcpy(wordFrequencies[numWords - 1].word, word);
            wordFrequencies[numWords - 1].frequency++;
        }
    }

    fclose(file);

    printWordFrequencies(wordFrequencies, numWords);

    return 0;
}