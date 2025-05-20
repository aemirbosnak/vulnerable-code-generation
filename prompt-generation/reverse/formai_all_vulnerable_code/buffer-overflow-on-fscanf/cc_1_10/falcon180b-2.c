//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *file, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
}

void spellCheck(FILE *file, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    int i, j;

    while (fscanf(file, "%s", word)!= EOF) {
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = tolower(word[i]);
            }
        }
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("Unknown word: %s\n", word);
        }
    }
}

void printWordCounts(WordCount words[]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    WordCount words[MAX_WORDS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    readWords(inputFile, words);
    fclose(inputFile);

    spellCheck(inputFile, words);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    printWordCounts(words);

    fclose(outputFile);

    return 0;
}