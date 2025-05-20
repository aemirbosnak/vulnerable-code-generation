//Falcon-180B DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
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

int main() {
    FILE *inputFile;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    int totalWords = 0;
    struct WordFrequency *wordFrequencyTable;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    wordFrequencyTable = malloc(MAX_WORDS * sizeof(struct WordFrequency));

    while (fscanf(inputFile, "%s", line)!= EOF) {
        totalWords += 1;

        char *token = strtok(line, ",.?!;:");

        while (token!= NULL) {
            strcpy(word, token);
            word[strcspn(word, ",.?!;:")] = '\0';

            if (wordCount >= MAX_WORDS) {
                printf("Error: maximum number of words reached.\n");
                exit(1);
            }

            if (strlen(word) > MAX_WORD_LENGTH) {
                printf("Error: word length exceeds maximum limit.\n");
                exit(1);
            }

            int index = wordCount;

            while (index > 0 && strcmp(wordFrequencyTable[index - 1].word, word) > 0) {
                memcpy(&wordFrequencyTable[index], &wordFrequencyTable[index - 1], sizeof(struct WordFrequency));
                index--;
            }

            strcpy(wordFrequencyTable[index].word, word);
            wordFrequencyTable[index].frequency = 1;

            wordCount++;

            token = strtok(NULL, ",.?!;:");
        }
    }

    qsort(wordFrequencyTable, wordCount, sizeof(struct WordFrequency), compareWords);

    printf("Total words: %d\n", totalWords);

    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFrequencyTable[i].word, wordFrequencyTable[i].frequency);
    }

    free(wordFrequencyTable);

    return 0;
}