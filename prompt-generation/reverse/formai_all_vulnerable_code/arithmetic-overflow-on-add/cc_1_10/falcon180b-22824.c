//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(char* filename, WordFrequency* wordFrequencies) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }

        WordFrequency* currentWord = NULL;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, wordFrequencies[i].word) == 0) {
                currentWord = &wordFrequencies[i];
                break;
            }
        }

        if (currentWord == NULL) {
            if (wordFrequencies[MAX_WORDS - 1].word[0] == '\0') {
                strcpy(wordFrequencies[MAX_WORDS - 1].word, word);
                currentWord = &wordFrequencies[MAX_WORDS - 1];
            } else {
                printf("Error: maximum number of words exceeded\n");
                exit(1);
            }
        }

        currentWord->count++;
    }

    fclose(file);
}

void printWordFrequencies(WordFrequency* wordFrequencies) {
    printf("Word\t\tFrequency\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].word[0]!= '\0') {
            printf("%s\t\t%d\n", wordFrequencies[i].word, wordFrequencies[i].count);
        }
    }

    printf("-----------------------------------------\n");
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Error: incorrect number of arguments\n");
        exit(1);
    }

    WordFrequency wordFrequencies[MAX_WORDS];
    readFile(argv[1], wordFrequencies);
    printWordFrequencies(wordFrequencies);

    return 0;
}