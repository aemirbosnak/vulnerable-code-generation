//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_WORDS 10000
#define WORD_LENGTH 50
struct Word {
    char word[WORD_LENGTH];
    int count;
};
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}
int main(int argc, char *argv[]) {
    bool isFirstWord = true;
    struct Word wordList[MAX_WORDS];
    int numWords = 0;
    char currentWord[WORD_LENGTH];
    if (argc < 2) {
        printf("Please provide a file path as an argument.\n");
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Could not open file.\n");
        return 1;
    }
    while (fscanf(fp, "%s", currentWord) != EOF) {
        toLowerCase(currentWord);
        bool wordExists = false;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(wordList[i].word, currentWord) == 0) {
                wordList[i].count++;
                wordExists = true;
                break;
            }
        }
        if (!wordExists) {
            strcpy(wordList[numWords].word, currentWord);
            wordList[numWords].count = 1;
            numWords++;
        }
        if (isFirstWord) {
            isFirstWord = false;
            printf("\n%-20s %s\n", "Word", "Frequency");
        }
        printf("%-20s %d\n", currentWord, wordList[numWords - 1].count);
    }
    fclose(fp);
    return 0;
}