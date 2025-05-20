//Falcon-180B DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCES 100
#define MAX_WORDS 1000
#define MIN_WORD_LENGTH 3

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void removePunctuation(char* sentence) {
    int i, j;
    for (i = 0, j = 0; sentence[i]!= '\0'; i++) {
        if (!isspace(sentence[i]) &&!ispunct(sentence[i])) {
            sentence[j++] = tolower(sentence[i]);
        }
    }
    sentence[j] = '\0';
}

int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

void printWordFrequencies(WordFrequency* frequencies, int numFrequencies) {
    qsort(frequencies, numFrequencies, sizeof(WordFrequency), compareWords);
    printf("Word\tFrequency\n");
    for (int i = 0; i < numFrequencies; i++) {
        printf("%s\t%d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main() {
    char input[MAX_SENTENCES][MAX_WORD_LENGTH];
    int numSentences = 0;
    printf("Enter sentences (type 'done' when finished):\n");
    while (scanf("%s", input[numSentences])!= EOF) {
        numSentences++;
    }

    WordFrequency frequencies[MAX_WORDS];
    int numFrequencies = 0;

    for (int i = 0; i < numSentences; i++) {
        char* sentence = input[i];
        char* word = strtok(sentence, " ");
        while (word!= NULL) {
            int wordLength = strlen(word);
            if (wordLength >= MIN_WORD_LENGTH) {
                for (int j = 0; j < numFrequencies; j++) {
                    if (strcmp(frequencies[j].word, word) == 0) {
                        frequencies[j].count++;
                        break;
                    }
                }
                if (numFrequencies >= MAX_WORDS) {
                    break;
                }
                strcpy(frequencies[numFrequencies].word, word);
                frequencies[numFrequencies].count = 1;
                numFrequencies++;
            }
            word = strtok(NULL, " ");
        }
    }

    printWordFrequencies(frequencies, numFrequencies);

    return 0;
}