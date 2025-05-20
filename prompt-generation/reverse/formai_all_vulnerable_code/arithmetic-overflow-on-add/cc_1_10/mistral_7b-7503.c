//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

void toLower(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

int isSeparater(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

void addWord(Word *words, char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }

    strcpy(words[MAX_WORDS - 1].word, word);
    words[MAX_WORDS - 1].count = 1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please provide a file to read.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }

    Word words[MAX_WORDS];
    char word[WORD_LENGTH];
    int numWords = 0;

    while (fscanf(file, "%s%*c", word) != EOF) {
        toLower(word);
        addWord(words, word);
        numWords++;
    }

    fclose(file);

    printf("Word Frequency Counter:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s : %d\n", words[i].word, words[i].count);
    }

    return 0;
}