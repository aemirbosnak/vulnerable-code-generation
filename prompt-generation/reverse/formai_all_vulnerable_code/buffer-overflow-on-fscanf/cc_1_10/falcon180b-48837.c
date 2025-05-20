//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE *inputFile;
    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LEN];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words\n");
            exit(1);
        }

        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == numWords) {
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(inputFile);

    printf("Word Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}