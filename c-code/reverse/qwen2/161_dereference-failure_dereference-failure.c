#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    return ((WordCount *)b)->count - ((WordCount *)a)->count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    WordCount wordCounts[MAX_WORDS] = {0};
    char word[MAX_WORD_LENGTH];

    while (fscanf(inputFile, "%s", word) == 1) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }
        if (!found && strcmp(wordCounts[MAX_WORDS-1].word, "") != 0) {
            strcpy(wordCounts[MAX_WORDS-1].word, word);
            wordCounts[MAX_WORDS-1].count = 1;
        }
    }

    qsort(wordCounts, MAX_WORDS, sizeof(WordCount), compare);

    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(wordCounts[i].word, "") != 0) {
            fprintf(outputFile, "%s %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
