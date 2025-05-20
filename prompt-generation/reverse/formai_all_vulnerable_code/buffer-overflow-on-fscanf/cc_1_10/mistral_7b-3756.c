//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define BUFFER_SIZE 1024

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int next;
} Word;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isWordDelimiter(char c) {
    return c == ' ' || c == '\n' || c == '\t' || c == ',' || c == '.' || c == ':' || c == ';' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
}

int readWord(FILE *fp, Word *words, int *numWords) {
    char word[MAX_WORD_LENGTH];
    int len = 0;

    while (isspace((unsigned char)fgetc(fp))) {}

    if (feof(fp)) {
        return 0;
    }

    while (!isspace((unsigned char)fgetc(fp)) && fscanf(fp, "%s", word) != EOF) {
        toLowerCase(word);
        strcpy(words[*numWords].word, word);
        (*numWords)++;

        if ((*numWords) % 100 == 0) {
            words = realloc(words, sizeof(Word) * (*numWords) * 2);
        }

        len += strlen(word) + 1;
    }

    words = realloc(words, sizeof(Word) * (*numWords) + len);
    strcpy(words[*numWords].word + strlen(words[*numWords].word), "\0");

    return 1;
}

void processFile(FILE *inputFile, FILE *outputFile, const char *wordToRemove) {
    Word *words = NULL;
    int numWords = 0;
    int prevIndex = -1;

    if (!readWord(inputFile, words, &numWords)) {
        return;
    }

    for (int i = 0; i < numWords; i++) {
        int index = i;

        if (i > 0 && strcmp(words[i].word, wordToRemove) == 0 && i != prevIndex) {
            for (int j = i; j < numWords; j++) {
                words[j].next = words[j+1].next;
            }

            numWords--;
            i--;

            continue;
        }

        if (i > 0) {
            words[i].next = words[i-1].next;
        }

        fprintf(outputFile, "%s%s", words[i].word, words[i].next ? " " : "");
        prevIndex = i;
    }

    free(words);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s inputFile outputFile wordToRemove\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    if (!inputFile || !outputFile) {
        perror("Error opening file");
        return 1;
    }

    processFile(inputFile, outputFile, argv[3]);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}