//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORD_COUNT 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readFile(char *filename, char *buffer) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    buffer = malloc(fileSize + 1);
    if (buffer == NULL) {
        printf("Memory error.\n");
        exit(1);
    }

    fread(buffer, fileSize, 1, fp);
    fclose(fp);

    buffer[fileSize] = '\0';
}

void tokenize(char *buffer, WordCount *wordCounts) {
    char *token = strtok(buffer, ",.?!;:\"'");
    while (token!= NULL) {
        if (strlen(token) > 0) {
            int i;
            for (i = 0; i < MAX_WORD_COUNT; i++) {
                if (wordCounts[i].count == 0) {
                    strcpy(wordCounts[i].word, token);
                    wordCounts[i].count = 1;
                    break;
                }
            }
        }
        token = strtok(NULL, ",.?!;:\"'");
    }
}

void printWordCounts(WordCount *wordCounts) {
    printf("Word\tCount\n");
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char filename[100];
    strcpy(filename, argv[1]);

    char buffer[1000000];
    readFile(filename, buffer);

    WordCount wordCounts[MAX_WORD_COUNT];
    memset(wordCounts, 0, sizeof(wordCounts));

    tokenize(buffer, wordCounts);

    printWordCounts(wordCounts);

    return 0;
}