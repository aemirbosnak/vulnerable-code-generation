//Falcon-180B DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compareWords(const void *a, const void *b) {
    struct WordFrequency *word1 = (struct WordFrequency *)a;
    struct WordFrequency *word2 = (struct WordFrequency *)b;

    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *inputFile;
    char inputBuffer[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    struct WordFrequency wordFrequencies[MAX_WORDS];

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        strcpy(word, inputBuffer);
        wordCount++;

        int found = 0;
        for (int i = 0; i < wordCount - 1; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordFrequencies[i].frequency++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(wordFrequencies[wordCount - 1].word, word);
            wordFrequencies[wordCount - 1].frequency = 1;
        }
    }

    qsort(wordFrequencies, wordCount, sizeof(struct WordFrequency), compareWords);

    printf("Word\tFrequency\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\t%d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    fclose(inputFile);

    return 0;
}