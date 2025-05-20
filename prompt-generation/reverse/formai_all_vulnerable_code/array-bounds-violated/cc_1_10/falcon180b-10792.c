//Falcon-180B DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
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
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *inputFile;
    char inputText[100000];
    int inputTextLength;
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    WordCount wordFrequency[MAX_WORDS];

    inputFile = fopen("post-apocalyptic.txt", "r");

    if (inputFile == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fseek(inputFile, 0, SEEK_END);
    inputTextLength = ftell(inputFile);
    rewind(inputFile);

    fread(inputText, inputTextLength, 1, inputFile);
    fclose(inputFile);

    inputText[inputTextLength - 1] = '\0'; // Add null terminator to end of text

    char *token;
    token = strtok(inputText, ",.?!;:\"'");

    while (token!= NULL) {
        if (wordCount >= MAX_WORDS) {
            printf("Error: Too many unique words.\n");
            return 1;
        }

        strcpy(wordFrequency[wordCount].word, token);
        wordFrequency[wordCount].count = 1;
        wordCount++;

        token = strtok(NULL, ",.?!;:\"'");
    }

    qsort(wordFrequency, wordCount, sizeof(WordCount), compareWords);

    printf("Word\tFrequency\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\t%d\n", wordFrequency[i].word, wordFrequency[i].count);
    }

    return 0;
}