//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*)a;
    WordFrequency* wordB = (WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequencies(WordFrequency* wordFrequencies, int numWords) {
    printf("Word\tFrequency\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords == MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        word[strcspn(word, "\n")] = '\0'; // remove newline character

        if (strlen(word) > 0) {
            WordFrequency* wordFrequency = bsearch(word, wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

            if (wordFrequency == NULL) {
                strcpy(wordFrequencies[numWords].word, word);
                wordFrequencies[numWords].frequency = 1;
                numWords++;
            } else {
                wordFrequency->frequency++;
            }
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printWordFrequencies(wordFrequencies, numWords);

    return 0;
}