//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main(int argc, char *argv[]) {
    FILE *inputFile;
    FILE *outputFile;
    char line[MAX_WORD_LENGTH];
    int numWords = 0;
    Word words[MAX_WORDS];

    if (argc!= 3) {
        fprintf(stderr, "Error: Usage %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: Could not open %s\n", argv[1]);
        exit(1);
    }

    outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Could not open %s\n", argv[2]);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (numWords == MAX_WORDS) {
                fprintf(stderr, "Error: Too many words\n");
                exit(1);
            }
            strcpy(words[numWords].word, token);
            words[numWords].count = 1;
            numWords++;
            token = strtok(NULL, ",.?!;:");
        }
    }

    fprintf(outputFile, "Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\t%d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}