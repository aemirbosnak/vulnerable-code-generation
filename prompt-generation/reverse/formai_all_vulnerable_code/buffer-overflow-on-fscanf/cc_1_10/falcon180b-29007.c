//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 10000

typedef struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(FILE *file, WordFrequency *words) {
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (wordCount >= MAX_NUM_WORDS) {
            printf("Error: Exceeded maximum number of words.\n");
            exit(1);
        }

        strcpy(words[wordCount].word, word);
        words[wordCount].frequency = 1;
        wordCount++;
    }
}

void countWordFrequencies(WordFrequency *words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

void printWordFrequencies(WordFrequency *words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    WordFrequency words[MAX_NUM_WORDS];
    readWords(file, words);
    fclose(file);

    countWordFrequencies(words, MAX_NUM_WORDS);
    printWordFrequencies(words, MAX_NUM_WORDS);

    return 0;
}