//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *inputFile;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int wordLength;
    int totalWords = 0;
    WordFrequency wordFrequencies[MAX_WORDS];

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        totalWords += countWords(line, wordFrequencies);
    }

    fclose(inputFile);

    qsort(wordFrequencies, totalWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    return 0;
}

int countWords(char *line, WordFrequency *wordFrequencies) {
    char *wordStart = line;
    char *wordEnd;
    int wordCount = 0;

    while ((wordEnd = strpbrk(wordStart, ",.?!;:\"'"))!= NULL) {
        wordEnd[0] = '\0';
        wordStart = wordEnd + 1;

        if (strlen(wordStart) > 0) {
            strcpy(wordFrequencies[wordCount].word, wordStart);
            wordFrequencies[wordCount].count++;
            wordCount++;
        }
    }

    return wordCount;
}