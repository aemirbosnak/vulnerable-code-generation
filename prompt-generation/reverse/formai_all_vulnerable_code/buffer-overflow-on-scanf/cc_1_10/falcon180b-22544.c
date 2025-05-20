//Falcon-180B DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE* file, char* buffer, int maxSize) {
    int ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (i >= maxSize - 1) {
            printf("Error: Buffer overflow.\n");
            exit(1);
        }
        buffer[i++] = ch;
    }
    buffer[i] = '\0';
}

void processWords(char* buffer, WordCount* wordCounts, int numWords) {
    char* word = strtok(buffer, ",.?!;:\"'");
    while (word!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many words.\n");
                exit(1);
            }
            strcpy(wordCounts[numWords].word, word);
            wordCounts[numWords].count = 1;
            numWords++;
        }
        word = strtok(NULL, ",.?!;:\"'");
    }
}

void printWordCounts(WordCount* wordCounts, int numWords) {
    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE* file;
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    char buffer[MAX_WORD_LENGTH * 100];
    readFile(file, buffer, sizeof(buffer));
    fclose(file);
    int numWords = 0;
    WordCount wordCounts[MAX_WORDS];
    processWords(buffer, wordCounts, numWords);
    printWordCounts(wordCounts, numWords);
    return 0;
}