//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char line[100];
    char word[MAX_WORD_LENGTH];
    WordFrequency *wordFrequencies = malloc(sizeof(WordFrequency) * MAX_WORDS);
    int numWords = 0;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",.?!;:");

        while (token!= NULL) {
            int i = 0;
            while (isalpha(token[i]) && i < MAX_WORD_LENGTH - 1) {
                word[i] = tolower(token[i]);
                i++;
            }
            word[i] = '\0';

            int found = 0;
            for (int j = 0; j < numWords; j++) {
                if (strcmp(wordFrequencies[j].word, word) == 0) {
                    wordFrequencies[j].count++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                if (numWords >= MAX_WORDS) {
                    printf("Error: too many unique words.\n");
                    exit(1);
                }
                strcpy(wordFrequencies[numWords].word, word);
                wordFrequencies[numWords].count = 1;
                numWords++;
            }

            token = strtok(NULL, ",.?!;:");
        }
    }

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    free(wordFrequencies);
    fclose(file);

    return 0;
}