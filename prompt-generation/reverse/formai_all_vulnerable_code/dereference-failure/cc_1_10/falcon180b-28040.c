//Falcon-180B DATASET v1.0 Category: Text processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int main(int argc, char *argv[]) {
    int numWords = 0;
    char word[MAX_WORD_LENGTH];
    char line[MAX_LINE_LENGTH];
    WordCount *wordCounts = NULL;
    FILE *inputFile = NULL;

    // Open input file
    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    // Read in words and count their occurrences
    while (fscanf(inputFile, "%s", word)!= EOF) {
        numWords++;
        if (wordCounts == NULL) {
            wordCounts = malloc(numWords * sizeof(WordCount));
        } else {
            wordCounts = realloc(wordCounts, (numWords + 1) * sizeof(WordCount));
        }
        wordCounts[numWords - 1].word = strdup(word);
        wordCounts[numWords - 1].count = 1;
    }

    // Sort words alphabetically
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    // Print word counts
    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }

    // Close input file
    fclose(inputFile);

    // Free memory
    for (int i = 0; i < numWords; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);

    return 0;
}