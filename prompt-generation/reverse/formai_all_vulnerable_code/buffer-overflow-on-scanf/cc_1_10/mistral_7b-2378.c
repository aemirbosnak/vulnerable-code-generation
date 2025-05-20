//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int count;
} Word;

void toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

void addWord(Word *words, int *numWords, char *word) {
    for (int i = 0; i < *numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }

    if (*numWords == MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }

    strcpy(words[*numWords].word, word);
    words[*numWords].count = 1;
    (*numWords)++;
}

int main() {
    FILE *file;
    char filename[100];
    char line[1024];
    char word[WORD_LENGTH];
    Word words[MAX_WORDS];
    int numWords = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        toLowerCase(line);
        char *token = strtok(line, " \n\t");
        while (token != NULL) {
            addWord(words, &numWords, token);
            token = strtok(NULL, " \n\t");
        }
    }

    fclose(file);

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}