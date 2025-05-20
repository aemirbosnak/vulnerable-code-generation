//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} WordCount;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

int isAlphabetic(char c) {
    return (isalpha(c) || isdigit(c) || c == '\'' || c == '_');
}

void addWord(WordCount *wordList, char *word) {
    for (int i = 0; i < 10000; i++) {
        if (!strcmp(wordList[i].word, word)) {
            wordList[i].count++;
            return;
        }
    }

    strcpy(wordList[9999].word, word);
    wordList[9999].count = 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    WordCount wordList[MAX_WORDS];
    char word[WORD_LENGTH];
    int currentWordIndex = 0;

    while (fscanf(file, "%s%*c", word) != EOF) {
        toLowerCase(word);

        if (isDelimiter(word[0])) {
            continue;
        }

        addWord(wordList, word);
    }

    fclose(file);

    printf("Word count:\n");
    for (int i = 0; i < 10000; i++) {
        if (wordList[i].count > 0) {
            printf("%s: %d\n", wordList[i].word, wordList[i].count);
        }
    }

    return 0;
}