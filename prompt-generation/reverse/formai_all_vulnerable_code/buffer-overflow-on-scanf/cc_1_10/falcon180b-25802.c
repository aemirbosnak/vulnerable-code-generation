//Falcon-180B DATASET v1.0 Category: Educational ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    char input[MAX_WORDS][MAX_WORD_LENGTH];
    int numWords = 0;
    int totalWords = 0;
    int i;

    printf("Enter words separated by spaces:\n");
    while (scanf(" %s", input[numWords])!= EOF) {
        numWords++;
        totalWords++;
    }

    printf("\nWords entered: %d\n", numWords);

    WordCount wordCounts[MAX_WORDS];
    for (i = 0; i < numWords; i++) {
        strcpy(wordCounts[i].word, input[i]);
        wordCounts[i].count = 1;
    }

    for (i = 1; i < numWords; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (strcmp(wordCounts[i].word, wordCounts[j].word) == 0) {
                wordCounts[i].count += wordCounts[j].count;
                strcpy(wordCounts[j].word, "");
                wordCounts[j].count = 0;
            }
        }
    }

    printf("\nWords and their counts:\n");
    for (i = 0; i < numWords; i++) {
        if (strlen(wordCounts[i].word) > 0) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }

    return 0;
}