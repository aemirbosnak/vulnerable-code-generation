//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wordA = (WordCount *) a;
    WordCount *wordB = (WordCount *) b;

    if (wordA->count > wordB->count)
        return -1;
    else if (wordA->count < wordB->count)
        return 1;
    else
        return 0;
}

void readWords(FILE *file, WordCount *wordCounts) {
    char word[MAX_WORD_LENGTH] = {0};
    int wordLength = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            if (isalpha(word[i])) {
                word[wordLength++] = tolower(word[i]);
            }
        }
        word[wordLength] = '\0';

        int wordIndex = -1;
        for (int i = 0; i < MAX_WORD_COUNT; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordIndex = i;
                break;
            }
        }

        if (wordIndex == -1) {
            if (wordCounts[MAX_WORD_COUNT - 1].word[0] == '\0') {
                strcpy(wordCounts[MAX_WORD_COUNT - 1].word, word);
                wordCounts[MAX_WORD_COUNT - 1].count++;
            }
        }
        else {
            wordCounts[wordIndex].count++;
        }
    }
}

void writeSortedWords(FILE *file, WordCount *wordCounts) {
    qsort(wordCounts, MAX_WORD_COUNT, sizeof(WordCount), compare);

    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        if (wordCounts[i].word[0]!= '\0') {
            fprintf(file, "%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    WordCount wordCounts[MAX_WORD_COUNT];
    memset(wordCounts, 0, sizeof(wordCounts));

    readWords(inputFile, wordCounts);

    writeSortedWords(outputFile, wordCounts);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}