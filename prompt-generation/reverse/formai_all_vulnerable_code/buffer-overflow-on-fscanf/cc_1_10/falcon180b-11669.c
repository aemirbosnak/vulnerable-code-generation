//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE* inputFile, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("Warning: Ignoring word '%s'\n", word);
        }
    }
}

void writeWords(FILE* outputFile, WordCount words[]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            fprintf(outputFile, "%s %d\n", words[i].word, words[i].count);
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
        printf("Error: Could not open input file '%s'\n", argv[1]);
        return 2;
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file '%s'\n", argv[2]);
        fclose(inputFile);
        return 3;
    }

    WordCount words[MAX_WORDS];
    memset(words, 0, sizeof(WordCount) * MAX_WORDS);

    readWords(inputFile, words);

    writeWords(outputFile, words);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}