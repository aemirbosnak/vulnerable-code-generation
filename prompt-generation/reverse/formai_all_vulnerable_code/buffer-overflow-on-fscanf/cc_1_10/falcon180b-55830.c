//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *file, WordCount *wordCounts) {
    char word[MAX_WORD_LENGTH];
    int wordLength;
    while (fscanf(file, "%s", word)!= EOF) {
        wordLength = strlen(word);
        if (wordLength > 0 && isalpha(word[0])) {
            for (int i = 0; i < wordLength; i++) {
                word[i] = tolower(word[i]);
            }
            wordCounts[wordLength - 1].count++;
        }
    }
}

void printWordCounts(WordCount *wordCounts) {
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (wordCounts[i].count > 0) {
            printf("%d %s\n", wordCounts[i].count, wordCounts[i].word);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    WordCount wordCounts[MAX_WORD_LENGTH];
    memset(wordCounts, 0, sizeof(wordCounts));

    readWords(inputFile, wordCounts);

    printWordCounts(wordCounts);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}