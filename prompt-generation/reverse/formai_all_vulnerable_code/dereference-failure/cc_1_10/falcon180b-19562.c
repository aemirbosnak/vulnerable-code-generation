//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int getWordFrequency(char *text, WordFrequency *wordFrequencies, int numWords) {
    char *word = strtok(text, ",.?!;:\"'");
    while (word!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, wordFrequencies[i].word) == 0) {
                wordFrequencies[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Maximum number of words (%d) exceeded.\n", MAX_WORDS);
                return -1;
            }
            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].count = 1;
            numWords++;
        }
        word = strtok(NULL, ",.?!;:\"'");
    }
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
    return 0;
}

void printWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main() {
    FILE *file;
    char *text = NULL;
    size_t textSize = 0;
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    textSize = ftell(file);
    rewind(file);

    text = malloc(textSize + 1);
    if (text == NULL) {
        printf("Error: Unable to allocate memory.\n");
        fclose(file);
        return -1;
    }

    fread(text, 1, textSize, file);
    fclose(file);

    getWordFrequency(text, wordFrequencies, numWords);
    printWordFrequencies(wordFrequencies, numWords);

    free(text);
    return 0;
}