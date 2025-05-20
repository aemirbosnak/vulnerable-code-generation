//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE* file, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
    }
}

void writeWords(FILE* file, WordCount words[], int count) {
    for (int i = 0; i < count; i++) {
        if (words[i].count > 0) {
            fprintf(file, "%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    WordCount words[MAX_WORDS];
    int wordCount = 0;

    readWords(inputFile, words);
    writeWords(outputFile, words, wordCount);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}