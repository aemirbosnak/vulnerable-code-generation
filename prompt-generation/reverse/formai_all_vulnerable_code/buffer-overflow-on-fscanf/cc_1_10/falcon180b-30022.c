//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

void readSentences(Sentence sentences[], int maxSentences) {
    FILE *file = fopen("sentences.txt", "r");
    int numSentences = 0;

    while (fscanf(file, "%s", sentences[numSentences].sentence)!= EOF && numSentences < maxSentences) {
        sentences[numSentences].length = strlen(sentences[numSentences].sentence);
        numSentences++;
    }

    fclose(file);
}

void countWordFrequencies(WordFrequency frequencies[], int maxWords, Sentence sentences[], int numSentences) {
    for (int i = 0; i < numSentences; i++) {
        char *token = strtok(sentences[i].sentence, " ");

        while (token!= NULL) {
            int j;
            for (j = 0; j < maxWords; j++) {
                if (strcmp(frequencies[j].word, token) == 0) {
                    frequencies[j].count++;
                    break;
                }
            }

            if (j == maxWords) {
                strcpy(frequencies[j].word, token);
                frequencies[j].count = 1;
            }

            token = strtok(NULL, " ");
        }
    }
}

void printWordFrequencies(WordFrequency frequencies[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main() {
    Sentence sentences[MAX_SENTENCES];
    WordFrequency frequencies[MAX_WORDS];

    srand(time(NULL));

    readSentences(sentences, MAX_SENTENCES);
    countWordFrequencies(frequencies, MAX_WORDS, sentences, MAX_SENTENCES);
    printWordFrequencies(frequencies, MAX_WORDS);

    return 0;
}