//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(FILE *file, char *text) {
    int c;
    while ((c = fgetc(file))!= EOF) {
        if (isalpha(c)) {
            strcat(text, tolower(c));
        } else {
            strcat(text, " ");
        }
    }
}

void countWords(char *text, WordFrequency *wordFreq, int numWords) {
    char *word = strtok(text, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, wordFreq[i].word) == 0) {
                wordFreq[i].count++;
                break;
            }
        }
        if (i == numWords) {
            strcpy(wordFreq[numWords - 1].word, word);
            wordFreq[numWords - 1].count = 1;
            numWords++;
        }
        word = strtok(NULL, " ");
    }
}

void printWordFrequencies(WordFrequency *wordFreq, int numWords) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordFreq[i].word, wordFreq[i].count);
    }
}

int main() {
    FILE *file;
    char text[MAX_WORD_LENGTH * 1000];
    WordFrequency wordFreq[MAX_WORDS];
    int numWords = 0;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    readFile(file, text);
    fclose(file);

    countWords(text, wordFreq, numWords);
    printWordFrequencies(wordFreq, numWords);

    return 0;
}