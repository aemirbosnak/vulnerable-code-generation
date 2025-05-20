//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define WORD_LEN 50
typedef struct Word {
    char word[WORD_LEN];
    int count;
} Word;

void toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

bool isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

void processWord(Word words[], int *numWords, char *line) {
    int i;
    for (i = 0; i < *numWords; i++) {
        if (strcmp(words[i].word, line) == 0) {
            words[i].count++;
            return;
        }
    }

    if (*numWords >= MAX_WORDS) {
        printf("Maximum number of words reached. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    strcpy(words[*numWords].word, line);
    words[*numWords].count = 1;
    (*numWords)++;
}

int main() {
    FILE *fp;
    char filename[100], line[1024];
    int numWords = 0;
    Word words[MAX_WORDS];

    printf("Enter file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        toLowerCase(line);
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            processWord(words, &numWords, token);
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(fp);

    printf("\nWord Frequency Table:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s : %d\n", words[i].word, words[i].count);
    }

    return EXIT_SUCCESS;
}