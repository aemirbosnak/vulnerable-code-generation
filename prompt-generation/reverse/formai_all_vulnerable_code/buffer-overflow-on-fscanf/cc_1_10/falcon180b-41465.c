//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *w1 = a;
    const WordFrequency *w2 = b;

    if (w1->frequency > w2->frequency) {
        return -1;
    } else if (w1->frequency < w2->frequency) {
        return 1;
    } else {
        return 0;
    }
}

void readWordsFromFile(FILE *file, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }
}

void printTopWords(WordFrequency words[], int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords && i < MAX_WORDS; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE *file;
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    readWordsFromFile(file, words);
    fclose(file);

    printf("Enter the number of top words to display (1-%d): ", numWords);
    scanf("%d", &numWords);

    if (numWords > MAX_WORDS || numWords <= 0) {
        printf("Error: Invalid number of top words.\n");
        exit(1);
    }

    printTopWords(words, numWords);

    return 0;
}