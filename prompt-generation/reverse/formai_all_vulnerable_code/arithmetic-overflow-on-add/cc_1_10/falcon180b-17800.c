//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(FILE *file, WordFrequency *wordFrequencies) {
    char ch;
    char word[MAX_WORD_LENGTH] = {0};
    int wordLength = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[wordLength++] = tolower(ch);
            if (wordLength == MAX_WORD_LENGTH) {
                word[MAX_WORD_LENGTH - 1] = '\0';
                break;
            }
        } else {
            if (wordLength > 0) {
                word[wordLength] = '\0';
                wordFrequencies[wordLength - 1].count++;
                wordLength = 0;
            }
        }
    }
}

void sortWordFrequencies(WordFrequency *wordFrequencies) {
    int i, j;
    WordFrequency temp;

    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (wordFrequencies[i].count < wordFrequencies[j].count) {
                temp = wordFrequencies[i];
                wordFrequencies[i] = wordFrequencies[j];
                wordFrequencies[j] = temp;
            }
        }
    }
}

void printTopWords(WordFrequency *wordFrequencies, int numWords) {
    int i;

    for (i = 0; i < numWords && i < MAX_WORDS; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    readFile(file, wordFrequencies);

    fclose(file);

    sortWordFrequencies(wordFrequencies);

    printTopWords(wordFrequencies, numWords);

    return 0;
}