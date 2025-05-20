//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100
#define MIN_WORD_LENGTH 2

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void generateRandomWords(char *words[], int numWords, int minLength, int maxLength) {
    srand(time(NULL));
    for (int i = 0; i < numWords; i++) {
        int length = rand() % (maxLength - minLength + 1) + minLength;
        words[i] = (char *) malloc(length * sizeof(char));
        for (int j = 0; j < length; j++) {
            int randomChar = rand() % 26 + 'a';
            words[i][j] = tolower(randomChar);
        }
        words[i][length] = '\0';
    }
}

void sortWords(char *words[], int numWords, int (*compare)(const void *, const void *)) {
    qsort(words, numWords, sizeof(char *), compare);
}

int compareFrequency(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;
    return wordB->count - wordA->count;
}

void printTopWords(WordFrequency *words, int numWords, int topN) {
    printf("Top %d most frequent words:\n", topN);
    for (int i = 0; i < topN && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char *words[MAX_WORDS];
    int numWords = 0;
    int minLength = MIN_WORD_LENGTH;
    int maxLength = MAX_WORD_LENGTH;
    int topN = 10;

    printf("Enter the number of words to generate (between %d and %d):\n", MIN_WORD_LENGTH, MAX_WORD_LENGTH);
    scanf("%d", &numWords);

    printf("Enter the minimum word length (between %d and %d):\n", MIN_WORD_LENGTH, MAX_WORD_LENGTH);
    scanf("%d", &minLength);

    printf("Enter the maximum word length (between %d and %d):\n", MIN_WORD_LENGTH, MAX_WORD_LENGTH);
    scanf("%d", &maxLength);

    generateRandomWords(words, numWords, minLength, maxLength);

    printf("Sorting words by frequency...\n");
    sortWords(words, numWords, compareFrequency);

    printf("Top %d most frequent words:\n", topN);
    printTopWords(words, numWords, topN);

    return 0;
}