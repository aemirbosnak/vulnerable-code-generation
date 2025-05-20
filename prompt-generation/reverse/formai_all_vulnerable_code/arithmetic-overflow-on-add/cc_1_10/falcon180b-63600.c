//Falcon-180B DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *inputFile;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int totalWords = 0;
    WordCount wordCounts[MAX_WORDS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        totalWords += countWords(line, wordCounts);
    }

    fclose(inputFile);

    qsort(wordCounts, totalWords, sizeof(WordCount), compareWords);

    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < totalWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}

int countWords(char *line, WordCount *wordCounts) {
    char *wordStart = line;
    char *wordEnd;

    while ((wordEnd = strpbrk(wordStart, ",.?!;:\"'"))!= NULL) {
        *wordEnd = '\0';
        strcpy(wordCounts->word, wordStart);
        wordCounts->count++;
        wordStart = wordEnd + 1;
    }

    strcpy(wordCounts->word, wordStart);
    wordCounts->count++;

    return 1;
}