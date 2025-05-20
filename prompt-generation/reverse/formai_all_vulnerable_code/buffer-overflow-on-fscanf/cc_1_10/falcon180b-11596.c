//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

void readWords(char* filename, WordFrequency* words, int* numWords) {
    FILE* file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (wordCount >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }

        int wordLength = strlen(word);
        if (wordLength > MAX_WORD_LENGTH) {
            printf("Error: Word '%s' is too long.\n", word);
            exit(1);
        }

        strcpy(words[wordCount].word, word);
        words[wordCount].frequency = 1;
        wordCount++;
    }

    fclose(file);
    *numWords = wordCount;
}

void sortWords(WordFrequency* words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
}

void printWords(WordFrequency* words, int numWords, int numToPrint) {
    printf("Top %d most frequent words:\n", numToPrint);
    for (int i = 0; i < numToPrint && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_WORD_LENGTH];
    strcpy(filename, argv[1]);

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(filename, words, &numWords);
    sortWords(words, numWords);
    printWords(words, numWords, 10);

    return 0;
}