//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(FILE* inputFile, WordFrequency words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }
}

void translateWords(WordFrequency words[MAX_WORDS], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s -> ", words[i].word);

        for (int j = 0; j < strlen(words[i].word); j++) {
            if (isalpha(words[i].word[j])) {
                printf("%c", toupper(words[i].word[j]));
            } else {
                printf("%c", words[i].word[j]);
            }
        }

        printf(" (%d)\n", words[i].frequency);
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

    WordFrequency words[MAX_WORDS];
    readWords(inputFile, words);

    int numWords = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            numWords++;
        }
    }

    translateWords(words, numWords);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}