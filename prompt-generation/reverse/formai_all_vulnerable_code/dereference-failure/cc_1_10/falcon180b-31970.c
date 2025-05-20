//Falcon-180B DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(FILE *file, char *text) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            text[i++] = tolower(ch);
        }
    }
    text[i] = '\0';
}

int compareWords(const void *a, const void *b) {
    WordFrequency *w1 = (WordFrequency *)a;
    WordFrequency *w2 = (WordFrequency *)b;
    return strcmp(w1->word, w2->word);
}

void countWords(char *text, WordFrequency *wordFrequencies, int numWords) {
    char *word = strtok(text, ",.?!;:");
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
                printf("Maximum number of words reached.\n");
                return;
            }
            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].count = 1;
            numWords++;
        }
        word = strtok(NULL, ",.?!;:");
    }
}

void printWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main() {
    FILE *file;
    char text[MAX_WORD_LENGTH * 1000];
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    readFile(file, text);
    countWords(text, wordFrequencies, numWords);

    printWordFrequencies(wordFrequencies, numWords);

    return 0;
}