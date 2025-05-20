//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000
#define MAX_LINE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

bool isAlphabet(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void readFile(FILE* fp, char* line, int maxLineLength) {
    char c = fgetc(fp);
    int i = 0;
    while (c!= EOF && i < maxLineLength - 1) {
        if (isAlphabet(c)) {
            line[i] = tolower(c);
            i++;
        }
        c = fgetc(fp);
    }
    line[i] = '\0';
}

void processLine(char* line, WordCount* words, int numWords) {
    char* token = strtok(line, " ");
    while (token!= NULL && numWords < MAX_NUM_WORDS) {
        int i = 0;
        while (token[i]!= '\0' && i < MAX_WORD_LENGTH - 1) {
            if (isAlphabet(token[i])) {
                words[numWords].word[i] = token[i];
                i++;
            } else {
                break;
            }
        }
        words[numWords].word[i] = '\0';
        words[numWords].count = 1;
        numWords++;
        token = strtok(NULL, " ");
    }
}

void printWordCounts(WordCount* words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char fileName[MAX_LINE_LENGTH];
    printf("Enter the file name: ");
    scanf("%s", fileName);

    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    WordCount words[MAX_NUM_WORDS];
    int numWords = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        readFile(fp, line, MAX_LINE_LENGTH);
        processLine(line, words, numWords);
    }

    fclose(fp);
    printWordCounts(words, numWords);

    return 0;
}