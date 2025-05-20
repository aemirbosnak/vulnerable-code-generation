//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE* file, char* buffer, int* bufferSize) {
    int ch;
    while ((ch = fgetc(file))!= EOF) {
        if (*bufferSize == 0) {
            *bufferSize = 1024;
            buffer = realloc(buffer, *bufferSize);
        }
        buffer[*bufferSize - 1] = ch;
        (*bufferSize)--;
    }
    buffer[*bufferSize] = '\0';
}

void tokenize(char* buffer, WordCount* wordCounts, int numWords) {
    char* token = strtok(buffer, ",.?!;:\"'");
    int i = 0;
    while (token!= NULL && i < numWords) {
        strcpy(wordCounts[i].word, token);
        wordCounts[i].count = 1;
        i++;
        token = strtok(NULL, ",.?!;:\"'");
    }
}

void countWords(char* filename, WordCount* wordCounts, int numWords) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char* buffer = malloc(1024);
    int bufferSize = 0;

    readFile(file, buffer, &bufferSize);
    fclose(file);

    tokenize(buffer, wordCounts, numWords);

    for (int i = 0; i < numWords; i++) {
        char* word = wordCounts[i].word;
        int count = wordCounts[i].count;

        printf("%s: %d\n", word, count);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    countWords(argv[1], wordCounts, MAX_WORDS);

    return 0;
}