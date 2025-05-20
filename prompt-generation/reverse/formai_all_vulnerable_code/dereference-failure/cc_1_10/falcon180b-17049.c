//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CHARS 1000
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void countWords(char *text, int textLen, WordCount *wordCounts, int maxWords) {
    char *word = NULL;
    int wordLen = 0;
    int i = 0;

    while (i < textLen) {
        while (isspace(text[i])) {
            i++;
        }
        word = &text[i];
        while (!isspace(text[i]) && i < textLen) {
            i++;
            wordLen++;
        }
        if (wordLen > 0) {
            if (i - 1 >= textLen) {
                break;
            }
            text[i - 1] = '\0';
            if (i < MAX_CHARS) {
                wordCounts[i].word = strdup(word);
            }
            wordCounts[i].count = 1;
            i += wordLen;
        }
    }
}

void sortWords(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
}

void printWords(WordCount *wordCounts, int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    char *text = NULL;
    int textLen = 0;
    WordCount *wordCounts = NULL;
    int numWords = 0;

    printf("Enter some text: ");
    fgets(text, MAX_CHARS, stdin);
    textLen = strlen(text);

    wordCounts = (WordCount *)malloc(MAX_WORDS * sizeof(WordCount));
    countWords(text, textLen, wordCounts, MAX_WORDS);
    sortWords(wordCounts, numWords);
    printWords(wordCounts, numWords);

    free(wordCounts);
    free(text);

    return 0;
}