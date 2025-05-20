//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_SIZE 50

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

void readFile(FILE *file, char *text) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            text[i++] = ch;
        } else {
            text[i] = '\0';
        }
    }
}

void tokenize(char *text, char **tokens) {
    int i = 0;
    char *token;

    while ((token = strtok(text, " \n\t\r"))!= NULL) {
        tokens[i++] = token;
    }
}

void countWords(char **tokens, int numTokens, WordCount *wordCounts) {
    int i;

    for (i = 0; i < numTokens; i++) {
        int j;
        for (j = 0; j < MAX_WORD_SIZE; j++) {
            if (isalnum(tokens[i][j])) {
                strncpy(wordCounts[i].word, tokens[i], j);
                wordCounts[i].word[j] = '\0';
                wordCounts[i].count++;
            } else {
                break;
            }
        }
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
    char text[MAX_WORD_SIZE * MAX_WORDS];
    char *tokens[MAX_WORDS];
    WordCount wordCounts[MAX_WORDS];
    int numTokens, i;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 2;
    }

    readFile(file, text);
    fclose(file);

    tokenize(text, tokens);
    countWords(tokens, numTokens, wordCounts);
    printWordCounts(wordCounts, numTokens);

    return 0;
}