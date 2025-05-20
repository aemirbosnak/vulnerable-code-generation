//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    char input[MAX_WORD_LENGTH];
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    int numWords = 0;
    WordFrequency words[MAX_WORDS];
    memset(words, 0, sizeof(WordFrequency) * MAX_WORDS);

    while (fscanf(file, "%s", input)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words.\n");
            fclose(file);
            return 1;
        }

        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(input, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == numWords) {
            strcpy(words[numWords].word, input);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}