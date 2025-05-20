//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(char *filename, WordFrequency *wordFrequencies) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, wordFrequencies[i].word) == 0) {
                wordFrequencies[i].frequency++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("Error: too many unique words in file\n");
            exit(1);
        }
    }

    fclose(file);
}

void calculateFrequencies(WordFrequency *wordFrequencies, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        wordFrequencies[i].frequency = (int) round((double) wordFrequencies[i].frequency / numWords * 100.0);
    }
}

void printFrequencies(WordFrequency *wordFrequencies, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d%%\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordFrequency wordFrequencies[MAX_WORDS];
    readWords(filename, wordFrequencies);

    int numWords = 0;
    while (strcmp(wordFrequencies[numWords].word, "")!= 0) {
        numWords++;
    }

    calculateFrequencies(wordFrequencies, numWords);
    printFrequencies(wordFrequencies, numWords);

    return 0;
}