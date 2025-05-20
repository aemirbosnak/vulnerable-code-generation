//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

void countWords(FILE *file, WordCount *wordCounts, int numWordCounts) {
    char word[MAX_WORD_LENGTH];
    char c;
    int wordIndex = 0;
    int inWord = 0;

    while ((c = fgetc(file))!= EOF) {
        if (isalpha(c)) {
            inWord = 1;
            word[0] = c;
            wordIndex = 1;
        } else if (inWord) {
            inWord = 0;
            word[wordIndex] = '\0';
            if (wordIndex > 0) {
                for (int i = 0; i < numWordCounts; i++) {
                    if (strcmp(word, wordCounts[i].word) == 0) {
                        wordCounts[i].count++;
                        break;
                    }
                }
            }
        }
    }
}

void printWordCounts(WordCount *wordCounts, int numWordCounts) {
    qsort(wordCounts, numWordCounts, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWordCounts; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordCount wordCounts[100];
    int numWordCounts = 0;

    countWords(file, wordCounts, 100);
    printWordCounts(wordCounts, numWordCounts);

    fclose(file);
    return 0;
}