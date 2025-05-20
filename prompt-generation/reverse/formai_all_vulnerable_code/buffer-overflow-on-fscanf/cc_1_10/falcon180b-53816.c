//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;
    return strcmp(wordA->word, wordB->word);
}

int readWordsFromFile(FILE *file, WordFrequency *words, int numWords) {
    char word[MAX_WORD_LENGTH];
    int numWordsRead = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (numWordsRead >= numWords) {
            break;
        }
        strcpy(words[numWordsRead].word, word);
        words[numWordsRead].frequency = 1;
        numWordsRead++;
    }

    return numWordsRead;
}

void countWordFrequencies(WordFrequency *words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    int numWords = 0;
    while (fgetc(file)!= EOF) {
        numWords++;
    }

    WordFrequency *words = malloc(sizeof(WordFrequency) * numWords);
    if (words == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    int numWordsRead = readWordsFromFile(file, words, numWords);

    countWordFrequencies(words, numWordsRead);

    free(words);
    fclose(file);

    return 0;
}