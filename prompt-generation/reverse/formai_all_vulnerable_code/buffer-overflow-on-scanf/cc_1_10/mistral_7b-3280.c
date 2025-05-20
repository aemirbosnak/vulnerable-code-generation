//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

void processWord(Word *words, int *numWords, char *line) {
    int i;

    for (i = 0; i < *numWords && strcmp(words[i].word, line); i++);

    if (i < *numWords) {
        words[i].count++;
    } else {
        if (*numWords == MAX_WORDS) {
            Word *newWords = realloc(words, sizeof(Word) * (MAX_WORDS + 100));
            if (!newWords) {
                printf("Error: Out of memory\n");
                exit(EXIT_FAILURE);
            }
            words = newWords;
        }

        strcpy(words[*numWords].word, line);
        strcpy(words[*numWords].word + strlen(line), "\0");
        words[*numWords].count = 1;
        (*numWords)++;
    }
}

int main() {
    FILE *file;
    char filename[100], line[1024];
    int numWords = 0;
    Word words[MAX_WORDS];

    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        toLower(line);
        char *token = strtok(line, " \t\n");
        while (token) {
            processWord(words, &numWords, token);
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(file);

    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}