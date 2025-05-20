//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

void readFile(FILE *file, char *buffer) {
    int ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (i >= strlen(buffer)) {
            buffer = realloc(buffer, strlen(buffer) + 100);
        }
        buffer[i++] = ch;
        buffer[i] = '\0';
    }
}

int isWord(char *word) {
    int i;

    for (i = 0; i < strlen(word); i++) {
        if (!isalnum(word[i])) {
            return 0;
        }
    }

    return 1;
}

void countWords(char *buffer, WordCount *wordCounts, int numWords) {
    char *token;
    int i;

    token = strtok(buffer, ",.?!;:");

    while (token!= NULL) {
        if (isWord(token)) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(token, wordCounts[i].word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
        }

        token = strtok(NULL, ",.?!;:");
    }
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *buffer = NULL;
    WordCount wordCounts[MAX_WORDS];
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

    readFile(file, buffer);
    fclose(file);

    countWords(buffer, wordCounts, numWords);
    printWordCounts(wordCounts, numWords);

    free(buffer);

    return 0;
}