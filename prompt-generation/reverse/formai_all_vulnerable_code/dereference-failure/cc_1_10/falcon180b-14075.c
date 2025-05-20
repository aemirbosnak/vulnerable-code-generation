//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;
    return strcmp(wordA->word, wordB->word);
}

void processWord(char *word) {
    int i, j;
    char *p;
    for (i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            word[i] = '\0';
        }
    }
    for (j = 0; j < strlen(word); j++) {
        word[j] = tolower(word[j]);
    }
    p = strrchr(word, '.');
    if (p!= NULL) {
        *p = '\0';
    }
}

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char line[MAX_WORD_SIZE];
    WordFrequency *wordFrequencies;
    int numWords;
    int i;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    wordFrequencies = malloc(sizeof(WordFrequency) * 100000);
    numWords = 0;

    while (fgets(line, MAX_WORD_SIZE, inputFile)!= NULL) {
        processWord(line);
        if (strlen(line) > 0) {
            wordFrequencies[numWords].word = strdup(line);
            wordFrequencies[numWords].frequency = 1;
            numWords++;
        }
    }

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    fclose(inputFile);
    free(wordFrequencies);

    return 0;
}