//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordFrequencyA = a;
    const WordFrequency *wordFrequencyB = b;

    if (wordFrequencyA->frequency > wordFrequencyB->frequency) {
        return -1;
    } else if (wordFrequencyA->frequency < wordFrequencyB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

void readWords(FILE *file, WordFrequency *wordFrequencies) {
    char word[MAX_WORD_LENGTH];
    int wordLength;

    while (fscanf(file, "%s", word)!= EOF) {
        wordLength = strlen(word);

        if (wordLength > MAX_WORD_LENGTH) {
            wordLength = MAX_WORD_LENGTH;
        }

        strncpy(wordFrequencies->word, word, MAX_WORD_LENGTH);
        wordFrequencies->word[wordLength] = '\0';
        wordFrequencies->frequency++;
        wordFrequencies++;
    }
}

void writeWordFrequencies(FILE *file, WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        fprintf(file, "%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    readWords(file, wordFrequencies);
    fclose(file);

    writeWordFrequencies(stdout, wordFrequencies, numWords);

    return 0;
}