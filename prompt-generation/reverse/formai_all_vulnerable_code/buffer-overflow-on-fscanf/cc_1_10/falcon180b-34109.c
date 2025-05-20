//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(FILE *file, WordFrequency *wordFrequencies) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordFrequencies[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            strcpy(wordFrequencies[i].word, word);
            wordFrequencies[i].count = 1;
        }
    }
}

void printWordFrequencies(WordFrequency *wordFrequencies) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].count > 0) {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency wordFrequencies[MAX_WORDS];
    memset(wordFrequencies, 0, sizeof(wordFrequencies));

    readFile(file, wordFrequencies);

    fclose(file);

    printWordFrequencies(wordFrequencies);

    return 0;
}