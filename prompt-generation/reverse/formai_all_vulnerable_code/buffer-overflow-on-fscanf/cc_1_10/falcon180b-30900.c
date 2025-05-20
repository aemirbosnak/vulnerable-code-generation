//Falcon-180B DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void ReadTextFile(FILE* inputFile, struct WordFrequency* wordFrequencies) {
    char word[MAX_WORD_LENGTH];
    int wordLength;
    while (fscanf(inputFile, "%s", word)!= EOF) {
        wordLength = strlen(word);
        if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
            for (int i = 0; i < MAX_WORDS; i++) {
                if (strcmp(wordFrequencies[i].word, word) == 0) {
                    wordFrequencies[i].frequency++;
                    break;
                }
            }
        }
    }
}

void SortWordsByFrequency(struct WordFrequency* wordFrequencies) {
    for (int i = 0; i < MAX_WORDS - 1; i++) {
        for (int j = i + 1; j < MAX_WORDS; j++) {
            if (wordFrequencies[j].frequency > wordFrequencies[i].frequency) {
                struct WordFrequency temp = wordFrequencies[i];
                wordFrequencies[i] = wordFrequencies[j];
                wordFrequencies[j] = temp;
            }
        }
    }
}

void PrintTopWords(struct WordFrequency* wordFrequencies, int numWords) {
    printf("Top %d most frequent words:\n", numWords);
    for (int i = 0; i < numWords && i < MAX_WORDS; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    FILE* inputFile;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    struct WordFrequency wordFrequencies[MAX_WORDS];
    ReadTextFile(inputFile, wordFrequencies);

    SortWordsByFrequency(wordFrequencies);

    PrintTopWords(wordFrequencies, 10);

    fclose(inputFile);
    return 0;
}