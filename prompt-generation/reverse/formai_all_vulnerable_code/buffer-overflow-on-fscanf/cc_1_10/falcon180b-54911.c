//Falcon-180B DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b)
{
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

int main()
{
    char input[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    char *token;
    FILE *inputFile;
    int i;

    printf("Enter the name of the input file: ");
    scanf("%s", input);

    inputFile = fopen(input, "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords == MAX_WORDS) {
            printf("Error: maximum number of words (%d) exceeded.\n", MAX_WORDS);
            exit(1);
        }

        strcpy(wordCounts[numWords].word, word);
        wordCounts[numWords].count = 1;
        numWords++;
    }

    fclose(inputFile);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}