//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LENGTH];
    int wordLength = 0;
    int i;
    while ((i = fscanf(file, "%s", word))!= EOF) {
        if (i == 0) {
            printf("Error: Invalid word found in file\n");
            fclose(file);
            return 1;
        }

        if (wordLength >= MAX_WORD_LENGTH) {
            printf("Error: Word is too long\n");
            fclose(file);
            return 1;
        }

        strcpy(words[numWords].word, word);
        words[numWords].frequency = 1;
        numWords++;

        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words in file\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}